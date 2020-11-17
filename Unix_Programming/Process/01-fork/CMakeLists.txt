cmake_minimum_required( VERSION 3.16 )
project(fork)
aux_source_directory(. SRCS)
set( CMAKE_CXX_STANDARD 11 )
set( TARGET main )

add_executable(${TARGET} ${SRCS})

set_target_properties(${TARGET} PROPERTIES
        COMPILE_FLAGS "-pthread"
        LINK_FLAGS "-pthread")

#target_link_libraries(${TARGET} pthread)

