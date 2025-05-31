#include "opselect.h"
#include "../Shapes/Shape.h"
#include "../Shapes/Graph.h"
#include "../controller.h"
#include "../GUI/GUI.h"
#include <iostream>

opselect::opselect(controller* pCont) :operation(pCont), selectedShape(nullptr)
{}
opselect::~opselect()
{}

void opselect::Execute() {
    GUI* pGUI = pControl->GetUI();
    Graph* pGraph = pControl->getGraph();
    Point P;


    pGUI->PrintMessage("Select");
    pGUI->GetPointClicked(P.x, P.y);
    pGUI->ClearStatusBar();

    selectedShape = pGraph->Getshape(P.x, P.y);

    if (selectedShape != nullptr) {
       // pControl->setSelectedShape(selectedShape);
        selectedShape->SetSelected(true);
       /* selectedShape->ChngDrawClr(DARKRED);*/
        pGUI->PrintMessage(" selected");
    }
    else {
        /*pControl->setSelectedShape(nullptr);*/
        selectedShape = nullptr;
        pGUI->PrintMessage("No shape is selected");
    }


}