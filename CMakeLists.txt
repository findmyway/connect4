CMAKE_MINIMUM_REQUIRED(VERSION 3.1)
PROJECT(CONNECT4)
SET(CONNECT4_VERSION_MAJOR 0)
SET(CONNECT4_VERSION_MINOR 9)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC --std=c++11 -W -Wall -O3 -DNDEBUG")

SET(C4_CORE_FILES
    Solver.cpp
    Solver.hpp
    Position.hpp
    TranspositionTable.hpp
    OpeningBook.hpp
    MoveSorter.hpp
)

ADD_LIBRARY(c4_core OBJECT ${C4_CORE_FILES})

ADD_EXECUTABLE(c4solver
    main.cpp)

ADD_EXECUTABLE(c4generator
        generator.cpp)

TARGET_LINK_LIBRARIES(c4solver c4_core)
TARGET_LINK_LIBRARIES(c4generator c4_core)

INSTALL(TARGETS c4_core DESTINATION lib)
INSTALL(TARGETS c4generator DESTINATION bin)
INSTALL(TARGETS c4solver DESTINATION bin)

add_subdirectory(julia_wrapper)