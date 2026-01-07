**Repo Overview**

- **Purpose:** Tiny SDL3-based minimal engine wrapper providing window, renderer and simple draw helpers.
- **Structure:** headers in `include/` and implementation in `src/`. The example runner is `src/main.cpp`.

**Key Files**

- **Header:** [include/e2gine.hpp](include/e2gine.hpp) — color macros, `extern` globals `window` and `renderer`, API surface (`e2gine_init`, `Begin`/`End`, draw helpers).
- **Implementation:** [src/e2gine.cpp](src/e2gine.cpp) — SDL initialization, global definitions, drawing implementations (some functions are incomplete).
- **Example runner:** [src/main.cpp](src/main.cpp) — demonstrates usage and contains the canonical compile command.

**Big-picture architecture**

- Single-process, synchronous render loop: caller drives frames by calling `Begin()` → draw calls → `End()`.
- Global engine state: `window` and `renderer` are defined as `extern` in the header and instantiated in the implementation — most code uses these globals directly.
- Minimal abstraction: API is a lightweight wrapper around SDL3; prefer using the provided helpers instead of re-initializing SDL elsewhere.

**Project-specific conventions & patterns**

- Color constants are macros (e.g. `RED`, `YELLOW`) defined in `include/e2gine.hpp` — use them for consistency.
- Geometry types are plain POD structs: `Rectangle` and `Vec2`. Drawing helpers accept either struct or raw floats (e.g. `DrawRectangleRec`, `DrawRectangleVec`, `DrawRectangle`).
- Keep signatures stable: many functions are declared in the header and used directly in `src/main.cpp` — preserve names and return types when changing behavior.

**Build / run / debug**

Use the compile command embedded in `src/main.cpp` (works for quick local builds):

```bash
g++ -std=c++17 -Iinclude -o prog src/main.cpp src/e2gine.cpp -lSDL3
./prog
```

- The project links to `SDL3`; ensure `libsdl3-dev` (or your platform equivalent) is installed.
- There are no unit tests or build system files; changes should be verified by building and running the binary.

**Integration & external dependencies**

- Dependency: SDL3 (dynamic linker flag `-lSDL3`). Code assumes SDL3 API (see include of `<SDL3/SDL.h>`).
- Global state means any new module that needs rendering should reuse `renderer` instead of creating another one.

**Practical guidance for AI agents (what to do / what to avoid)**

- Preserve public API: keep function names and signatures declared in `include/e2gine.hpp` unless you update both header and all callers.
- Fix small missing implementations (example: `DrawLine` is empty in `src/e2gine.cpp`) — a correct implementation can call `SDL_RenderDrawLineF(renderer, x1, y1, x2, y2);` after setting the draw color.
- Prefer minimal, localized changes: implement missing helper bodies, add sanity checks where clearly missing (e.g. check SDL init / create return values), but avoid large refactors that introduce new build tooling.
- Use existing macros for colors rather than introducing new constants or enums.
- When adding tests or CI, keep them lightweight (a single build + run smoke test) — avoid heavy frameworks.

**Small examples from this repo**

- Colors/macros: see `include/e2gine.hpp` for `RED`, `YELLOW`, etc.
- Minimal draw loop: `src/main.cpp` demonstrates `e2gine_init(...)`, `while(windowShouldClose()) { Begin(...); Draw...; End(); }`.
- Suggested `DrawLine` fix (apply with matching style):

```cpp
void DrawLine(float x1, float y1, float x2, float y2, SDL_Color color){
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderDrawLineF(renderer, x1, y1, x2, y2);
}
```

**What I could not infer (ask the maintainer)**

- Intended error-handling semantics for `e2gine_init` (currently returns `true` unconditionally). Should failure bubble up or abort?
- Any preferred naming/formatting rules (clang-format, etc.) or commit guidelines for PRs.

If you'd like, I can open a small PR implementing `DrawLine`, add basic SDL error checks in `e2gine_init`, and include a short README with the build command. Any preferences or constraints?
