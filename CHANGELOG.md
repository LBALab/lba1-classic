# Changelog

All notable changes to this project will be documented in this file.


## Unreleased

### Added
- Skip Adeline Logo
- Enable/Disable Wall Collision damage.
- Initial platform-agnostic and DOS-agnostic library refactors, including an initial DOS platform layer.
- Removed the player selection screen now that autosave and the enhanced save system are available.


### Fixed
- FLA movie playback reliability and the ability to skip FLA movies with ENTER.
- Sprite sort order and several visual glitches.
- Work with CDROM if available, otherwise use current directory
- Improved DOSBox/VESA emulation behavior and fixed DOS keyboard build issues.
- Allow LBA to play on Windows 9x even if in DOS mode.

### Others
- Converted many ASM routines to C for better maintainability and portability.

### Removed
- Unused and obsolete DOS-specific files to simplify the codebase.

---

_Check the [AUTHORS.md](AUTHORS.md) file for contributions and authorship information._
