# Divine

Divine is an open-source programming language for easily creating beautiful and capable graphical user interfaces. It is easy to use, lightning fast and extensible.

## Table of Contents

- [Table of Contents](#table-of-contents)
- [Features of Divine](#features-of-divine)
- [Installing Divine](#installing-divine)
- [Contributing to Divine](#contributing-to-divine)

## Features of Divine

- Intuitive syntax
- Exception handling
- Powerful object-oriented syntax
- Lightning fast after compilation
- Highly portable

## Installing Divine

Check out the releases page [here](https://github.com/BitPigeon/Divine/releases), and download the latest stable release.

## Contributing to Divine

Check out the contributing file [here](https://github.com/BitPigeon/Divine/blob/main/CONTRIBUTING.md)!

## Contributing: Understanding this Project

Divine is a simple programming language, and has three main components The Lexer, The Parser, and The Compiler. The Lexer can be found in the `lexer/` folder, and it takes a plain string and converts it into a list of tokens. The token object can be found in the `lexer/token/` folder. The Parser can be found in the `parser/` folder, and it take the list of tokens and converts it to an AST (Abstract Syntax Tree), which is essentially a list of nodes, the AST groups together tokens into expressions and statements. The AST objects can be found in the `parser/node/` folder. The Compiler takes the AST and converts it into a source file that can be read by the computer.
