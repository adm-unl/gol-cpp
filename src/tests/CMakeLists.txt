if(BUILD_TESTING)
    add_executable(gol_tests test_board.cpp test_cell.cpp)
    target_link_libraries(gol_tests PRIVATE GTest::gtest_main gol)

    include(GoogleTest)
    gtest_discover_tests(gol_tests)
endif()
