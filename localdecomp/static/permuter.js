// Permuter panel: starts tools/permuter_engine.py jobs through the server and
// shows what they are doing while they run: score over time, every pass the
// random search tries, which passes found improvements, and each result as a
// diff against the editor's code that can be loaded back into the editor.
// Uses app.js's globals (currentFunc, currentTarget, cEditor, doBuild, ...).

const permBtn = document.getElementById("permuter-btn");
const permPanel = document.getElementById("perm-panel");
const permJobsIn = document.getElementById("perm-jobs");
const permMinsIn = document.getElementById("perm-mins");
const permAsmIn = document.getElementById("perm-asm");
const permStartBtn = document.getElementById("perm-start");
const permStopBtn = document.getElementById("perm-stop");
const permStateEl = document.getElementById("perm-state");
const permFuncEl = document.getElementById("perm-func");
const permStatsEl = document.getElementById("perm-stats");
const permChart = document.getElementById("perm-chart");
const permFeed = document.getElementById("perm-feed");
const permPasses = document.getElementById("perm-passes");
const permResults = document.getElementById("perm-results");
const permOutput = document.getElementById("perm-output");
const permNote = document.getElementById("perm-note");
const permSearchIn = document.getElementById("perm-search");

let permJob = null;        // job id being shown
let permSeq = 0;           // last event seq received
let permTries = [];        // [t, score] of sampled candidates, for the chart
let permFeedItems = [];
let permTimer = null;
let permInfo = null;
let permLast = null;       // last status snapshot
let permSelected = null;   // output n shown below the results

const PERM_RUNNING = new Set(["starting", "running"]);
const ASM_PASSES = new Set(["perm_reg_fence", "perm_sched_barrier", "fence", "barrier"]);
function permIsAsm(p) { return !!p && (ASM_PASSES.has(p) || /^(fence|barrier)_|\+(fence|barrier)_/.test(p)); }

function permFmtTime(s) {
  s = Math.max(0, Math.round(s));
  const m = Math.floor(s / 60), r = s % 60;
  return m ? `${m}m ${String(r).padStart(2, "0")}s` : `${r}s`;
}

function permShortPass(p) {
  return (p || "(base)").replace(/^perm_/, "");
}

async function permLoadInfo() {
  try {
    permInfo = await (await fetch("/api/permuter/info?" + tq())).json();
  } catch (e) {
    permInfo = { available: false, message: String(e) };
  }
  if (!permJobsIn.value) permJobsIn.value = Math.max(1, (permInfo.cpus || 2) - 1);
  if (!permInfo.available) {
    permNote.textContent = permInfo.message;
    permNote.className = "perm-note bad";
  } else if (!permInfo.asm_passes) {
    permNote.textContent = "This decomp-permuter has no fence/barrier passes (apply tools/decomp-permuter-asm-passes.patch to " + permInfo.path + ").";
    permNote.className = "perm-note";
    permAsmIn.checked = false;
    permAsmIn.disabled = true;
  } else {
    permNote.textContent = "decomp-permuter: " + permInfo.path;
    permNote.className = "perm-note";
    permAsmIn.disabled = false;
  }
  permUpdateStart();
}

function permCanStart() {
  const exhaustive = permSearchIn.value === "exhaustive";
  return !!currentFunc && (exhaustive || (permInfo && permInfo.available));
}

function permUpdateStart() {
  const running = permLast && PERM_RUNNING.has(permLast.status) && permLast.func === currentFunc;
  permStartBtn.disabled = running || !permCanStart();
  permAsmIn.disabled = permSearchIn.value === "exhaustive" || !(permInfo && permInfo.asm_passes);
}

permSearchIn.addEventListener("change", permUpdateStart);

function permReset() {
  permSeq = 0;
  permTries = [];
  permFeedItems = [];
  permLast = null;
  permSelected = null;
  permFeed.innerHTML = "";
  permResults.innerHTML = '<div class="empty-hint">Results appear here as the search finds them.</div>';
  permOutput.innerHTML = "";
  permPasses.innerHTML = "";
  permStatsEl.innerHTML = "";
  permDrawChart(null);
}

async function permOpen() {
  permPanel.hidden = false;
  document.body.classList.add("perm-open");
  permFuncEl.textContent = currentFunc ? currentFunc + " (" + currentTarget + ")" : "pick a function first";
  await permLoadInfo();
  // reattach to a job for this function that is still running (or the latest one)
  try {
    const { jobs } = await (await fetch("/api/permuter/jobs")).json();
    const mine = jobs.filter(j => j.func === currentFunc && j.target === currentTarget);
    const pick = mine.find(j => PERM_RUNNING.has(j.status)) || mine[mine.length - 1];
    if (pick && pick.id !== permJob) {
      permJob = pick.id;
      permReset();
    } else if (!pick) {
      permJob = null;
      permReset();
    }
  } catch (e) {}
  permPoll();
}

function permClose() {
  permPanel.hidden = true;
  document.body.classList.remove("perm-open");
}

permBtn.addEventListener("click", () => (permPanel.hidden ? permOpen() : permClose()));
document.getElementById("perm-close").addEventListener("click", permClose);

permStartBtn.addEventListener("click", async () => {
  if (!currentFunc) return;
  permStartBtn.disabled = true;
  permStateEl.textContent = "preparing...";
  permStateEl.className = "score-badge";
  try {
    const res = await (await fetch("/api/permuter/start", {
      method: "POST",
      headers: { "Content-Type": "application/json" },
      body: JSON.stringify({
        target: currentTarget, name: currentFunc, c: cEditor.value,
        jobs: Number(permJobsIn.value) || 1, seconds: (Number(permMinsIn.value) || 0) * 60,
        asm_passes: permAsmIn.checked, search: permSearchIn.value,
      }),
    })).json();
    if (!res.ok) {
      permStateEl.textContent = "failed";
      permStateEl.className = "score-badge bad";
      permOutput.innerHTML = '<pre class="perm-error">' + escapeHtml(res.message || "") + "</pre>";
      permStartBtn.disabled = false;
      return;
    }
    permJob = res.id;
    permReset();
    permPoll();
  } catch (e) {
    permStateEl.textContent = "request failed";
    permStartBtn.disabled = false;
  }
});

permStopBtn.addEventListener("click", async () => {
  if (!permJob) return;
  permStopBtn.disabled = true;
  await fetch("/api/permuter/stop", {
    method: "POST", headers: { "Content-Type": "application/json" },
    body: JSON.stringify({ id: permJob }),
  });
});

function permSchedule(ms) {
  clearTimeout(permTimer);
  permTimer = setTimeout(permPoll, ms);
}

async function permPoll() {
  if (!permJob) {
    permStateEl.textContent = "idle";
    permStopBtn.disabled = true;
    return;
  }
  let st;
  try {
    st = await (await fetch(`/api/permuter/status?id=${encodeURIComponent(permJob)}&since=${permSeq}`)).json();
  } catch (e) {
    permSchedule(2000);
    return;
  }
  if (st.error) {
    permStateEl.textContent = st.error;
    return;
  }
  permLast = st;
  for (const ev of st.events) {
    permSeq = Math.max(permSeq, ev.seq);
    if ((ev.kind === "try" || ev.kind === "found") && ev.score !== null && ev.score !== undefined) {
      permTries.push([ev.t, ev.score]);
    }
    permFeedItems.push(ev);
  }
  if (permTries.length > 3000) permTries = permTries.slice(-3000);
  if (permFeedItems.length > 200) permFeedItems = permFeedItems.slice(-200);
  permRender(st);
  const running = PERM_RUNNING.has(st.status);
  permStopBtn.disabled = !running;
  permUpdateStart();
  if (running && !permPanel.hidden) permSchedule(1000);
  else if (running) permSchedule(5000);
}

function permRender(st) {
  const running = PERM_RUNNING.has(st.status);
  permStateEl.textContent = (st.search === "exhaustive" ? "exhaustive: " : "") + st.status + (st.message ? ": " + st.message : "");
  permStateEl.className = "score-badge " + (st.status === "matched" ? "good" : st.status === "error" ? "bad" : running ? "live" : "");
  permFuncEl.textContent = st.func + " (" + st.target + ")";
  const best = st.best_score, base = st.base_score;
  const gain = base !== null && best !== null ? base - best : null;
  permStatsEl.innerHTML = [
    ["elapsed", permFmtTime(st.elapsed) + (st.seconds ? " / " + permFmtTime(st.seconds) : "")],
    ["workers", st.jobs],
    ["candidates", st.iterations.toLocaleString()],
    ["per second", st.rate],
    ["didn't compile", st.compile_errors.toLocaleString()],
    ["base", base === null ? "..." : base + " diffs"],
    ["best", best === null ? "..." : best + " diffs" + (gain ? ` (-${gain})` : "")],
  ].map(([k, v]) => `<div class="perm-stat"><span>${k}</span><b>${v}</b></div>`).join("")
    + `<div class="perm-flags" title="compile flags">${escapeHtml(st.flags.join(" "))}${st.asm_passes ? " &middot; fence/barrier passes on" : ""}</div>`;
  permDrawChart(st);
  permRenderFeed();
  permRenderPasses(st);
  permRenderResults(st);
  if (st.worker_errors && st.worker_errors.length && st.status === "error") {
    permOutput.innerHTML = '<pre class="perm-error">' + escapeHtml(st.worker_errors[st.worker_errors.length - 1]) + "</pre>";
  }
}

function permDrawChart(st) {
  const W = permChart.clientWidth || 360, H = permChart.clientHeight || 150;
  permChart.setAttribute("viewBox", `0 0 ${W} ${H}`);
  if (!st || st.base_score === null) {
    permChart.innerHTML = `<text x="${W / 2}" y="${H / 2}" class="perm-axis" text-anchor="middle">waiting for the base score...</text>`;
    return;
  }
  const L = 34, R = 8, T = 8, B = 20;
  const tMax = Math.max(st.elapsed, 10);
  const yMax = Math.max(1, Math.ceil(st.base_score * 1.6));
  const x = t => L + (W - L - R) * (t / tMax);
  const y = s => T + (H - T - B) * (1 - Math.min(s, yMax) / yMax);
  let g = "";
  // grid + y labels
  const step = Math.max(1, Math.ceil(yMax / 4));
  for (let v = 0; v <= yMax; v += step) {
    g += `<line x1="${L}" x2="${W - R}" y1="${y(v)}" y2="${y(v)}" class="perm-grid"/>`;
    g += `<text x="${L - 4}" y="${y(v) + 3}" class="perm-axis" text-anchor="end">${v}</text>`;
  }
  g += `<text x="${L}" y="${H - 5}" class="perm-axis">0s</text>`;
  g += `<text x="${W - R}" y="${H - 5}" class="perm-axis" text-anchor="end">${permFmtTime(tMax)}</text>`;
  // base line
  g += `<line x1="${L}" x2="${W - R}" y1="${y(st.base_score)}" y2="${y(st.base_score)}" class="perm-base"/>`;
  // candidates
  for (const [t, s] of permTries) {
    const over = s > yMax;
    g += `<circle cx="${x(t).toFixed(1)}" cy="${y(s).toFixed(1)}" r="1.6" class="perm-dot${over ? " over" : ""}"/>`;
  }
  // best-so-far step line
  const tl = st.timeline.slice();
  if (tl.length) {
    tl.push([st.elapsed, st.best_score]);
    let d = `M${x(tl[0][0])},${y(tl[0][1])}`;
    for (let i = 1; i < tl.length; i++) d += `H${x(tl[i][0])}V${y(tl[i][1])}`;
    g += `<path d="${d}" class="perm-best"/>`;
  }
  permChart.innerHTML = g;
}

function permRenderFeed() {
  const rows = permFeedItems.slice(-60).reverse().map(ev => {
    const t = ev.t.toFixed(1).padStart(6) + "s";
    if (ev.kind === "base") return `<div class="perm-ev base">${t}  base compiled: ${ev.score} diffs</div>`;
    if (ev.kind === "phase") return `<div class="perm-ev base">${t}  ${escapeHtml(ev.text)}</div>`;
    if (ev.kind === "fatal") return `<div class="perm-ev bad">${t}  worker ${ev.worker} stopped: ${escapeHtml((ev.text || "").trim().split("\n").pop())}</div>`;
    const p = permShortPass(ev.pass_);
    const asm = permIsAsm(ev.pass_) ? " asm" : "";
    if (ev.kind === "found") {
      return `<div class="perm-ev ${ev.improved ? "good" : "same"}${asm}">${t}  w${ev.worker}  ${p.padEnd(24)} ${ev.improved ? "NEW BEST" : "kept"} ${ev.score} diffs  (#${ev.n})</div>`;
    }
    const s = ev.score === null ? "didn't compile" : ev.score + " diffs";
    return `<div class="perm-ev${ev.score === null ? " fail" : ""}${asm}">${t}  w${ev.worker}  ${p.padEnd(24)} ${s}</div>`;
  });
  permFeed.innerHTML = rows.join("");
}

function permRenderPasses(st) {
  const rows = Object.entries(st.passes).sort((a, b) => b[1][1] - a[1][1] || b[1][0] - a[1][0]);
  permPasses.innerHTML = "<tr><th>pass</th><th>tried</th><th>new best</th><th>no compile</th></tr>" + rows.map(([p, [n, imp, bad]]) =>
    `<tr class="${permIsAsm(p) ? "asm" : ""}${imp ? " hit" : ""}"><td>${permShortPass(p)}</td><td>${n}</td><td>${imp || ""}</td><td>${n ? Math.round(100 * bad / n) + "%" : ""}</td></tr>`).join("");
}

function permRenderResults(st) {
  if (!st.outputs.length) return;
  permResults.innerHTML = st.outputs.map(o =>
    `<div class="perm-res${o.n === permSelected ? " sel" : ""}${o.score === 0 ? " match" : ""}" data-n="${o.n}">
       <b>${o.score}</b> diffs <span>#${o.n} at ${permFmtTime(o.t)} via ${permShortPass(o.pass_)}</span></div>`).join("");
}

permResults.addEventListener("click", async (e) => {
  const row = e.target.closest(".perm-res");
  if (!row) return;
  permSelected = Number(row.dataset.n);
  if (permLast) permRenderResults(permLast);
  const out = await (await fetch(`/api/permuter/output?id=${encodeURIComponent(permJob)}&n=${permSelected}`)).json();
  if (out.error) return;
  const lines = out.diff.split("\n").map(l => {
    const cls = l.startsWith("+") && !l.startsWith("+++") ? "add" : l.startsWith("-") && !l.startsWith("---") ? "del" : l.startsWith("@@") ? "hunk" : "";
    const asm = /\basm\b|__asm__/.test(l) && cls === "add" ? " asm" : "";
    return `<div class="perm-dl ${cls}${asm}">${escapeHtml(l) || "&nbsp;"}</div>`;
  }).join("");
  permOutput.innerHTML = `<div class="perm-out-head">Result #${out.n}: change against the code the run started from
      <button id="perm-load">Load into editor</button><button id="perm-load-build">Load &amp; Build</button></div>
    <div class="perm-diff">${lines || '<div class="empty-hint">same source text</div>'}</div>`;
  const load = () => {
    cEditor.value = permReplaceFunction(cEditor.value, currentFunc, out.function);
    syncHighlight();
    statusEl.textContent = `Loaded permuter result #${out.n} (Ctrl+Z won't undo this; the run's base is in scratch/permuter)`;
  };
  document.getElementById("perm-load").addEventListener("click", load);
  document.getElementById("perm-load-build").addEventListener("click", () => { load(); doBuild(); });
});

// Replace FUNC's definition in the editor text with the permuter's version,
// keeping the declarations around it; falls back to appending.
function permReplaceFunction(text, func, newFn) {
  const re = new RegExp("^[^\\n;{}]*\\b" + func + "\\s*\\([^;{]*\\)\\s*\\{", "m");
  const m = re.exec(text);
  newFn = newFn.replace(/^\s+/, "").replace(/\s+$/, "") + "\n";
  if (!m) return text.replace(/\s*$/, "\n\n") + newFn;
  let i = m.index + m[0].length, depth = 1;
  while (i < text.length && depth) {
    const c = text[i++];
    if (c === "{") depth++;
    else if (c === "}") depth--;
  }
  while (i < text.length && text[i] !== "\n") i++;
  return text.slice(0, m.index) + newFn.replace(/\n$/, "") + text.slice(i);
}

window.addEventListener("resize", () => { if (permLast) permDrawChart(permLast); });
