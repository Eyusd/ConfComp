#include "guess.h"
#include <stdio.h>
#include <openenclave/enclave.h>

void ecall_dispatcher::initialize(uint8_t max_value)
{
    oe_result_t result;
    result = oe_random(&m_secret_number, sizeof(m_secret_number));
    m_secret_number = m_secret_number % max_value;
    fprintf(stdout, "Number : %d\n ", m_secret_number);
}

bool ecall_dispatcher::guess(uint8_t input)
{
    return (input == m_secret_number);
}