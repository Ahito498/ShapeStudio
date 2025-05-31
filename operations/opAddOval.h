#pragma once
#include "operation.h"

class opAddOval : public operation
{
public:
    opAddOval(controller* pCont);
    virtual ~opAddOval();

    // Execute the operation
    virtual void Execute();

};

