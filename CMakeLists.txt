cmake_minimum_required(VERSION 3.14)

project(vcpkg-example CXX)

add_executable(vcpkg-example src/main.cxx)

vcpkg_install_packages()

find_package(fmt CONFIG REQUIRED)

target_link_libraries(vcpkg-example
  PRIVATE
    fmt::fmt)
