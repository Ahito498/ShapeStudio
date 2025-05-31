#include "operation.h"

class opAddTriangle : public operation
{
public:
    opAddTriangle(controller* pCont);
    virtual ~opAddTriangle();

    // Execute the operation
    virtual void Execute();
};