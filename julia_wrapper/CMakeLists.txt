find_package(JlCxx REQUIRED)

include_directories(${CMAKE_SOURCE_DIR})
add_library(connect4jl SHARED connect4jl.cpp $<TARGET_OBJECTS:c4_core>)
target_link_libraries(connect4jl PRIVATE JlCxx::cxxwrap_julia JlCxx::cxxwrap_julia_stl)

set_target_properties(connect4jl PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS ON
)

install(TARGETS connect4jl
    RUNTIME DESTINATION lib
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
)