#pragma once
#include "operation.h"
#include "../Shapes/Shape.h"
#include "../Shapes/Graph.h"
#include "../controller.h"
#include "../GUI/GUI.h"
#include <iostream>

class opDelete : public operation {
    
public:
    opDelete(controller* pCont);
    virtual ~opDelete();

    // Execute the select operation
    virtual void Execute();
};