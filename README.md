# ShapeStudio

A C++ graphics application for drawing and manipulating various shapes. This project provides a user-friendly interface for creating, editing, and managing different geometric shapes with various operations.

## Features

- Draw multiple types of shapes:
  - Lines
  - Rectangles
  - Triangles
  - Circles
  - Squares
  - Ovals
  - Hexagons

- Shape Operations:
  - Draw shapes
  - Change drawing color
  - Change fill color
  - Change background color
  - Delete shapes
  - Move shapes
  - Resize shapes
  - Rotate shapes
  - Send shapes to back/front
  - Copy and paste shapes
  - Save/Load functionality

## Project Structure

```
ShapeStudio/
├── CMUgraphicsLib/     # Graphics library
├── GUI/                # User interface components
├── Shapes/            # Shape classes
│   ├── Circle.cpp/h
│   ├── Graph.cpp/h
│   ├── Hexagon.cpp/h
│   ├── Line.cpp/h
│   ├── Oval.cpp/h
│   ├── Rect.cpp/h
│   ├── Shape.cpp/h
│   ├── Square.cpp/h
│   └── Triangle.cpp/h
├── operations/        # Operation handling
└── main.cpp          # Program entry point
```

## Requirements

- C++ compiler with C++11 support
- CMU Graphics Library (included)
- Visual Studio (for Windows users)

## Building the Project

### Using Visual Studio:
1. Open `CIE202-project.sln` in Visual Studio
2. Build the solution (Ctrl + Shift + B)
3. Run the program (F5)

## Usage

1. Launch the application
2. Use the toolbar to select different operations
3. Click on the drawing area to create shapes
4. Use the various tools to modify and manipulate shapes
5. Save your work using the save functionality

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Contributing

1. Fork the repository
2. Create your feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

## Authors

- Hassan Rashwan 