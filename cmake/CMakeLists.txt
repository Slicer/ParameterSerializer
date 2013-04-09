# For build tree configuration.
set( ${PROJECT_NAME}_INCLUDE_DIRS ${${PROJECT_NAME}_BUILD_INCLUDE_DIRS} )
configure_file( "${PROJECT_SOURCE_DIR}/cmake/${PROJECT_NAME}Config.cmake.in"
  "${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake" )

# For install configuration.
# TODO
