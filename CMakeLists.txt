cmake_minimum_required( VERSION 3.16.3 )

project( ParameterSerializer )

if( NOT CMAKE_CXX_STANDARD )
  set( CMAKE_CXX_STANDARD 17 )
endif()
if( NOT CMAKE_CXX_STANDARD MATCHES "^(17|20|23)$" )
  message( FATAL_ERROR "CMAKE_CXX_STANDARD must be set to 17, 20, or 23" )
endif()
set( CMAKE_CXX_STANDARD_REQUIRED ON )
set( CMAKE_CXX_EXTENSIONS OFF )

set( CMAKE_MODULE_PATH ${${PROJECT_NAME}_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH} )

find_package( ITK 5.4 REQUIRED
  COMPONENTS ITKCommon
  OPTIONAL_COMPONENTS ITKImageGradient ITKOptimizers
  )
if( ITK_INTERFACE_LIBRARIES )
  set( ${PROJECT_NAME}_ITK_LIBRARIES ${ITK_INTERFACE_LIBRARIES} )
else()
  include( ${ITK_USE_FILE} )
  set( ${PROJECT_NAME}_ITK_LIBRARIES ${ITK_LIBRARIES} )
endif()

if( EXISTS ${JsonCpp_DIR}/JsonCppConfig.cmake )
  # Use the more reliable JsonCppConfig.cmake.
  find_package( JsonCpp REQUIRED CONFIG )
else()
  find_package( JsonCpp REQUIRED )
endif()
include_directories( ${JsonCpp_INCLUDE_DIRS} )


if( NOT CMAKE_RUNTIME_OUTPUT_DIRECTORY )
  set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${${PROJECT_NAME}_BINARY_DIR}/bin )
endif()
if( NOT CMAKE_LIBRARY_OUTPUT_DIRECTORY )
  set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${${PROJECT_NAME}_BINARY_DIR}/lib )
endif()
if( NOT CMAKE_ARCHIVE_OUTPUT_DIRECTORY )
  set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${${PROJECT_NAME}_BINARY_DIR}/lib )
endif()

if( UNIX )
  set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-strict-aliasing"
    CACHE STRING "Flags used by all build types." FORCE )
  set( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fno-strict-aliasing"
    CACHE STRING "Flags used by all build types." FORCE )
  if( ${CMAKE_SIZEOF_VOID_P} EQUAL 8 )
    set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC"
         CACHE STRING "Flags used by all build types." FORCE )
    set( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC"
         CACHE STRING "Flags used by all build types." FORCE )
  endif( ${CMAKE_SIZEOF_VOID_P} EQUAL 8 )
endif( UNIX )

# Implementation agnostic fPIC
set( CMAKE_POSITION_INDEPENDENT_CODE ON )

# These will be populated by the subdirectory CMakeLists.txt.
set( ${PROJECT_NAME}_BUILD_INCLUDE_DIRS "${${PROJECT_NAME}_BINARY_DIR}/include" CACHE INTERNAL
  "Build directories with project headers.")
set( ${PROJECT_NAME}_LIBRARIES "" CACHE INTERNAL
  "Project libraries" )

add_subdirectory( include )

include_directories( include
  "${${PROJECT_NAME}_BINARY_DIR}/include"
  include/Core/Common
  include/Filtering/ImageGradient
  include/Numerics/Optimizers )
add_subdirectory( src )

include( CTest )
if( BUILD_TESTING )
  add_subdirectory( test )
endif()

add_subdirectory( cmake )
