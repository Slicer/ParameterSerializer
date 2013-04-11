# For build tree configuration.
set( ${PROJECT_NAME}_INCLUDE_DIRS ${${PROJECT_NAME}_BUILD_INCLUDE_DIRS} )
get_target_property( ${PROJECT_NAME}_LIBRARY_FULL_PATH ${${PROJECT_NAME}_LIBRARY} LOCATION )
set( ${PROJECT_NAME}_LIBRARIES ${${PROJECT_NAME}_LIBRARY_FULL_PATH} ${ITK_LIBRARIES} ${JsonCpp_LIBRARIES} )
configure_file( "${PROJECT_SOURCE_DIR}/cmake/${PROJECT_NAME}Config.cmake.in"
  "${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake" )

# For install configuration.
# TODO
