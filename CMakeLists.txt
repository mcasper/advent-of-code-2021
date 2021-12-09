cmake_minimum_required(VERSION 3.21)
project(aoc C CXX)

set(CMAKE_CXX_STANDARD 17)

set(SHARED_SRC utils/io.cpp utils/string_scanner.cpp)

file(GLOB DAYS CONFIGURE_DEPENDS "day*")
foreach(DAY_PATH ${DAYS})
    get_filename_component(DAY "${DAY_PATH}" NAME)

    file(GLOB PARTS CONFIGURE_DEPENDS "${DAY}/*.cpp")
    foreach(PART_PATH ${PARTS})
        get_filename_component(PART "${PART_PATH}" NAME_WLE)
        add_executable("${DAY}${PART}" main.cpp ${DAY}/${PART}.cpp ${SHARED_SRC})
    endforeach(PART_PATH)
endforeach(DAY_PATH)

## Tests

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()
include(GoogleTest)

foreach(DAY_PATH ${DAYS})
    get_filename_component(DAY "${DAY_PATH}" NAME)

    file(GLOB PARTS CONFIGURE_DEPENDS "${DAY}/*.cpp")
    foreach(PART_PATH ${PARTS})
        get_filename_component(PART "${PART_PATH}" NAME_WLE)
        add_executable("${DAY}${PART}_test" ${DAY}/${PART}.cpp ${SHARED_SRC})
        target_compile_definitions("${DAY}${PART}_test" PUBLIC MY_TEST)
        target_link_libraries("${DAY}${PART}_test" gtest_main)
        gtest_discover_tests("${DAY}${PART}_test")
    endforeach(PART_PATH)
endforeach(DAY_PATH)

add_executable(utils_tests utils/string_scanner_tests.cpp utils/string_scanner.cpp utils/io.cpp utils/io_tests.cpp)
target_link_libraries(utils_tests gtest_main)
gtest_discover_tests(utils_tests)
