cmake_minimum_required(VERSION 3.28)
project(Dynavl)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Incluir diretórios
include_directories(include)

# Fontes principais (sem main.cpp!)
file(GLOB_RECURSE PROJECT_SOURCES "src/*.cpp")

# Criar o executável principal (agora incluindo main.cpp)
add_executable(${PROJECT_NAME} ${PROJECT_SOURCES} main.cpp)

# ========== Parte opcional para Testes ==========

option(BUILD_TESTS "Build unit tests" OFF)

if(BUILD_TESTS)
    enable_testing()

    find_package(GTest REQUIRED)

    add_definitions(-DTEST_MODE)

    file(GLOB_RECURSE TEST_SOURCES "test/*.cpp")

    # Criar o executável de testes (sem main.cpp)
    add_executable(${PROJECT_NAME}Tests ${TEST_SOURCES} ${PROJECT_SOURCES})

    target_link_libraries(${PROJECT_NAME}Tests GTest::GTest GTest::Main pthread)

    add_test(NAME DynavlTests COMMAND ${PROJECT_NAME}Tests)
endif()
