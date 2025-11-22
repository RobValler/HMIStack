

#include "i_op.h"

class COp1 : public IOperation
{
    public:
    COp1()=default;
    ~COp1()=default;
    void process() override;
};