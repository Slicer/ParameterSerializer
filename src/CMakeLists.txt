set( ${PROJECT_NAME}_SRCS
  itkJsonCppArchiver.cxx
  itkParameterArchiver.cxx
  itkParameterSerializer.cxx
  Core/Common/itkObjectSerializer.cxx
  )

# Utility macro: add sources if the corresponding module is enabled
# when ITK was built.
macro( add_sources_if_module_enabled _dir _sources )
  list( FIND ITK_MODULES_ENABLED ITK${_dir} _have )
  if( NOT ${_have} EQUAL "-1" )
    list( APPEND ${PROJECT_NAME}_SRCS ${_sources} )
  endif()
endmacro()

add_sources_if_module_enabled( Optimizers
  Numerics/Optimizers/itkOptimizerSerializer.cxx
  )


add_library( ${PROJECT_NAME}Lib
  ${${PROJECT_NAME}_SRCS}
  )
target_link_libraries( ${PROJECT_NAME}Lib
  ${ITK_LIBRARIES}
  ${JsonCpp_LIBRARIES}
  )
include( GenerateExportHeader )
generate_export_header( ${PROJECT_NAME}Lib
  BASE_NAME ${PROJECT_NAME}
  EXPORT_MACRO_NAME ${PROJECT_NAME}_EXPORT
  EXPORT_FILE_NAME ../include/${PROJECT_NAME}Export.h
  STATIC_DEFINE ${PROJECT_NAME}_STATIC
  )

set( ${PROJECT_NAME}_LIBRARY ${PROJECT_NAME}Lib CACHE INTERNAL
  "${PROJECT_NAME} library" )

list( APPEND ${PROJECT_NAME}_LIBRARIES
  ${${PROJECT_NAME}_LIBRARY}
  ${ITK_LIBRARIES}
  ${JsonCpp_LIBRARIES}
  )
set( ${PROJECT_NAME}_LIBRARIES ${${PROJECT_NAME}_LIBRARIES} CACHE INTERNAL
  "${PROJECT_NAME} libraries" )
