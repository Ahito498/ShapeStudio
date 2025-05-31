#include "opPaste.h"
#include"..\Shapes\Graph.h"
#include"..\controller.h"
#include"..\operations\operation.h"

opPaste::opPaste(controller* pCont) :operation(pCont){}

opPaste::~opPaste(){}
void opPaste::Execute()
{
    GUI* pUI = pControl->GetUI();
    Graph* pGph = pControl->getGraph();

    shape** copiedShapeList = pGph->GetCopiedShapesList();
    int CopyCount = pGph->GetCopyCount();
   
    if (CopyCount == 0)
    {
        pUI->PrintMessage("NO shapes to paste!");
    }
    else {
        pUI->PrintMessage("Click on the Place that you want to paste in: ");/////ask forlocation that I want to paste in
    }
        Point pastepoint;
        pUI->GetPointClicked(pastepoint.x, pastepoint.y);


    for (int i = 0; i < CopyCount;i++)
    {
        if (copiedShapeList[i] != nullptr)
        {
            shape* newShape = copiedShapeList[i]->Duplicate();
            newShape->Move(pastepoint.x,pastepoint.y);
            pGph->Addshape(newShape);
            pUI->PrintMessage("Shape has been pasted!");
            pGph->Draw(pUI);
        }
    }
}
