#include "opResize.h"

opResize::opResize(controller* pcont) : operation(pcont)
{}

opResize::~opResize()
{}

void opResize::Execute()
{
    GUI* pUI = pControl->GetUI(); 
    Graph* pGph = pControl->getGraph();
    pUI->PrintMessage("enter ratio -> 0.25 or 0.5 or 2 or 4");
    ratio = stod(pUI->GetSrting());  //Convert String in the GUI to integer that application understand
    while (ratio != 0.25 && ratio != 0.5 && ratio != 2 && ratio != 4) {
        pUI->PrintMessage("error, enter ratio -> 0.25 or 0.5 or 2 or 4");
        ratio = stod(pUI->GetSrting());
    }
    shape** shapesList = pGph->GetShapesList();
    int shapeCount = pGph->GetShapeCount();


    //Resize
    for (int i = 0; i < shapeCount; i++)
    {

        if (shapesList[i] != nullptr && shapesList[i]->IsSelected())
        {
            shapesList[i]->Resize(ratio);
            pUI->PrintMessage("Size changed");
            pGph->Draw(pUI); // Redraw the shapes after resize
        }
        else
        {
            pUI->PrintMessage("No shape is selected to resize");
        }

    }

}
