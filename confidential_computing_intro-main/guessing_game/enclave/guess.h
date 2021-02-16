#ifndef DEF_DISPATCHER
#define DEF_DISPATCHER

#include <openenclave/enclave.h>

class ecall_dispatcher
{
    private:
        uint8_t m_secret_number;
    public:
        void initialize(uint8_t max_value);
        bool guess(uint8_t input);
};

#endif