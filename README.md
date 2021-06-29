# DAG-EUF-Algorithm

This project implements a uniform interpolation
algorithm for the theory of equations with 
uninterpreted symbols.

## Building the project

In the root directory, execute the command:

```
make bin/euf_interpolator
```

## Using the implementation

Call the binary _euf_interpolator_ in the bin folder followed
by the address of the SMT2 file containing the asserted formula
to be processed and the uncommon symbols to be eliminited
separated by a space.

Example:

```
./bin/euf_interpolator ./tests/smt2-files/test_1.smt2 e e1 e2
```
