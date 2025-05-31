#include "operation.h"

class opCHNGdrawColor : public operation
{
public:
    opCHNGdrawColor(controller* pCont);
    virtual ~opCHNGdrawColor();

    //Add Square to the controller
    virtual void Execute();

};
