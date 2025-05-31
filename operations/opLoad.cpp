//#include "opLoad.h"
//#include <fstream>
//#include "..\shapes\shape.h"
//#include "..\controller.h"
//#include "..\GUI\GUI.h"
//#include "../Shapes\circle.h"
//#include "../Shapes\Line.h"
//#include "../Shapes\Rect.h"
//#include "../Shapes\Oval.h"
//#include "../Shapes\Square.h"
//#include "../Shapes\Triangle.h"
//#include "../Shapes\Hexagon.h"
//
//shape* opLoad::CreateShape(string shapeType) {
//
//    shape* opLoad::CreateShape(string shapeType) {
//        if (shapeType == "Circle") {
//            return new Circle();
//        }
//        else if (shapeType == "Rectangle") {
//            return new Rect();
//        }
//        else if (shapeType == "Triangle") {
//            return new Triangle();
//        }
//        else if (shapeType == "Line") {
//            return new Line();
//        }
//        else if (shapeType == "Square") {
//            return new SQ();
//        }
//        else if (shapeType == "Polygon") {
//            return new polygon();
//        }
//        else if (shapeType == "Oval") {
//            return new Oval();
//        }
//        else {
//            return nullptr;
//        }
//    }
//
//
//// Execute the save operation
//void opLoad::Execute()
//{
//    ifstream inputfile;
//    int shapeCount;
//    string drawColorStr, fillColorStr, shapeData;
//
//
//    // Get a pointer to the input/output interfaces
//    GUI* pUI = pControl->GetUI();
//
//    // Get a pointer to the graph
//    Graph* pGr = pControl->getGraph();
//
//    // Ask the user for the filename
//    pUI->PrintMessage("Enter filename to load: ");
//    string filename = pUI->GetSrting();
//    filename += ".txt";
//    inputfile.open(filename);
//
//    if (inputfile.fail()) {
//        pUI->PrintMessage("Failed to open file.");
//        return;
//    }
//    // Read and set the current draw and fill colors
//
//    //std::ifstream inputFile(inputfile);
//    if (!inputfile.is_open()) {
//        pUI->PrintMessage("Unable to open file");
//    }
//    string msg = filename + " file loaded Succesfully.";
//    pUI->PrintMessage(msg);
//    std::getline(inputfile, drawColorStr, ')');
//    drawColorStr += ')'; // Append the closing parenthesis
//    std::getline(inputfile, fillColorStr, ')');
//    fillColorStr += ')'; // Append the closing parenthesis
//
//    // Move the input file stream position past the space between the two color strings
//    inputfile.ignore(1);
//
//    pUI->SetCrntDrawColor(pUI->parseColor(drawColorStr));
//    pUI->SetCrntFillColor(pUI->parseColor(fillColorStr));
//    cout << drawColorStr << " " << fillColorStr << endl;
//
//    inputfile >> shapeCount;
//    cout << shapeCount << endl;
//    std::string shapeType;
//
//    // Read each shape's data and create the corresponding shape
//    for (int i = 0; i < shapeCount; ++i) {
//
//        inputfile >> shapeType;
//        cout << shapeType << endl;
//        shape* newShape = CreateShape(shapeType);
//        // Read the rest of the line containing the shape data
//
//        std::getline(inputfile, shapeData);
//
//        if (newShape) {
//            newShape->Load(shapeData);
//            pGr->Addshape(newShape);
//        }
//    }
//    inputfile.close();
//
//    //pGr->Load(inputfile);
//
//
//
//}
//
