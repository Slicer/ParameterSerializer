# For build tree configuration.
set( ${PROJECT_NAME}_INCLUDE_DIRS ${${PROJECT_NAME}_BUILD_INCLUDE_DIRS} )
list( APPEND ${PROJECT_NAME}_INCLUDE_DIRS
  ${JsonCpp_INCLUDE_DIR}
  ${ITK_INCLUDE_DIRS}
  )
export( TARGETS ${${PROJECT_NAME}_LIBRARY}
  FILE "${PROJECT_BINARY_DIR}/${PROJECT_NAME}Targets.cmake" )
set( ${PROJECT_NAME}_LIBRARIES ${${PROJECT_NAME}_LIBRARY} )
configure_file( "${PROJECT_SOURCE_DIR}/cmake/${PROJECT_NAME}Config.cmake.in"
  "${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
  @ONLY )

# For install configuration.
# TODO
