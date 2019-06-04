# C programming exercises

The repository contains some exercises implementations and code exploration based on `c`, with the purpose of becoming more familiar with the language.

## Building

To check memory errors you can use `valgrind` with the command:

```
$ valgrind <output_file> --track-origins=yes --leak-check=full --read-var-info=yes
```

For building the exercises on Linux-based distributions, you can use the `gcc` compiler with the command:

```
$ gcc -o <output_file> <source_file>.c -Wall
```

This command compile the `source_file` and output the result to an executable `output_file`.

## Executing

For executing the binary file, you can use the command:

```
$ ./<output_file>
```

## TBD

* [ ] Implements tests
* [ ] Use Makefile for automatic code checking and testin
