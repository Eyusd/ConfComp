project(Calculette)
cmake_minimum_required(VERSION 3.18)
find_package(OpenEnclave CONFIG REQUIRED)

# Trusted bindings for the enclave
add_custom_command(OUTPUT calc_t.h calc_t.c calc.h
  DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/calc.edl
  COMMAND openenclave::oeedger8r --trusted ${CMAKE_CURRENT_SOURCE_DIR}/calc.edl)

# Untrusted bindings for the host
add_custom_command(OUTPUT calc_u.h calc_u.c calc.h
  DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/calc.edl
  COMMAND openenclave::oeedger8r --untrusted ${CMAKE_CURRENT_SOURCE_DIR}/calc.edl)

add_executable(example_enclave calc.cpp calc_t.c)
target_link_libraries(example_enclave openenclave::oeenclave openenclave::oelibcxx)

# NOTE: This is a self-signed certificate only for demonstration.
add_custom_command(OUTPUT private.pem public.pem
  COMMAND openssl genrsa -out private.pem -3 3072
  COMMAND openssl rsa -in private.pem -pubout -out public.pem)

add_custom_command(OUTPUT example_enclave.signed
  DEPENDS example_enclave calc.conf private.pem
  COMMAND openenclave::oesign sign -e $<TARGET_FILE:example_enclave> -c ${CMAKE_CURRENT_SOURCE_DIR}/calc.conf -k private.pem)

add_custom_target(signed_example_enclave ALL
  DEPENDS example_enclave.signed)

add_executable(example_host host.cpp calc_u.c)
target_link_libraries(example_host openenclave::oehost)