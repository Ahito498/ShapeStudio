# Shape Studio

A GUI-based shape drawing and management application built with C++ using object-oriented design principles.

![C++](https://img.shields.io/badge/C++-17-blue.svg)
![OOP](https://img.shields.io/badge/Design-OOP-purple.svg)
![Graphics](https://img.shields.io/badge/Graphics-CMU%20Graphics%20Lib-orange.svg)
![License](https://img.shields.io/badge/License-MIT-yellow.svg)

---

## Overview

Shape Studio is a desktop GUI application for drawing, selecting, and manipulating geometric shapes. Built with C++ using the CMU Graphics Library, it demonstrates a clean MVC-style architecture with a full OOP class hierarchy — where each shape is a self-contained object with its own draw, resize, rotate, and color logic.

---

## Features

- Draw 7 shape types: Line, Rectangle, Square, Circle, Triangle, Oval, Hexagon
- Select, move, resize, and rotate shapes interactively
- Fill color and draw color management per shape
- Copy, paste, and delete operations
- Save and load drawings from file
- Icon-based GUI menu with CMU Graphics Library
- Full undo/redo-ready operation architecture

---

## Tech Stack

| Layer | Technology |
|-------|-----------|
| Language | C++ (C++17) |
| GUI Library | CMU Graphics Library |
| Architecture | MVC (Model-View-Controller) |
| Build | Visual Studio / g++ |

---

## OOP Design

```
Shape (Abstract Base Class)
├── Line
├── Rect
│   └── Square
├── Circle
├── Triangle
├── Oval
└── Hexagon

Operation (Abstract Base Class)
├── opAddCircle / opAddRect / opAddTriangle ...
├── opDelete / opCopy / opPaste
├── opResize / opRotate
├── opSave / opLoad
└── CHNGfillColor / opCHNGdrawColor
```

- **Abstraction**: `Shape` and `Operation` define clean interfaces
- **Inheritance**: Each shape/operation extends the base with specific logic
- **Polymorphism**: Shapes stored as `Shape*`, operations as `Operation*`
- **Encapsulation**: All shape state (position, color, size) fully encapsulated

---

## Getting Started

```bash
git clone https://github.com/Ahito498/ShapeStudio.git
cd ShapeStudio
# Open CIE202-project.sln in Visual Studio
# Build and run
```

---

## Project Structure

```
ShapeStudio/
├── main.cpp                  # Entry point
├── controller.h / .cpp       # MVC controller
├── DEFS.h                    # Global definitions
├── Shapes/                   # Shape class hierarchy
│   ├── Shape.h / .cpp        # Abstract base
│   ├── Circle, Rect, Square, Triangle, Oval, Hexagon, Line
├── operations/               # Operation class hierarchy
│   ├── operation.h           # Abstract base
│   ├── opAdd*, opDelete, opCopy, opPaste, opResize, opRotate ...
├── GUI/                      # GUI rendering layer
├── CMUgraphicsLib/           # Graphics library
└── images/MenuIcons/         # UI icon assets
```

---

## Key Concepts Demonstrated

- Abstract classes, virtual functions, and runtime polymorphism
- Command/Operation pattern for extensible action handling
- MVC separation: GUI renders, Controller decides, Shapes hold data
- File I/O for save/load functionality
- Event-driven GUI programming

---

## License

MIT License
