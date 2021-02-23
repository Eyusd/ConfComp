add_custom_command(
  OUTPUT calc_t.h calc_t.c calc_args.h
  DEPENDS ${CMAKE_SOURCE_DIR}/calc.edl
  COMMAND
    openenclave::oeedger8r --trusted ${CMAKE_SOURCE_DIR}/calc.edl
    --search-path ${OE_INCLUDEDIR} --search-path
    ${OE_INCLUDEDIR}/openenclave/edl/sgx)

add_executable(enclave enc.cpp ${CMAKE_CURRENT_BINARY_DIR}/calc_t.c)

target_compile_definitions(enclave PUBLIC OE_API_VERSION=2)

target_include_directories(enclave PRIVATE ${CMAKE_CURRENT_BINARY_DIR})

#Visiblement, il faut inclure ça (merci les docs)
if (LVI_MITIGATION MATCHES ControlFlow)
  apply_lvi_mitigation(enclave)
  target_link_libraries(
    enclave openenclave::oeenclave-lvi-cfg
    openenclave::oecrypto${OE_CRYPTO_LIB}-lvi-cfg openenclave::oelibc-lvi-cfg)
else ()
  target_link_libraries(
    enclave openenclave::oeenclave openenclave::oecrypto${OE_CRYPTO_LIB}
    openenclave::oelibc)
endif ()