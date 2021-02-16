#ifndef DEF_DISPATCHER
#define DEF_DISPATCHER

#include <openenclave/enclave.h>
#include <string>
using namespace std;

class ecall_dispatcher
{
    public:
        double parser(string str);
};

#endif