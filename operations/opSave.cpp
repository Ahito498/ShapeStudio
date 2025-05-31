//#include "opSave.h"
//#include "..\shapes\shape.h"
//#include "..\controller.h"
//#include "..\GUI\GUI.h"
//#include <fstream>
//
//
//opSave::opSave(controller* pCont) : operation(pCont) {}
//opSave::~opSave() {}
//
//
//void opSave::Execute()
//{
//    
//    GUI* pUI = pControl->GetUI();
//
//   
//    Graph* pGr = pControl->getGraph();
//
//    
//    pUI->PrintMessage("Enter filename to save: ");
//    std::string filename = pUI->GetSrting();
//   
//    std::ofstream outFile(filename + ".txt");
//    if (!outFile) {
//        pUI->PrintMessage("Error opening file for writing.");
//        return;
//    }
//
//    
//    outFile << pUI->getCrntDrawColor().toString() << " " << pUI->getCrntFillColor().toString() << endl;
//    outFile << pGr->getShapeCount() << endl;
//    pGr->Save(outFile);
//
//    outFile.close();
//    pUI->PrintMessage("Data successfully saved to " + filename);
//}
