#include "opAddCircle.h"
#include "..\shapes\Circle.h"
#include "..\controller.h"
#include "..\GUI\GUI.h"

opAddCircle::opAddCircle(controller* pCont) : operation(pCont)
{}
opAddCircle::~opAddCircle()
{}

// Execute the operation
void opAddCircle::Execute()
{
    Point center;
    int radius;

    // Get a Pointer to the Input / Output Interfaces
    GUI* pUI = pControl->GetUI();

    pUI->PrintMessage("New Circle: Click at center point");
    // Read center point and store in point center
    pUI->GetPointClicked(center.x, center.y);

    string msg = "Center point is at (" + to_string(center.x) + ", " + to_string(center.y) + " )";
    msg += " ... Click at a point on the circumference";
    pUI->PrintMessage(msg);
    // Read a point on the circumference and store in point P2
    Point circumference;
    pUI->GetPointClicked(circumference.x, circumference.y);
    msg += "  Enter the thickness of the shape";
    pUI->ClearStatusBar();
    pUI->PrintMessage(msg);

    // Calculate the radius
    radius = sqrt(pow(circumference.x - center.x, 2) + pow(circumference.y - center.y, 2));

    // Prepare all circle parameters
    GfxInfo CircleGfxInfo;

    // Get drawing, filling colors and pen width from the interface
    CircleGfxInfo.DrawClr = pUI->getCrntDrawColor();
    CircleGfxInfo.FillClr = pUI->getCrntFillColor();
    CircleGfxInfo.BorderWdth = pUI->getCrntPenWidth();

    CircleGfxInfo.isFilled = pUI->getFill();
    CircleGfxInfo.isSelected = false; // default is not selected
    string x = pUI->GetSrting();
    int y = stoi(x); // convert string to int
    // Create a circle with the above parameters
    Circle* C = new Circle(center, radius, CircleGfxInfo,y);

    // Get a pointer to the graph
    Graph* pGr = pControl->getGraph();

    // Add the circle to the list of shapes
    pGr->Addshape(C);
}
