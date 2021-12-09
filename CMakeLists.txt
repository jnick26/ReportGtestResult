cmake_minimum_required(VERSION 3.5)

project(GtestReportResult CXX)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
  message(
    STATUS
      "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
  file(
    DOWNLOAD
    "https://raw.githubusercontent.com/conan-io/cmake-conan/0.17.0/conan.cmake"
    "${CMAKE_BINARY_DIR}/conan.cmake"
    EXPECTED_HASH
      SHA256=3bef79da16c2e031dc429e1dac87a08b9226418b300ce004cc125a82687baeef
    TLS_VERIFY ON)
endif()

include(${CMAKE_BINARY_DIR}/conan.cmake)

conan_cmake_configure(REQUIRES fmt/6.1.2 GENERATORS cmake_find_package)

conan_cmake_configure(REQUIRES gtest/1.10.0 GENERATORS cmake_find_package)

conan_cmake_autodetect(settings)

conan_cmake_install(
  PATH_OR_REFERENCE
  .
  BUILD
  missing
  REMOTE
  conancenter
  SETTINGS
  ${settings})

find_package(GTest)

add_executable(ComponentTest ComponentTest.cpp)
target_link_libraries(ComponentTest PRIVATE GTest::gmock_main)
