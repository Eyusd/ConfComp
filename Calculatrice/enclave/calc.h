#ifndef DEF_DISPATCHER
#define DEF_DISPATCHER

#include <openenclave/enclave.h>

#define MAX_CHAR 100
typedef char string[MAX_CHAR+1];

class ecall_dispatcher
{
    public:
        double parser(string str);
};

#endif