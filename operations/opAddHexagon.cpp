#include "opAddHexagon.h"
#include "..\shapes\Hexagon.h"
#include "..\controller.h"
#include "..\GUI\GUI.h"
#include <cmath>


opAddPolygon::opAddPolygon(controller* pCont) : operation(pCont)
{}

opAddPolygon::~opAddPolygon()
{}

// Execute the operation
void opAddPolygon::Execute()
{
    Point center;
    int radius;
   int numVertices;

    // Get a Pointer to the Input / Output Interfaces
    GUI* pUI = pControl->GetUI();

    pUI->PrintMessage("New Polygon: Click at center point");
    // Read center point and store in point center
    pUI->GetPointClicked(center.x, center.y);

    string msg = "Center point is at (" + to_string(center.x) + ", " + to_string(center.y) + " )";
    msg += " ... Click at a point on the circumference";
    pUI->PrintMessage(msg);
    Point circumference;
    // Read circumference point
    pUI->GetPointClicked(circumference.x, circumference.y);
    pUI->ClearStatusBar();

    // Calculate radius
    radius = sqrt(pow(circumference.x - center.x, 2) + pow(circumference.y - center.y, 2));
    pUI->PrintMessage("Enter the number of sides for the polygon: ");
    numVertices = stoi(pUI->GetSrting());


    msg = "Enter the thickness of the shape";
    pUI->PrintMessage(msg);
    pUI->ClearStatusBar();

    // Prepare all hexagon parameters
    GfxInfo PolygonGfxInfo;

    // get drawing, filling colors and pen width from the interface
    PolygonGfxInfo.isFilled = pUI->getFill();    // default is not filled
    PolygonGfxInfo.isSelected = false;           // default is not selected
    PolygonGfxInfo.DrawClr = pUI->getCrntDrawColor();
    PolygonGfxInfo.FillClr = pUI->getCrntFillColor();
    PolygonGfxInfo.BorderWdth = pUI->getCrntPenWidth();

    string x = pUI->GetSrting();
    int y = stoi(x); // convert string to int

    // Create a Polygon with the above parameters
    polygon* P = new polygon(center, radius, numVertices, PolygonGfxInfo, y);

    // Get a pointer to the graph
    Graph* pGr = pControl->getGraph();

    // Add the Polygon to the list of shapes
    pGr->Addshape(P);
}
