#pragma once
#include "operation.h"
#include "../Shapes/Shape.h"
#include "../Shapes/Graph.h"
#include "../controller.h"
#include "../GUI/GUI.h"
#include <iostream>

class opRotate : public operation {

public:
    opRotate(controller* pCont);
    virtual ~opRotate();

    // Execute the select operation
    virtual void Execute();
};