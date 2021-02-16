#include <string.h>
using namespace std;

#ifndef DEF_DISPATCHER
#define DEF_DISPATCHER
#include <openenclave/enclave.h>

class ecall_dispatcher
{
    public:
        double parser(string str);
};

#endif