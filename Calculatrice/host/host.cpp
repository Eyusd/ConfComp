// Copyright (c) Open Enclave SDK contributors.
// Licensed under the MIT License.
#include <openenclave/host.h>
#include <iostream>

// Include the untrusted helloworld header that is generated
// during the build. This file is generated by calling the
// sdk tool oeedger8r against the helloworld.edl file.
#include "calc_u.h"

int main(int argc, const char* argv[])
{
    oe_result_t result;
    int ret = 1;
    oe_enclave_t* enclave = NULL;

    uint32_t flags = OE_ENCLAVE_FLAG_DEBUG;
    char op[256];
    double* res;

    if (argc != 2)
    {
        fprintf(
            stderr, "Usage: %s enclave_image_path [ --simulate  ]\n", argv[0]);
        goto exit;
    }

    // Create the enclave
    result = oe_create_calc_enclave(
        argv[1], OE_ENCLAVE_TYPE_AUTO, flags, NULL, 0, &enclave);
    if (result != OE_OK)
    {
        fprintf(
            stderr,
            "oe_create_enclave(): result=%u (%s)\n",
            result,
            oe_result_str(result));
        goto exit;
    }

    // Call into the enclave
    printf("Entre une operation : ");
    std::cin.getline(op, 256);

    result = enclave_parser(enclave, op, res);
    if (result != OE_OK)
    {
        fprintf(
            stderr,
            "calling into enclave failed: result=%u (%s)\n",
            result,
            oe_result_str(result));
        goto exit;
    }

    fprintf(stderr, "%lf", *res);

    ret = 0;

exit:
    // Clean up the enclave if we created one
    if (enclave)
        oe_terminate_enclave(enclave);

    return ret;
}
