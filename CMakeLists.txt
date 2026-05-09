cmake_minimum_required(VERSION 3.15)
project(DLLTemplate LANGUAGES CXX)

# 1. Set C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# 2. Set C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 3. Define the library
add_library(my_library SHARED src/vcmgr.cpp)

# 4. Include directories
target_include_directories(my_library PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# 5. Preprocessor definition to trigger __declspec(dllexport)
target_compile_definitions(my_library PRIVATE EXPORTING_DLL)

# 6. Link necessary Windows system libraries (e.g., kernel32)
# target_link_libraries(my_library kernel32) <- ts is optional 