#include "opRotate.h"
opRotate::opRotate(controller* pCont) :operation(pCont)
{}

opRotate::~opRotate()
{}
void opRotate::Execute()
{
    GUI* pUI = pControl->GetUI();  
    Graph* pGph = pControl->getGraph();
    shape** shapesList = pGph->GetShapesList();
    int shapeCount = pGph->GetShapeCount();



    //Rotate by 90 operation
    for (int i = 0; i < shapeCount; i++)
    {

        if (shapesList[i] != nullptr && shapesList[i]->IsSelected())
        {
            shapesList[i]->Rotate();
            pUI->PrintMessage("Rotated successfully");
            pGph->Draw(pUI); // Redraw the shapes after rotation
        }
        else
        {
            pUI->PrintMessage("No shape is selected to rotate");
        }
    
    }

}