#pragma once
#include "operation.h"

class opCHNGfillColor : public operation
{
public:
    opCHNGfillColor(controller* pCont);
    virtual ~opCHNGfillColor();

    //Add Square to the controller
    virtual void Execute();

};
