#ifndef DEF_DISPATCHER
#define DEF_DISPATCHER
#include <string>
using namespace std;
#include <openenclave/enclave.h>

class ecall_dispatcher
{
    public:
        double parser(string str);
};

#endif