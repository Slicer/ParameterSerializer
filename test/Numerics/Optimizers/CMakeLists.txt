set( OptimizersSerializerTests
  itkGradientDescentOptimizerSerializerTest.cxx
  )

CreateTestDriver( OptimizersSerializer "${${PROJECT_NAME}_LIBRARIES}"
  ${OptimizersSerializerTests} )

add_test( NAME itkGradientDescentOptimizerSerializerTest
  COMMAND OptimizersSerializerTestDriver
  itkGradientDescentOptimizerSerializerTest
  ${TEMP}/itkGradientDescentOptimizerSerializerTest.json )
