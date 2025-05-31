#pragma once

#include "operation.h"

class opAddPolygon : public operation
{
public:
    opAddPolygon(controller* pCont);
    virtual ~opAddPolygon();
    virtual void Execute();
};
