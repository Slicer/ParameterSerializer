set( ImageGradientSerializerTests
  itkGradientMagnitudeRecursiveGaussionImageFilterSerializerTest.cxx
  )

CreateTestDriver( ImageGradientSerializer "${${PROJECT_NAME}_LIBRARIES}"
  ${ImageGradientSerializerTests} )

add_test( NAME itkGradientMagnitudeRecursiveGaussionImageFilterSerializerTest
  COMMAND ImageGradientSerializerTestDriver
  itkGradientMagnitudeRecursiveGaussionImageFilterSerializerTest
  ${TEMP}/itkGradientMagnitudeRecursiveGaussionImageFilterSerializerTest )
