#include "calc_t.h"
#include "calc.h"
#include <iostream>

static ecall_dispatcher dispatcher;

void enclave_parser(char str [256], double* output)
{
    *output = dispatcher.parser(str);
}