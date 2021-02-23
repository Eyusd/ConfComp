add_custom_command(
  OUTPUT calc_u.h calc_u.c calc_args.h
  DEPENDS ${CMAKE_SOURCE_DIR}/calc.edl
  COMMAND
    openenclave::oeedger8r --untrusted ${CMAKE_SOURCE_DIR}/calc.edl
    --search-path ${OE_INCLUDEDIR} --search-path
    ${OE_INCLUDEDIR}/openenclave/edl/sgx)

add_executable(calc_host host.cpp
                               ${CMAKE_CURRENT_BINARY_DIR}/calc_u.c)

target_include_directories(
  calc_host PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR})

target_link_libraries(calc_host openenclave::oehost)