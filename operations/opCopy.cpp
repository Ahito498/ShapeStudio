#include"opCopy.h"
#include"..\Shapes\Graph.h"
#include"..\controller.h"
#include"..\operations\operation.h"

opCopy::opCopy(controller* pCont) :operation(pCont) {}

opCopy::~opCopy(){}

void opCopy::Execute()
{
    GUI* pUI = pControl->GetUI();
    Graph* pGph = pControl->getGraph();

    shape** shapesList = pGph->GetShapesList();
    int shapeCount = pGph->GetShapeCount();
    shape** copiedShapeList= pGph->GetCopiedShapesList();

//clean the copy list
    for (int i = 0;i < 1000;i++)
    {
        copiedShapeList[i] = nullptr;
    }

    if (shapeCount == 0)
    {
        pUI->PrintMessage("No Shapes to copy!");
    }
    for (int i = 0;i < shapeCount;i++)
    {
        bool found = false;
        if (shapesList[i]->IsSelected())
        {
            copiedShapeList[i] = shapesList[i];
            pGph->SetCopyCount(copiedShapeList[i]);
            found = true;
        }
        else {
            if (found == 0) {
                pUI->PrintMessage("No shape Selected!");
            }
        }
    }
    for (int i = 0;i < shapeCount;i++)
    {
        if (copiedShapeList[i] != nullptr)
        {
            pUI->PrintMessage("Shape has been copied");
        }
    }

}
