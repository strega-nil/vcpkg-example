cmake_minimum_required(VERSION 3.14)

project(vcpkg-example CXX)

set(A ${VCPKG_TARGET_TRIPLET})
set(VCPKG_TARGET_TRIPLET ${VCPKG_TARGET_TRIPLET} --debug)
vcpkg_install_packages()
set(VCPKG_TARGET_TRIPLET ${A})

add_executable(vcpkg-example src/main.cxx)

find_package(fmt CONFIG REQUIRED)
find_package(cppitertools CONFIG REQUIRED)

target_link_libraries(vcpkg-example
  PRIVATE
    fmt::fmt
    cppitertools::cppitertools)
