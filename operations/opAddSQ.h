#pragma once
#include "operation.h"

//Add Square operation class
class opAddSQ : public operation
{
public:
    opAddSQ(controller* pCont);
    virtual ~opAddSQ();

    //Add Square to the controller
    virtual void Execute();

};
