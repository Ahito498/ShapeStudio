#include "opAddLine.h"
#include "..\shapes\Line.h"
#include "..\controller.h"
#include "..\GUI\GUI.h"

opAddLine::opAddLine(controller* pCont) : operation(pCont)
{}

opAddLine::~opAddLine()
{}

// Execute the operation
void opAddLine::Execute()
{
    Point P1, P2;

    // Get a Pointer to the Input / Output Interfaces
    GUI* pUI = pControl->GetUI();

    pUI->PrintMessage("New Line: Click at first point");
    // Read 1st point and store in point P1
    pUI->GetPointClicked(P1.x, P1.y);

    string msg = "First point is at (" + to_string(P1.x) + ", " + to_string(P1.y) + " )";
    msg += " ... Click at second point";
    pUI->PrintMessage(msg);
    // Read 2nd point and store in point P2
    pUI->GetPointClicked(P2.x, P2.y);
    pUI->ClearStatusBar();
    pUI->PrintMessage(msg);


    // Prepare all line parameters
    GfxInfo LineGfxInfo;

    // Get drawing color and pen width from the interface
    LineGfxInfo.DrawClr = pUI->getCrntDrawColor();
    LineGfxInfo.FillClr = pUI->getCrntFillColor();
    pUI->PrintMessage("Enter Pen Width");
    LineGfxInfo.BorderWdth = pUI->getCrntPenWidth();

    LineGfxInfo.isFilled = false;    // default is not filled
    LineGfxInfo.isSelected = false;  // default is not selected
    string x = pUI->GetSrting();
    int y = stoi(x); // convert string to int
    // Create a line with the above parameters
    Line* L = new Line(P1, P2, LineGfxInfo,y);

    // Get a pointer to the graph
    Graph* pGr = pControl->getGraph();

    // Add the line to the list of shapes
    pGr->Addshape(L);
}
