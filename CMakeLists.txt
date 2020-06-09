cmake_minimum_required(VERSION 3.14)

if(NOT DEFINED VCPKG_ROOT)
	if(DEFINED ENV{VCPKG_ROOT})
		set(VCPKG_ROOT $ENV{VCPKG_ROOT} CACHE PATH "Path to vcpkg directory")
	endif()
endif()

if(DEFINED VCPKG_ROOT)
	set(
		CMAKE_TOOLCHAIN_FILE "${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake"
		CACHE PATH "Path to vcpkg toolchain")

	if(NOT EXISTS "${CMAKE_TOOLCHAIN_FILE}")
		message(FATAL_ERROR "Invalid VCPKG_ROOT specified (${VCPKG_ROOT}); please specify an absolute path")
	endif()
endif()

project(vcpkg-example CXX)

add_executable(vcpkg-example src/main.cxx)

vcpkg_install_packages()

find_package(fmt CONFIG REQUIRED)
find_package(cppitertools CONFIG REQUIRED)

target_link_libraries(vcpkg-example
  PRIVATE
    fmt::fmt
    cppitertools::cppitertools)
