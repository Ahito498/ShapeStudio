#pragma once
#include "operation.h"
#include "../Shapes/Shape.h"
#include "../Shapes/Graph.h"
#include "../controller.h"
#include "../GUI/GUI.h"
#include <iostream>

class opResize : public operation {
private:
    double ratio = 1;

public:
    opResize(controller* pcont);
    virtual ~opResize();
    virtual void Execute();

};