add_library(gol board.cpp cell.cpp)
target_link_libraries(gol PUBLIC cxx_setup)

add_subdirectory(tests)
