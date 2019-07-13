include_directories(${PROJECT_SOURCE_DIR}/include)
add_executable(unit_test unit_test_main.cpp)

target_link_libraries(unit_test AnalyticsCore)

