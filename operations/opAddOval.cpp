#include "opAddOval.h"
#include "..\shapes\Oval.h"

#include "..\controller.h"
#include "..\GUI\GUI.h"

opAddOval::opAddOval(controller* pCont) : operation(pCont)
{}
opAddOval::~opAddOval()
{}

// Execute the operation
void opAddOval::Execute()
{
    Point P1, P2;

    // Get a Pointer to the Input / Output Interfaces
    GUI* pUI = pControl->GetUI();

    pUI->PrintMessage("New Oval: Click at first point");
    // Read 1st point and store in point P1
    pUI->GetPointClicked(P1.x, P1.y);

    string msg = "First point is at (" + to_string(P1.x) + ", " + to_string(P1.y) + " )";
    msg += " ... Click at second point";
    pUI->PrintMessage(msg);
    // Read 2nd point and store in point P2
    pUI->GetPointClicked(P2.x, P2.y);
    pUI->ClearStatusBar();

    // Prepare all oval parameters
    GfxInfo OvalGfxInfo;

    // Get drawing, filling colors and pen width from the interface
    OvalGfxInfo.DrawClr = pUI->getCrntDrawColor();
    OvalGfxInfo.FillClr = pUI->getCrntFillColor();
    pUI->PrintMessage("Enter Pen width:");
    OvalGfxInfo.BorderWdth = pUI->getCrntPenWidth();

    OvalGfxInfo.isFilled = pUI->getFill();
    OvalGfxInfo.isSelected = false; // default is not selected
    string x = pUI->GetSrting();
    int y = stoi(x); // convert string to int
    // Create an oval with the above parameters
    Oval* O = new Oval(P1, P2, OvalGfxInfo,y);

    // Get a pointer to the graph
    Graph* pGr = pControl->getGraph();

    // Add the oval to the list of shapes
    pGr->Addshape(O);
}
