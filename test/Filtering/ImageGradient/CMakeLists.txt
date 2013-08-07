set( ImageGradientSerializerTests
  itkGradientMagnitudeRecursiveGaussianImageFilterSerializerTest.cxx
  )

CreateTestDriver( ImageGradientSerializer "${${PROJECT_NAME}_LIBRARIES}"
  ${ImageGradientSerializerTests} )

add_test( NAME itkGradientMagnitudeRecursiveGaussianImageFilterSerializerTest
  COMMAND ImageGradientSerializerTestDriver
  itkGradientMagnitudeRecursiveGaussianImageFilterSerializerTest
  ${TEMP}/itkGradientMagnitudeRecursiveGaussianImageFilterSerializerTest )
