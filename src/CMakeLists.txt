cmake_minimum_required(VERSION 3.10)

project(guess)

include(FetchContent)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

FetchContent_Declare(fmt
  GIT_REPOSITORY https://github.com/fmtlib/fmt.git
  GIT_TAG master
)
FetchContent_MakeAvailable(fmt)

find_package(Threads REQUIRED) 

include_directories(include)

add_executable(guess 
    main.cpp
    service.cpp
    random_wrapper.cpp
    languages.cpp
    base64.cpp
    clear_console.cpp
)

FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
                        GIT_TAG f88fd7737de3e640c61703eb57a0fa0ce00c60cd)
FetchContent_MakeAvailable(cpr)


target_link_libraries(guess PRIVATE
    cpr::cpr
    fmt::fmt
)