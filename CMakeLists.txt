cmake_minimum_required(VERSION 3.21)
project(aoc C CXX)

set(CMAKE_CXX_STANDARD 17)

set(SHARED_SRC utils/io.cpp)

file(GLOB DAYS CONFIGURE_DEPENDS "day*")
foreach(DAY_PATH ${DAYS})
    get_filename_component(DAY "${DAY_PATH}" NAME)

    file(GLOB PARTS CONFIGURE_DEPENDS "${DAY}/*.cpp")
    foreach(PART_PATH ${PARTS})
        get_filename_component(PART "${PART_PATH}" NAME_WLE)
        add_executable("${DAY}${PART}" ${DAY}/${PART}.cpp ${SHARED_SRC})
    endforeach(PART_PATH)
endforeach(DAY_PATH)
