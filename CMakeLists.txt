cmake_minimum_required(VERSION 3.14)

if(NOT DEFINED VCPKG_ROOT)
	if(DEFINED ENV{VCPKG_ROOT})
		set(VCPKG_ROOT $ENV{VCPKG_ROOT} CACHE PATH "Path to vcpkg directory")
	endif()
endif()

if(DEFINED VCPKG_ROOT AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
	set(
		CMAKE_TOOLCHAIN_FILE "${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake"
		CACHE PATH "Path to vcpkg toolchain")

	if(NOT EXISTS "${CMAKE_TOOLCHAIN_FILE}")
		message(WARNING "Could not find toolchain file at ${CMAKE_TOOLCHAIN_FILE}")
		message(FATAL_ERROR "Did you specify an absolute path for VCPKG_ROOT? (${VCPKG_ROOT})")
	endif()
endif()

project(vcpkg-example CXX)

add_executable(vcpkg-example src/main.cxx)

find_package(fmt CONFIG REQUIRED)
find_package(cppitertools CONFIG REQUIRED)

target_link_libraries(vcpkg-example
  PRIVATE
    fmt::fmt
    cppitertools::cppitertools)
