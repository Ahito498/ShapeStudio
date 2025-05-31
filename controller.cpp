#include "controller.h"
#include "operations\opAddRect.h"
#include "operations\opAddLine.h"
#include "operations\opAddCircle.h"
#include "operations\opAddTriangle.h"
#include "operations\opAddSQ.h"
#include "operations\opAddHexagon.h"
#include "operations\opAddOval.h"
#include "operations/opCHNGdrawColor.h"
#include "operations/CHNGfillColor.h"
#include "operations/opselect.h"
#include "operations/opDelete.h"
#include "operations/opRotate.h"
#include "operations/opResize.h"
#include "operations/opCopy.h"
#include "operations/opPaste.h"
//Constructor
controller::controller()
{
	pGraph = new Graph;
	pGUI = new GUI;	//Create GUI object
}

//==================================================================================//
//								operations-Related Functions							//
//==================================================================================//
operationType controller::GetUseroperation() const
{
	//Ask the input to get the operation from the user.
	return pGUI->GetUseroperation();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an operation and executes it
operation* controller::createOperation(operationType OpType)
{
	operation* pOp = nullptr;
	
	//According to operation Type, create the corresponding operation object
	switch (OpType)
	{
		case DRAW_RECT:
			pOp = new opAddRect(this);
			break;

		case DRAW_LINE:
			pOp = new opAddLine(this);
			break;
        case DRAW_CIRC :
            pOp = new opAddCircle(this);
            break;
        case DRAW_TRI:
            pOp = new opAddTriangle(this);
            break;
        case DRAW_SQ:
            pOp = new opAddSQ(this);
            break;
        case DRAW_HEX:
            pOp = new opAddPolygon(this);
            break;
        case Draw_OVAL:
            pOp = new opAddOval(this);
            break;
        case CHNG_DRAW_CLR:
            pOp = new opCHNGdrawColor(this);//***************************
            break;
        case CHNG_FILL_CLR:
            pOp = new opCHNGfillColor(this);
            break;
        case SELECT:
            pOp = new opselect (this);
            break;
        case DEL:
            pOp = new opDelete(this);
            break;
        case ROTATE:
            pOp = new opRotate(this);
            break;
        case RESIZE:
            pOp = new opResize(this);
            break;
        case COPY:
            pOp = new opCopy(this);
            break;
        case PASTE:
            pOp = new opPaste(this);
            break;
		case EXIT:
			///create Exitoperation here
			
			break;
		
		case STATUS:	//a click on the status bar ==> no operation
			break;
	}

	return pOp;
	
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all shapes on the user interface
void controller::UpdateInterface() const
{	
	pGraph->Draw(pGUI);
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the UI
GUI *controller::GetUI() const
{	return pGUI; }
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the Graph
Graph* controller::getGraph() const
{
	return pGraph;
}



//Destructor
controller::~controller()
{
	delete pGUI;
	delete pGraph;
	
}



//==================================================================================//
//							Run function											//
//==================================================================================//
void controller::Run()
{
	operationType OpType;
	do
	{
		//1. Ask the GUI to read the required operation from the user
		OpType = GetUseroperation();

		//2. Create an operation coresspondingly
		operation* pOpr = createOperation(OpType);
		 
		//3. Execute the created operation
		if (pOpr)
		{
			pOpr->Execute();//Execute
			delete pOpr;	//operation is not needed any more ==> delete it
			pOpr = nullptr;
		}

		//Update the interface
		UpdateInterface();

	} while (OpType != EXIT);

}