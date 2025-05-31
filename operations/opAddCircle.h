#include "operation.h"

class opAddCircle : public operation
{
public:
    opAddCircle(controller* pCont);
    virtual ~opAddCircle();

    // Execute the operation
    virtual void Execute();
};
