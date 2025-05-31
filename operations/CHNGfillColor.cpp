#include "CHNGfillColor.h"
#include "..\controller.h"

#include "..\GUI\GUI.h"

opCHNGfillColor::opCHNGfillColor(controller* pCont) :operation(pCont)
{}
opCHNGfillColor::~opCHNGfillColor()
{}

void opCHNGfillColor::Execute()
{
    GUI* pUI = pControl->GetUI();   //pControl pointer used to access the UI and save it in the pUI pointer
    color newcolorf = pUI->GetPalet();   //Dislay the color palette to let the user select a color
    
       
    
    pUI->SetCurrentFillColor(newcolorf);
    pUI->setFill(true);
    pUI->PrintMessage("Filling mode is ON: Color Changed successfully.");
    }
    
    
