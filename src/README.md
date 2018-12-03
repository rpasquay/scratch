# `src/`

Source files and private headers go into this directory.

Optionally/preferably grouped in sub-directories by the target they belong to.

## `src/lib/`

The sub-directory `lib/` does not relate to a target "lib" but is used to group library targets. So *executable* targets have sub-directories directly in `src/` whereas library targets (irrelevant if shared or dynamic) go into `src/lib/`.

Don't confuse this directory however with the `extern/` directory at project root level which is reserved for external libraries. In some projects `<project root>/extern/` is called `<project root>/lib/`. 