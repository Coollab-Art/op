cmake_minimum_required(VERSION 3.20)

set(WARNINGS_AS_ERRORS_FOR_OP OFF CACHE BOOL "ON iff you want to treat warnings as errors")

add_library(op INTERFACE)
add_library(op::op ALIAS op)
target_compile_features(op INTERFACE cxx_std_11)

if(WARNINGS_AS_ERRORS_FOR_OP)
    target_include_directories(op INTERFACE include)
else()
    target_include_directories(op SYSTEM INTERFACE include)
endif()