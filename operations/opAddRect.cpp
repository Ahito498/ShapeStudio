#include "opAddRect.h"
#include "..\shapes\Rect.h"

#include "..\controller.h"

#include "..\GUI\GUI.h"

opAddRect::opAddRect(controller * pCont):operation(pCont)
{}
opAddRect::~opAddRect()
{} 

//Execute the operation
void opAddRect::Execute() 
{
	Point P1, P2;

	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage("New Rectangle: Click at first corner");
	//Read 1st corner and store in point P1
	pUI->GetPointClicked(P1.x, P1.y);

	string msg = "First corner is at (" + to_string(P1.x) + ", " + to_string(P1.y) + " )";
	msg += " ... Click at second corner";
	pUI->PrintMessage(msg);
	//Read 2nd corner and store in point P2
	pUI->GetPointClicked(P2.x, P2.y);
    msg += "  Enter the thickness of the shape";
    pUI->ClearStatusBar();
    pUI->PrintMessage(msg);

	//Preapre all rectangle parameters
	GfxInfo RectGfxInfo;
	
	//get drawing, filling colors and pen width from the interface
    RectGfxInfo.isFilled = pUI->getFill();	//default is not filled
	RectGfxInfo.isSelected = false;	//defualt is not selected
	RectGfxInfo.DrawClr = pUI->getCrntDrawColor();
	RectGfxInfo.FillClr = pUI->getCrntFillColor();
	RectGfxInfo.BorderWdth = pUI->getCrntPenWidth();


    string x = pUI->GetSrting();
    int y = stoi(x); // convert string to int
    // Create a line with the above parameters

	//Create a rectangle with the above parameters
	Rect *R=new Rect(P1, P2, RectGfxInfo,y);

	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	//Add the rectangle to the list of shapes
	pGr->Addshape(R);

}
