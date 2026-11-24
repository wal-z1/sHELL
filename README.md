# Compact Shell in C

A minimalist, lightweight command-line shell written in portable C.

## Overview

This project provides a compact, educational Unix/Windows-compatible command interpreter (shell) built in pure C with zero external dependencies.

### Features

- **REPL Architecture**: Clean Read-Eval-Print Loop.
- **Cross-Platform**: Supports both Windows (via `_spawnvp` / MinGW) and POSIX (via `fork` / `execvp`).
- **Built-in Commands**:
  - `cd <path>`: Change working directory.
  - `help`: Display help and available built-in commands.
  - `exit`: Terminate the shell session.
- **External Program Execution**: Spawns external binaries available in your system `PATH`.
- **Lightweight**: Self-contained in a single, well-documented source file.

---

## Getting Started

### Prerequisites

- A C compiler (such as GCC, Clang, or MSVC)
- Make (optional)

### Build Instructions

#### Using GCC directly:
```bash
gcc -Wall -Wextra -O2 shell.c -o shell
```

On Windows (MinGW):
```powershell
gcc -Wall -Wextra -O2 shell.c -o shell.exe
```

#### Using Make:
```bash
make
```

To clean build artifacts:
```bash
make clean
```

---

## Usage

Run the compiled executable:

```powershell
./shell.exe
```

Example session:
```text
Compact C Shell initialized. Type 'help' for commands, 'exit' to quit.
minishell> help

=== Compact C Shell ===
Type program names and arguments, then hit Enter.
Built-in commands:
  - cd
  - help
  - exit
Use standard system commands (e.g., dir, ls, ping) as usual.

minishell> cd ..
minishell> exit
```

---

## Project Structure

```text
.
├── .gitignore   # Git ignore rules for build artifacts
├── Makefile     # Cross-platform Makefile
├── README.md    # Project documentation
└── shell.c      # Shell source code
```

---

## License

MIT License. Free to use, modify, and distribute.
