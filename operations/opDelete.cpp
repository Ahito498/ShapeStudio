#include "opDelete.h"

opDelete::opDelete(controller* pCont):operation(pCont)
{}

opDelete::~opDelete()
{}

void opDelete::Execute()
{

    GUI* pUI = pControl->GetUI();   //pControl pointer used to access the UI and save it in the pUI pointer
    Graph* pGph = pControl->getGraph();  //pControl pointer used to access the graph pointer.
    

    shape** shapesList = pGph->GetShapesList();
    int shapeCount = pGph->GetShapeCount();

    bool isShapeDeleted = false;
    
    for (int i = 0; i < shapeCount; i++)//delete operation
    {
        
        if (shapesList[i] != nullptr && shapesList[i]->IsSelected())
        {
            delete shapesList[i];
            shapesList[i] = nullptr;
            isShapeDeleted = true;
        }
    }

    int newshapeCount = 0;
    for (int i = 0;i < shapeCount; i++)//re-ordering the ShapeList
    {
        if (shapesList[i] != nullptr)
        {
            shapesList[newshapeCount] = shapesList[i];
            newshapeCount++;
        }
    }
    shapeCount = newshapeCount;
    pGph->UpdateShapeCount(shapeCount);

    if (isShapeDeleted == true)
    {
        pUI->PrintMessage("Selected Shape deleted successfully.");
    }
    else {
        pUI->PrintMessage("No Shape was selected to delete.");
    }
}
