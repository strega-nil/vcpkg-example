cmake_minimum_required(VERSION 3.14)

project(vcpkg-example CXX)

add_executable(vcpkg-example src/main.cxx)

find_package(fmt CONFIG REQUIRED)
find_package(ZLIB REQUIRED)

target_link_libraries(vcpkg-example
  PRIVATE
    fmt::fmt
    ZLIB::ZLIB)
