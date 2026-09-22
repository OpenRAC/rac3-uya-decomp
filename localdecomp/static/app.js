const buildBtn = document.getElementById("build-btn");
const saveBtn = document.getElementById("save-btn");
const exportDiffBtn = document.getElementById("export-diff-btn");
const scoreBadge = document.getElementById("score-badge");
const statusEl = document.getElementById("status");
const cEditor = document.getElementById("c-editor");
const cHighlight = document.getElementById("c-highlight");
const cHighlightCode = document.getElementById("c-highlight-code");
const diffView = document.getElementById("diff-view");
const sidebarToggleBtn = document.getElementById("sidebar-toggle-btn");
const funcSidebar = document.getElementById("func-sidebar");

let currentFunc = null;
let allFunctions = [];
let lastBuildDiff = null; // full diff JSON from the most recent successful /api/build, for export

sidebarToggleBtn.addEventListener("click", () => {
  funcSidebar.classList.toggle("collapsed");
});

async function loadFunctions() {
  const res = await fetch("/api/functions");
  const data = await res.json();
  if (data.error) {
    statusEl.textContent = "Error: " + data.error;
    return;
  }
  allFunctions = data.functions;
  renderProgressBar();
  renderSidebar();
  if (!currentFunc && allFunctions.length > 0) {
    await selectFunction(allFunctions[0].name);
  }
}

const sidebarFilter = document.getElementById("sidebar-filter");
const sidebarList = document.getElementById("sidebar-list");

function renderSidebar() {
  const query = sidebarFilter.value.trim();
  const list = allFunctions.filter((fn) => fuzzyMatch(query, fn.name));
  sidebarList.innerHTML = list
    .map((fn) => {
      const selectedCls = fn.name === currentFunc ? "selected" : "";
      const dotCls = fn.match_status; // "perfect" | "partial" | "none"
      const scoreStr =
        fn.match_status === "partial"
          ? `${matchPercent(fn.current_score, fn.max_score).toFixed(0)}%`
          : "";
      return `<div class="sidebar-item ${selectedCls}" data-name="${fn.name}">
        <span class="dot ${dotCls}"></span>
        <span class="sname">${escapeHtml(fn.name)}</span>
        <span class="sscore">${escapeHtml(scoreStr)}</span>
      </div>`;
    })
    .join("");
}

sidebarFilter.addEventListener("input", renderSidebar);

sidebarList.addEventListener("click", (e) => {
  const item = e.target.closest(".sidebar-item");
  if (item && item.dataset.name) {
    selectFunction(item.dataset.name);
  }
});

function renderProgressBar() {
  const total = allFunctions.length;
  const fill = document.getElementById("progress-fill");
  const label = document.getElementById("progress-label");
  if (total === 0) {
    fill.innerHTML = "";
    label.textContent = "no functions found";
    return;
  }
  const perfect = allFunctions.filter((f) => f.match_status === "perfect").length;
  const partialFns = allFunctions.filter((f) => f.match_status === "partial");
  const partial = partialFns.length;
  const unverified = allFunctions.filter((f) => f.match_status === "unverified").length;
  const none = total - perfect - partial - unverified;
  const pct = (n) => (n / total) * 100;

  // The yellow "partial" segment's own width only shows HOW MANY functions
  // have a partial candidate, treating a 5%-matched attempt the same as a
  // 95%-matched one. Overlay a second bar INSIDE that segment, sized by the
  // average match_percent across just those partial functions, so the
  // segment visually fills in as partial candidates actually get closer to
  // 100%, not just as more of them appear.
  const avgPartialPct = partial > 0
    ? partialFns.reduce((sum, f) => sum + matchPercent(f.current_score, f.max_score), 0) / partial
    : 0;

  fill.innerHTML = `
    <div class="seg-perfect" style="width:${pct(perfect)}%"></div>
    <div class="seg-partial" style="width:${pct(partial)}%">
      <div class="seg-partial-fill" style="width:${avgPartialPct}%" title="avg ${avgPartialPct.toFixed(1)}% match across partial functions"></div>
    </div>
    <div class="seg-unverified" style="width:${pct(unverified)}%"></div>
    <div class="seg-none" style="width:${pct(none)}%"></div>
  `;
  const overallPct = ((perfect / total) * 100).toFixed(1);

  // Function-count percentage treats a 4-byte stub the same as a 472-byte
  // one, which overstates progress once the easy small functions are gone.
  // Weight by actual bytes of target code instead: sum of every matched
  // function's own byte size (from splat's "nonmatching NAME, 0xSIZE"),
  // divided by the total byte size of every tracked function. Falls back
  // to the count-based percentage if size data is missing for everything
  // (e.g. an older /api/functions response).
  const totalBytes = allFunctions.reduce((sum, f) => sum + (f.size || 0), 0);
  let byteLabel = "";
  if (totalBytes > 0) {
    const matchedBytes = allFunctions
      .filter((f) => f.match_status === "perfect")
      .reduce((sum, f) => sum + (f.size || 0), 0);
    const bytePct = ((matchedBytes / totalBytes) * 100).toFixed(1);
    byteLabel = `, ${bytePct}% by code size (${matchedBytes}/${totalBytes} bytes)`;
  }

  label.textContent =
    `${perfect} matched, ${partial} partial, ${unverified} unverified, ${none} not started, ` +
    `${total} functions total, ${overallPct}% fully matched${byteLabel}`;
}

function fuzzyMatch(query, text) {
  // Simple substring-first, then loose fuzzy fallback (like a "goto" filter):
  // characters of query must appear in order in text, not necessarily
  // contiguous, so "rst" matches "RequestScreenTransition"-style names too.
  query = query.toLowerCase();
  text = text.toLowerCase();
  if (query === "") return true;
  if (text.includes(query)) return true;
  let qi = 0;
  for (let ti = 0; ti < text.length && qi < query.length; ti++) {
    if (text[ti] === query[qi]) qi++;
  }
  return qi === query.length;
}

document.addEventListener("keydown", (e) => {
  if (e.ctrlKey && e.key.toLowerCase() === "k") {
    e.preventDefault();
    funcSidebar.classList.remove("collapsed");
    sidebarFilter.focus();
    sidebarFilter.select();
  }
});

// Same formula decomp.me uses: 100% only at a perfect (0) score, clamped at
// 0% so a current_score above max_score (a genuinely bad/rewritten match)
// never shows negative.
function matchPercent(current_score, max_score) {
  if (!max_score) return current_score === 0 ? 100 : 0;
  const pct = (100 * (max_score - current_score)) / max_score;
  return Math.max(0, Math.min(100, pct));
}

async function selectFunction(name) {
  currentFunc = name;
  statusEl.textContent = "Loading " + name + "...";
  const res = await fetch("/api/function?name=" + encodeURIComponent(name));
  const data = await res.json();
  if (data.error) {
    statusEl.textContent = "Error: " + data.error;
    return;
  }
  cEditor.value = data.c;
  syncHighlight();
  diffView.innerHTML = '<div class="empty-hint">Click Build to compile and diff.</div>';
  scoreBadge.textContent = "no build yet";
  scoreBadge.className = "score-badge";
  statusEl.textContent = "Loaded " + name;
  lastBuildDiff = null;
  exportDiffBtn.disabled = true;
  renderSidebar();
}

async function doBuild() {
  if (!currentFunc) return;
  statusEl.textContent = "Building...";
  buildBtn.disabled = true;
  try {
    const res = await fetch("/api/build", {
      method: "POST",
      headers: { "Content-Type": "application/json" },
      body: JSON.stringify({ name: currentFunc, c: cEditor.value }),
    });
    const data = await res.json();
    if (!data.ok) {
      renderError(data.stage, data.message);
      scoreBadge.textContent = "build failed";
      scoreBadge.className = "score-badge bad";
      statusEl.textContent = "Failed at stage: " + data.stage;
      lastBuildDiff = null;
      exportDiffBtn.disabled = true;
      return;
    }
    renderDiff(data.diff);
    const { current_score, max_score } = data.diff;
    const pct = matchPercent(current_score, max_score).toFixed(2);
    scoreBadge.textContent = `${pct}% match (${current_score} / ${max_score})`;
    scoreBadge.className = "score-badge " + (current_score === 0 ? "good" : "");
    statusEl.textContent = "Build OK";
    lastBuildDiff = data.diff;
    exportDiffBtn.disabled = false;
    await loadFunctions(); // refresh match_status/progress bar with the new score
  } catch (e) {
    statusEl.textContent = "Request failed: " + e;
  } finally {
    buildBtn.disabled = false;
  }
}

buildBtn.addEventListener("click", doBuild);
cEditor.addEventListener("keydown", (e) => {
  if (e.ctrlKey && e.key === "Enter") {
    e.preventDefault();
    doBuild();
    return;
  }
  // Tab/Shift+Tab indent like a real code editor instead of moving focus
  // out of the textarea (the browser's default <textarea> behavior).
  if (e.key === "Tab") {
    e.preventDefault();
    const el = cEditor;
    const start = el.selectionStart;
    const end = el.selectionEnd;
    const value = el.value;
    const INDENT = "    "; // 4 spaces, matching this project's C style

    if (start === end && !e.shiftKey) {
      // No selection: just insert the indent at the cursor.
      el.value = value.slice(0, start) + INDENT + value.slice(end);
      el.selectionStart = el.selectionEnd = start + INDENT.length;
      return;
    }

    // Selection spans one or more lines: indent/dedent every line in it,
    // like Tab/Shift+Tab do in a real code editor.
    let lineStart = value.lastIndexOf("\n", start - 1) + 1;
    const before = value.slice(0, lineStart);
    const selected = value.slice(lineStart, end);
    const after = value.slice(end);
    const lines = selected.split("\n");

    let firstLineDelta = 0;
    const newLines = lines.map((line, i) => {
      if (e.shiftKey) {
        if (line.startsWith(INDENT)) {
          if (i === 0) firstLineDelta = -INDENT.length;
          return line.slice(INDENT.length);
        }
        const stripped = line.replace(/^ {1,4}/, "");
        if (i === 0) firstLineDelta = -(line.length - stripped.length);
        return stripped;
      }
      if (i === 0) firstLineDelta = INDENT.length;
      return INDENT + line;
    });

    const newSelected = newLines.join("\n");
    el.value = before + newSelected + after;
    el.selectionStart = start + firstLineDelta;
    el.selectionEnd = before.length + newSelected.length;
  }
});

async function doSave() {
  if (!currentFunc) return;
  statusEl.textContent = "Saving...";
  saveBtn.disabled = true;
  try {
    const res = await fetch("/api/save", {
      method: "POST",
      headers: { "Content-Type": "application/json" },
      body: JSON.stringify({ name: currentFunc, c: cEditor.value }),
    });
    const data = await res.json();
    if (!data.ok) {
      statusEl.textContent = "Save failed at stage: " + data.stage + " - " + data.message;
      return;
    }
    statusEl.textContent = "Saved " + currentFunc + " to src/text.c";
    await loadFunctions();
  } catch (e) {
    statusEl.textContent = "Save request failed: " + e;
  } finally {
    saveBtn.disabled = false;
  }
}

saveBtn.addEventListener("click", doSave);

function renderError(stage, message) {
  diffView.innerHTML =
    `<div class="diff-error">Build failed at stage: ${escapeHtml(stage)}\n\n${escapeHtml(message)}</div>`;
}

// Segment formats that count as "this row differs from the other side",
// mirroring decomp.me's whole-row highlighting rather than per-token tinting.
const DIFF_FORMATS = new Set(["diff_add", "diff_remove", "diff_change", "register"]);

function renderSegments(segments) {
  if (!segments) return "";
  return segments
    .map((seg) => {
      const cls = seg.format ? "seg-" + seg.format : "";
      // Segments with no diff-relevant format (or plain "text") get MIPS
      // mnemonic/register/symbol/immediate coloring; segments asm-differ
      // itself flagged (diff_add/remove/change, register, rotation, ...)
      // keep their own diff-status color instead, so the diff highlight
      // always takes priority over generic syntax coloring.
      if (!seg.format || seg.format === "text") {
        return `<span class="${cls}">${highlightMipsText(seg.text)}</span>`;
      }
      return `<span class="${cls}">${escapeHtml(seg.text)}</span>`;
    })
    .join("");
}

function rowHasDiffFormat(side) {
  if (!side || !side.text) return false;
  return side.text.some((seg) => seg.format && DIFF_FORMATS.has(seg.format));
}

function classifyRow(row) {
  const hasBase = !!row.base;
  const hasCurrent = !!row.current;
  if (hasBase && !hasCurrent) return "row-remove";
  if (hasCurrent && !hasBase) return "row-add";
  if (rowHasDiffFormat(row.base) || rowHasDiffFormat(row.current)) return "row-change";
  return "row-same";
}

function renderDiff(diffData) {
  const rows = diffData.rows || [];
  let html = "";
  for (const row of rows) {
    const rowClass = classifyRow(row);
    const baseHtml = row.base ? renderSegments(row.base.text) : "";
    const curHtml = row.current ? renderSegments(row.current.text) : "";
    html += `<div class="diff-row ${rowClass}"><div class="base">${baseHtml}</div><div class="current">${curHtml}</div></div>`;
  }
  diffView.innerHTML = html || '<div class="empty-hint">No rows returned.</div>';
}

// ---------------------------------------------------------------------
// AI-readable diff export
// ---------------------------------------------------------------------
// Turns the most recent build's diff JSON into a single plain-text file:
// function metadata, current C source, and a compact target-vs-candidate
// row rendering (identical rows skipped, like harness.py's own
// render_diff_rows) -- meant to be pasted or attached directly into a
// chat with any AI, no HTML/JS/JSON wrangling required on their end.

function segmentsToPlainText(segments) {
  if (!segments) return "";
  return segments.map((seg) => seg.text).join("");
}

function buildDiffExportText(name, diffData, cSource) {
  const rows = diffData.rows || [];
  const { current_score, max_score } = diffData;
  const pct = matchPercent(current_score, max_score).toFixed(2);

  const lines = [];
  lines.push(`FUNCTION: ${name}`);
  lines.push(`MATCH: ${pct}% (current_score=${current_score}, max_score=${max_score})`);
  lines.push("");
  lines.push("=== CURRENT C SOURCE (as last built) ===");
  lines.push(cSource.trimEnd());
  lines.push("");
  lines.push("=== DIFF: target (left) vs current candidate (right) ===");
  lines.push("Rows that already match are omitted. '(missing)' means that side has no");
  lines.push("instruction at this row (the other side has extra/different code here).");
  lines.push("");

  let skippedRun = 0;
  const flushSkipped = () => {
    if (skippedRun > 0) {
      lines.push(`  ... ${skippedRun} matching row${skippedRun === 1 ? "" : "s"} omitted ...`);
      skippedRun = 0;
    }
  };

  for (const row of rows) {
    const rowClass = classifyRow(row);
    if (rowClass === "row-same") {
      skippedRun++;
      continue;
    }
    flushSkipped();
    const baseText = row.base ? segmentsToPlainText(row.base.text).trim() : "(missing)";
    const curText = row.current ? segmentsToPlainText(row.current.text).trim() : "(missing)";
    lines.push(`TARGET:  ${baseText}`);
    lines.push(`CURRENT: ${curText}`);
    lines.push("");
  }
  flushSkipped();

  return lines.join("\n");
}

function downloadTextFile(filename, text) {
  const blob = new Blob([text], { type: "text/plain;charset=utf-8" });
  const url = URL.createObjectURL(blob);
  const a = document.createElement("a");
  a.href = url;
  a.download = filename;
  document.body.appendChild(a);
  a.click();
  document.body.removeChild(a);
  URL.revokeObjectURL(url);
}

function doExportDiff() {
  if (!currentFunc || !lastBuildDiff) return;
  const text = buildDiffExportText(currentFunc, lastBuildDiff, cEditor.value);
  downloadTextFile(`${currentFunc}_diff.txt`, text);
  statusEl.textContent = `Exported ${currentFunc}_diff.txt`;
}

exportDiffBtn.addEventListener("click", doExportDiff);

function escapeHtml(s) {
  return String(s)
    .replace(/&/g, "&amp;")
    .replace(/</g, "&lt;")
    .replace(/>/g, "&gt;");
}

// ---------------------------------------------------------------------
// Syntax highlighting
// ---------------------------------------------------------------------
// Both highlighters are small hand-rolled tokenizers, not a real parser --
// good enough for coloring, not for anything that needs to understand the
// code. Each token becomes <span class="tok-...">text</span>; anything
// unmatched passes through escaped but uncolored.

const C_KEYWORDS = new Set([
  "if", "else", "for", "while", "do", "switch", "case", "default", "break",
  "continue", "return", "goto", "sizeof", "typedef", "struct", "union",
  "enum", "static", "extern", "const", "volatile", "register", "inline",
  "void", "__asm__", "asm",
]);
const C_TYPES = new Set([
  "s8", "u8", "s16", "u16", "s32", "u32", "s64", "u64", "f32", "f64",
  "int", "char", "short", "long", "float", "double", "unsigned", "signed",
  "size_t", "void",
]);

// Order matters: earlier patterns win when they start at the same index.
const C_TOKEN_RE = new RegExp(
  [
    /\/\/.*$/.source,                                  // line comment
    /\/\*[\s\S]*?\*\//.source,                         // block comment
    /"(?:\\.|[^"\\])*"/.source,                        // string literal
    /'(?:\\.|[^'\\])*'/.source,                        // char literal
    /#\s*\w+/.source,                                  // preprocessor
    /\b0[xX][0-9A-Fa-f]+\b/.source,                    // hex literal
    /\b\d+\.\d+[fF]?\b|\b\d+[uUlLfF]*\b/.source,       // number literal
    /\b[A-Za-z_]\w*(?=\s*\()/.source,                  // function-call-ish name
    /\b[A-Za-z_]\w*\b/.source,                         // identifier/keyword
    /[{}()\[\];,.]/.source,                            // punctuation
  ].join("|"),
  "gm"
);

function highlightC(src) {
  let out = "";
  let last = 0;
  C_TOKEN_RE.lastIndex = 0;
  let m;
  while ((m = C_TOKEN_RE.exec(src))) {
    if (m.index > last) out += escapeHtml(src.slice(last, m.index));
    const tok = m[0];
    out += escapeHtml(tok).replace(/^(.*)$/, (full) => {
      let cls = null;
      if (tok.startsWith("//") || tok.startsWith("/*")) cls = "tok-comment";
      else if (tok.startsWith('"') || tok.startsWith("'")) cls = "tok-string";
      else if (tok.startsWith("#")) cls = "tok-preproc";
      else if (/^0[xX]/.test(tok) || /^\d/.test(tok)) cls = "tok-num";
      else if (/^[{}()\[\];,.]$/.test(tok)) cls = "tok-punct";
      else if (C_KEYWORDS.has(tok)) cls = "tok-kw";
      else if (C_TYPES.has(tok)) cls = "tok-type";
      else if (/^[A-Za-z_]\w*$/.test(tok) && src[m.index + tok.length] === "(") cls = "tok-func";
      return cls ? `<span class="${cls}">${full}</span>` : full;
    });
    last = m.index + tok.length;
  }
  out += escapeHtml(src.slice(last));
  return out;
}

function syncHighlight() {
  cHighlightCode.innerHTML = highlightC(cEditor.value) + "\n";
}

function syncScroll() {
  cHighlight.scrollTop = cEditor.scrollTop;
  cHighlight.scrollLeft = cEditor.scrollLeft;
}

cEditor.addEventListener("input", syncHighlight);
cEditor.addEventListener("scroll", syncScroll);

// MIPS asm highlighting for the diff view. asm-differ already segments
// each row with its own formats (diff_add/remove/change, register,
// rotation, ...) via renderSegments below; this adds mnemonic/register/
// symbol/immediate coloring UNDERNEATH those on plain "text"-formatted
// (or unformatted) segments, so a diff highlight always still wins.
// Every "$..." token (named ABI register like $sp, or numeric $0-$31/$f0-
// $f31) is colored as a register -- no need to validate the name here,
// since asm-differ's own disassembly output never emits a bogus one.
const MIPS_TOKEN_RE = new RegExp(
  [
    /\/\*.*?\*\//.source,                              // /* offset addr word */ comment
    /\$\w+/.source,                                    // $reg
    /\b0[xX][0-9A-Fa-f]+\b/.source,                    // hex immediate/address
    /\b-?\d+\b/.source,                                // decimal immediate/offset
    /\b(?:D|func|jtbl)_[0-9A-Fa-f]+(?:_\w*)?\b/.source, // project symbol names
    /\b[a-z][a-z0-9.]*\b(?=\s|$)/.source,               // mnemonic (lowercase, may contain '.')
    /[(),]/.source,                                    // punctuation
  ].join("|"),
  "gm"
);

function highlightMipsText(src) {
  let out = "";
  let last = 0;
  MIPS_TOKEN_RE.lastIndex = 0;
  let m;
  let firstWordOnLine = true;
  let lineStart = 0;
  while ((m = MIPS_TOKEN_RE.exec(src))) {
    if (m.index > last) {
      const between = src.slice(last, m.index);
      out += escapeHtml(between);
      if (between.includes("\n")) {
        firstWordOnLine = true;
        lineStart = m.index;
      }
    }
    const tok = m[0];
    let cls = null;
    if (tok.startsWith("/*")) cls = "tok-comment";
    else if (tok.startsWith("$")) cls = "tok-reg";
    else if (/^-?0[xX][0-9A-Fa-f]+$/.test(tok) || /^-?\d+$/.test(tok)) cls = "tok-imm";
    else if (/^(D|func|jtbl)_/.test(tok)) cls = "tok-sym";
    else if (/^[(),]$/.test(tok)) cls = "tok-punct";
    else if (/^[a-z]/.test(tok) && firstWordOnLine) cls = "tok-mnem";
    out += cls ? `<span class="${cls}">${escapeHtml(tok)}</span>` : escapeHtml(tok);
    if (/^[a-z]/.test(tok) && firstWordOnLine) firstWordOnLine = false;
    last = m.index + tok.length;
  }
  out += escapeHtml(src.slice(last));
  return out;
}

loadFunctions();
