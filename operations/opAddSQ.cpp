#include "opAddSQ.h"
#include "..\shapes\Square.h"
#include "..\controller.h"
#include "..\GUI\GUI.h"
#include <iostream> // For std::cerr
#include <stdexcept> // For std::invalid_argument and std::out_of_range

opAddSQ::opAddSQ(controller* pCont) :operation(pCont)
{}
opAddSQ::~opAddSQ()
{}

//Execute the operation
void opAddSQ::Execute()
{
    Point P1, P2;

    //Get a Pointer to the Input / Output Interfaces
    GUI* pUI = pControl->GetUI();

    pUI->PrintMessage("New Square: Click at first vertex");
    //Read 1st vertex and store in point P1
    pUI->GetPointClicked(P1.x, P1.y);

    string msg = "First vertex is at (" + to_string(P1.x) + ", " + to_string(P1.y) + " )";
    msg += " ... Click at second vertex";
    pUI->PrintMessage(msg);
    //Read 2nd vertex and store in point P2
    pUI->GetPointClicked(P2.x, P2.y);
    msg += "  Enter the thickness of the shape";
    pUI->ClearStatusBar();
    pUI->PrintMessage(msg);

    //Prepare all Square parameters
    GfxInfo SQGfxInfo;

    //get drawing, filling colors and pen width from the interface
    SQGfxInfo.DrawClr = pUI->getCrntDrawColor();
    SQGfxInfo.FillClr = pUI->getCrntFillColor();
    SQGfxInfo.BorderWdth = pUI->getCrntPenWidth();

    SQGfxInfo.isFilled = pUI->getFill();	//default is not filled
    SQGfxInfo.isSelected = false;	//default is not selected

    int thickness = 1; // Default thickness
    while (true)
    {
        try
        {
            string x = pUI->GetSrting();
            thickness = stoi(x); // convert string to int
            if (thickness <= 0)
            {
                pUI->PrintMessage("Thickness must be positive. Please enter again:");
                continue;
            }
            break; // Exit loop if conversion is successful and valid
        }
        catch (const std::invalid_argument& e)
        {
            pUI->PrintMessage("Invalid input. Please enter a numeric value:");
        }
        catch (const std::out_of_range& e)
        {
            pUI->PrintMessage("Input is out of range. Please enter a smaller value:");
        }
    }

    //Create a Square with the above parameters
    SQ* S = new SQ(P1, P2, SQGfxInfo, thickness);

    //Get a pointer to the graph
    Graph* pGr = pControl->getGraph();

    //Add the Square to the list of shapes
    pGr->Addshape(S);
}
