list( APPEND ${PROJECT_NAME}_BUILD_INCLUDE_DIRS
  ${CMAKE_CURRENT_SOURCE_DIR} )
set( ${PROJECT_NAME}_BUILD_INCLUDE_DIRS ${${PROJECT_NAME}_BUILD_INCLUDE_DIRS}
  CACHE INTERNAL
  "Build directories with project headers.")

# Utility macro: add_subdirectory if the corresponding module is enabled
# when ITK was built.  Also add the directory to the project
# BUILD_INCLUDE_DIRS.
macro( add_subdirectory_if_module_enabled _dir )
  list( FIND ITK_MODULES_ENABLED ITK${_dir} _have )

  if( NOT ${_have} EQUAL "-1" )
    list( APPEND ${PROJECT_NAME}_BUILD_INCLUDE_DIRS
      ${CMAKE_CURRENT_SOURCE_DIR}/${_dir} )
    set( ${PROJECT_NAME}_BUILD_INCLUDE_DIRS ${${PROJECT_NAME}_BUILD_INCLUDE_DIRS}
      CACHE INTERNAL
      "Build directories with project headers.")
    add_subdirectory( ${_dir} )
  endif()
endmacro()

add_subdirectory( Core )
add_subdirectory( Filtering )
add_subdirectory( Numerics )
