find_package(LLVM REQUIRED CONFIG)

separate_arguments(LLVM_DEFINITION_LIST NATIVE_COMMAND ${LLVM_DEFINITIONS})
add_definitions(${LLVM_DEFINITION_LIST})
include_directories(${LLVM_INCLUDE_DIRS})
list(APPEND CMAKE_MODULE_PATH "${LLVM_CMAKE_DIR}")
include(AddLLVM)

add_llvm_library(NumOpCodes MODULE
    NumOpCodes.cpp
    PLUGIN_TOOL
    opt
    )
