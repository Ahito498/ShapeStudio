#include "opCHNGdrawColor.h"
#include "..\controller.h"

#include "..\GUI\GUI.h"

opCHNGdrawColor::opCHNGdrawColor (controller* pCont) :operation(pCont)
{}
opCHNGdrawColor::~opCHNGdrawColor()
{}

void opCHNGdrawColor::Execute()
{
    GUI* pUI = pControl->GetUI();   //pControl pointer used to access the UI and save it in the pUI pointer
    color newcolor = pUI->GetPalet();   //Dislay the color palette to let the user select a color
    pUI->SetCurrentDrawColor(newcolor);
    pUI->PrintMessage("Color Changed successfully.");
}
