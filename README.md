# acme9k

This is a fork of the `acme` text editor from the `plan9port` distribution. It combines the customizability of [lumar](https://github.com/lumar)/[sminez](https://github.com/sminez/plan9port)'s forks and [acme2k](https://github.com/karahobny/acme2k) with upstream fixes from [9fans](https://github.com/9fans/plan9port) and some custom work.

Namely, when click-to-focus is enabled, the active text frame renders the tick (aka the text cursor) with the hilight color (`COLOR_<TAG|BODY>_HI`); otherwise the tick is rendered with the text color (`COLOR_<TAG|BODY>_TX`). This is all done with a fork of `libframe` which is included in the distribution and compiled into the program, and some simple logic that selects the proper ticks for each frame when the focus changes and forces a redraw.

See the `config.def.h` for out of the box customizations that can be done. Below is a screenshot of my typical setup (note I use compositing rules to make the window transparent, this is not in the scope of `acme` itself).

[![screenshot](./scrot.png)](./scrot.png)

## usage

Keybindings are as follows:

- Ctrl
  - c: copy
  - x: cut
  - v: paste
  - z: undo
  - y: redo
  - s: save
  - e: move to end of line
  - a: move to begining of line
  - f: filename completion
  - u: kill line
  - w: kill word (backwords)
- Up/Down: move cursor
- PgUp/PgDown: the obvious
- Esc: cut if there is a selection, otherwise hilight the most recently edited text

Users unfamiliar with `acme` in general should check the following resources:

- [Acme: A User Interface for Programmers](http://doc.cat-v.org/plan_9/4th_edition/papers/acme/) - the definitive guide from Rob Pike
- [A Tour of Acme](https://research.swtch.com/acme) - Russ Cox giving a tour of acme on plan9port (video)
- [acme(1)](http://man.cat-v.org/plan_9/1/acme) - manual page

## build

- Clone this repository
- From the repo root, if desired, copy `config.def.h` to `config.h` and make your modifications (you will almost certainly want to change the fonts; my default primary font is Sauce Code Pro Nerd Font)
- Run `./build.sh` from the repo root.

## install

After building, run `./install.sh`; If run as a regular user, it will install to `~/bin/9`; if run as root, it will overwrite the systemwide `acme` in `$PLAN9/bin`

## helpers

The `scripts` directory contains some helpers, mostly just shortcuts for [acme-lsp](https://github.com/fhs/acme-lsp). Also shortcuts to change font size and a `Slide` utility (for presentations). Copy them to your `$PATH` and let 'em rip.

These work only in window tags (not column or row tags):

- `F+`: increase font size
- `F-`: decrease font size
- `Slide+`: move to the next file in the current directory (alphabetical order)
- `Slide-`: move to the previous file in the current directory (alphabetical order)
- `Slide`: move to the named file in the current directory (called by the previous two)

These will work anywhere:

- `agols`: pass a colon-separated list of workspaces to start `acme-lsp` for go development
- `atsls`: pass a colon-separated list of workspaces to start `acme-lsp` for javascript/typescript development
- `acls`: pass a colon-separated list of workspaces to start `acme-lsp` for C/C++ development
- `acsls`: pass a colon-separated list of workspaces to start `acme-lsp` for C# development

For `acls` to work right with plan9port C stuff you will need to add your `$PLAN9/include` directory to the compile flags in either the project `.clangd` file or your `~/.config/clangd/config.yaml`:

```
CompileFlags:
  Add: 
    - "-I/usr/lib/plan9/include"
```

The C# server doesn't seem to be able to handle metadata yet (eg, going to definitions that are part of the standard library or packages).

See also:

- [plumbing rules](https://nilfm.cc/git/dotfiles/tree/plumbing) - my plumbing rules, includes opening headers by right-click on the filename in an include directive

The `Toolbox` file contains a compilation of `sam` command language (`Edit` scripts) that may be useful.

## thanks

- [rob pike](https://github.com/robpike) - author of the original `acme` for Plan9
- [russ cox](https://research.swtch.com) and the rest of the [9fans](https://github.com/9fans) for [plan9port](https://github.com/9fans/plan9port)
- [lumar](https://github.com/lumar) - looks like they deleted their github repos but I originally pulled my keybinds from there
- [sminez](https://github.com/sminez) - possibly the original source of lumar's keybindings
- [karahobny](https://github.com/karahobny) - creator of acme2k, a big inspiration for this project
- [aksr](https://github.com/aksr) - source of the missing tag border pixel fix
- [chyvonomys](https://github.com/chyvonomys) - source of a few  bugfixes
- [jxy](https://github.com/jxy) - source of the column drag window drift fix
