# Lexer and Parser Project

## Overview
This project is designed to build a lexer and parser using Flex and C. The lexer reads input from a file (`lexerAnalyzer.gcupl`) and identifies different tokens such as types, commands, conditions, identifiers, and various operators. The project includes:

- `Makefile`: Automates the build process.
- `lexer.l`: Contains the Flex lexer rules.
- `lexerAnalyzer.gcupl`: Sample input file for the lexer.

## Files

### Makefile
The Makefile includes the necessary commands to build and clean the lexer.

- **Build**: `make lexer`
- **Clean**: `make clean`

#### Build Commands
```makefile
lexer: lexer.l
    flex lexer.l
    gcc -o Lexer lex.yy.c -ll
    ./Lexer lexerAnalyzer.gcupl

clean:
    rm -f Lexer
    rm -f lex.yy.c
    rm -f a.out
    ls -l
