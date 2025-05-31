#ifndef OPSELECT_H
#define OPSELECT_H

#include "operation.h"
#include "../Shapes/Shape.h"
#include "../Shapes/Graph.h"
#include "../controller.h"
#include "../GUI/GUI.h"
#include <iostream>

class opselect : public operation {
private:
    shape* selectedShape;

public:
    opselect(controller* pCont);
    virtual ~opselect();

    // Execute the select operation
    virtual void Execute();
};

#endif // OPSELECT_H
