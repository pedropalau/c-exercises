# C programming exercises

This repository contains some exercises implementations and code exploration based on `c`, with the purpose of becoming more familiar with the language.

## Building

For building the exercises on Linux-based distributions, you can use the `gcc` compiler with the command:

```
$ gcc -o <output_file> <source_file>.c -Wall
```

Alternative, you cand build the exercises using `clang` compiler:

```
$ clang <source_file> -o <outpue_file>
```

This command compile the `source_file` and output the result to an executable `output_file`.

## Executing

For executing the binary file, you can use the command:

```
$ ./<output_file>
```

To check memory errors you can use `valgrind` with the command:

```
$ valgrind <output_file> --track-origins=yes --leak-check=full --read-var-info=yes
```

## Available commands

This options are available using `make` command:

* `make all-checks` - Run all checks over the code, like the code-style.
* `make build` - Create a binary build of each `main.c` available on subfolders.
* `make memory-check` - It runs `valgrind` to check memory errors.
* `make clean` - Remove all the `build` binary files.

## TBD

* [ ] Implements tests
* [x] Configure clang-format for code styling
* [x] Use Makefile for automatic code checking and testing
