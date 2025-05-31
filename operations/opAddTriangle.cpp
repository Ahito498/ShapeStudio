#include "opAddTriangle.h"
#include "..\shapes\Triangle.h"

#include "..\controller.h"
#include "..\GUI\GUI.h"

opAddTriangle::opAddTriangle(controller* pCont) : operation(pCont)
{}
opAddTriangle::~opAddTriangle()
{}

// Execute the operation
void opAddTriangle::Execute()
{
    Point P1, P2, P3;

    // Get a Pointer to the Input / Output Interfaces
    GUI* pUI = pControl->GetUI();

    pUI->PrintMessage("New Triangle: Click at first vertex");
    // Read 1st vertex and store in point P1
    pUI->GetPointClicked(P1.x, P1.y);

    string msg = "First vertex is at (" + to_string(P1.x) + ", " + to_string(P1.y) + " )";
    msg += " ... Click at second vertex";
    pUI->PrintMessage(msg);
    // Read 2nd vertex and store in point P2
    pUI->GetPointClicked(P2.x, P2.y);

    msg = "Second vertex is at (" + to_string(P2.x) + ", " + to_string(P2.y) + " )";
    msg += " ... Click at third vertex";
    pUI->PrintMessage(msg);
 
    // Read 3rd vertex and store in point P3
    pUI->GetPointClicked(P3.x, P3.y);
    msg += "  Enter the thickness of the shape";
    pUI->ClearStatusBar();
    pUI->PrintMessage(msg);

    // Prepare all triangle parameters
    GfxInfo TriangleGfxInfo;

    // Get drawing, filling colors and pen width from the interface
    TriangleGfxInfo.DrawClr = pUI->getCrntDrawColor();
    TriangleGfxInfo.FillClr = pUI->getCrntFillColor();
    TriangleGfxInfo.BorderWdth = pUI->getCrntPenWidth();

    TriangleGfxInfo.isFilled = pUI->getFill(); // default is not filled
    TriangleGfxInfo.isSelected = false; // default is not selected
    string x = pUI->GetSrting();
    int y = stoi(x); // convert string to int
    // Create a triangle with the above parameters
  
    Triangle* T = new Triangle(P1, P2, P3, TriangleGfxInfo,y);

    // Get a pointer to the graph
    Graph* pGr = pControl->getGraph();

    // Add the triangle to the list of shapes
    pGr->Addshape(T);
}
