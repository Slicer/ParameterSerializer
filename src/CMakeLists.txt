set( ${PROJECT_NAME}_SRCS
  itkJsonCppArchiver.cxx
  itkParameterArchiver.cxx
  itkParameterSerializer.cxx
  )

add_library( ${PROJECT_NAME}Lib
  ${${PROJECT_NAME}_SRCS}
  )
target_link_libraries( ${PROJECT_NAME}Lib
  ${ITK_LIBRARIES}
  ${JsonCpp_LIBRARIES}
  )

set( ${PROJECT_NAME}_LIBRARIES ${PROJECT_NAME}Lib CACHE INTERNAL
  "Project libraries" )
