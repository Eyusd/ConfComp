// Copyright (c) Open Enclave SDK contributors.
// Licensed under the MIT License.

// Include the trusted helloworld header that is generated
// during the build. This file is generated by calling the
// sdk tool oeedger8r against the helloworld.edl file.
#include <string.h>
using namespace std;
#include "calc_t.h"
#include <stdio.h>
#include "calc.h"
#include <iostream>

static ecall_dispatcher dispatcher;

// This is the function that the host calls. It prints
// a message in the enclave before calling back out to
// the host to print a message from there too.

void enclave_parser(string str, bool* output)
{
    *output = dispatcher.parser(str);
}