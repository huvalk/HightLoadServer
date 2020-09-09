cmake_minimum_required( VERSION 3.10 )
project( highload )

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
#set( EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin )

find_package( Boost 1.65 REQUIRED COMPONENTS system filesystem thread regex)
include_directories( SYSTEM ${Boost_INCLUDE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/include )

add_executable( highload main.cpp src/ConfigParser.cpp src/Config.cpp
        src/Server.cpp src/Client.cpp src/ResponseProcessor.cpp src/RequestProcessor.cpp)

target_link_libraries(${CMAKE_PROJECT_NAME} ${Boost_LIBRARIES})