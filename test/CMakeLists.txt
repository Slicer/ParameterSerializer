# Utility macro: add_subdirectory if the corresponding module is enabled
# when ITK was built.
macro( add_subdirectory_if_module_enabled _dir )
  list( FIND ITK_MODULES_ENABLED ITK${_dir} _have )

  if( NOT ${_have} EQUAL "-1" )
    add_subdirectory( ${_dir} )
  endif()
endmacro()

# Create source code, compile and link a test driver
# Two variables must be defined before including this file.
#   KIT should define a unique name for the test driver.
#   KitTests should contain a list of test file names.
# Arguments - Input
#   KIT - the name of the test directory
#   KIT_LIBS - a list of libraries needed to link the test driver
#   KitTests - a list of tests to be included in the test driver
macro(CreateTestDriver KIT KIT_LIBS KitTests)
  set(CMAKE_TESTDRIVER_BEFORE_TESTMAIN "#include \"itkTestDriverBeforeTest.inc\"")
  set(CMAKE_TESTDRIVER_AFTER_TESTMAIN "#include \"itkTestDriverAfterTest.inc\"")
  create_test_sourcelist(Tests ${KIT}TestDriver.cxx
    ${KitTests}
    EXTRA_INCLUDE itkTestDriverIncludeRequiredIOFactories.h
    FUNCTION  ProcessArgumentsAndRegisterRequiredFactories
    )
  add_executable(${KIT}TestDriver ${KIT}TestDriver.cxx ${Tests})
  target_link_libraries(${KIT}TestDriver ${KIT_LIBS} ${ITKTestKernel_LIBRARIES})
endmacro()
set( TEMP ${PROJECT_BINARY_DIR}/Testing/Temporary )

add_subdirectory( Filtering )
