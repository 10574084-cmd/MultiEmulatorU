# MultiEmulatorU

MultiEmulatorU is a Wii U homebrew frontend prototype for Aroma. It is intended to become a multi-system launcher for NES, SNES, Game Boy, GBA, Nintendo 64, Nintendo DS, PlayStation 1 and PSP.

## Important status

This repository starts as a **frontend/build prototype**, not a working emulator collection. Selecting a system does not emulate games until a compatible, legally distributable emulator core is integrated. PSP, DS, N64 and PS1 are especially demanding; performance depends on the core and game.

### Aroma vs WUP Installer

- **Aroma:** the intended homebrew format is a `.wuhb` application, placed on the SD card under `/wiiu/apps/` and launched from the Homebrew Launcher/Aroma environment as supported by the installed setup.
- **WUP Installer:** installs signed/title-format packages (`.wup` content). A `.wuhb` is **not** a WUP package. This workflow does not fabricate a WUP or claim a WUP Installer-ready title. Producing a legitimate installable title requires a separate title packaging/signing process and is not interchangeable with an Aroma homebrew build.

## Build

Pushes to `main` and manual workflow runs trigger GitHub Actions. The workflow builds with the devkitPro Wii U toolchain and uploads build outputs as an Actions artifact. Check the workflow log before treating any artifact as installable.

## Planned features

- System library and ROM file picker
- Per-system resolution, scaling, frame pacing and performance presets
- Save states and save management where supported by the selected core
- Per-game cheat files where supported by the selected core
- Controller mapping and configuration profiles

## ROMs and cores

This project does not include commercial ROMs, BIOS files, or proprietary emulator assets. Use game dumps and BIOS files you are legally entitled to use, and respect each core's license.
