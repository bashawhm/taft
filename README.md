## Taft

The worlds greatest Pascal compiler by volume, writen for my compiler construction class

## Usage
`make clean; make`
`./taft <filename>`

The compiler will output a file called a.s containing 64 bit assembly representing the
program. 

## Testing
The Pascal files in the examples/ directory were used to test the compiler and it's output.
As well, files from the tests/ directory were used to supliment the testing. The files were
run through the compiler to generate the output, which was then compiled to a binary by clang
version 1001.0.46.4 on Mac OS 10.14. If one wishes to use GCC on Linux to compile the assembly,
one should remove the lines `.globl _main` and rename the `_main` function to `main`.

## Features
(1.0) Lexical Analysis

- Line numbering                                              DONE
- Two styles of comments                                      DONE

(1.5) Syntax Analysis: grammar adjustments

- Unlimited nesting of subprograms                            DONE
- Array access on both sides of assignment                    DONE
- Allow for statements                                        PARTIAL (No pascal style for loops, but C style are implimented)
- (optional) Another loop construct                           DONE (C style for loops are implimented)

(2.0) Symbol Table

- Memory-leak handler                                         NOT DONE

(2.5) Syntax Tree (Intermediate Code Generation)

- Visual print                                                DONE
- Memory-leak handler                                         NOT DONE

(3.0) Semantic Analysis & Type Checking

- Check list                                                  PARTIAL (See tests/Semantic/semantic-check-list.txt)
- Error reporting                                             PARTIAL (Not fantastic error messages, but correct)

(4.0) Code Generation

- Input/Output statements                                     DONE
- Simple expressions (arithmetic and relational): gencode     DONE
- Statements (assignment, conditional, loop)                  DONE
- Nonlocal names: base frame pointer (static scope parent)    NOT DONE
- Recursive routines (example: GCD program)                   PARTIAL (functions and procedures can call themselves, but argument passing isn't implimented - here's no point)
- Complex expressions (register spilling)                     NOT DONE
- (optional) Arrays (L-value, R-value, parameters, nonlocal)  PARTIAL (Integer array support)

Other things not implimented and not referenced above:
- Uninary minus
- nesting of array indexing

## Symantics
See tests/Semantic/semantic-check-list.txt

## Freewill project

For the freewill project I targeted 64 bit assembly instead of 32 bit, as well as implimented
C-Style for loops.

## Haiku
See haiku.txt