/*=========================================================================

Library:   TubeTK

Copyright 2010 Kitware Inc. 28 Corporate Drive,
Clifton Park, NY, 12065, USA.

All rights reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

=========================================================================*/
#include "itkGradientDescentOptimizerSerializer.h"

#include "itkJsonCppArchiver.h"

#include "itkGradientDescentOptimizer.h"

int itkGradientDescentOptimizerSerializerTest( int argc, char * argv[] )
{
  if( argc < 2 )
    {
    std::cerr << "Usage: "
              << argv[0]
              << " archiveFileName"
              << std::endl;
    return EXIT_FAILURE;
    }
  const char * archiveFileName = argv[1];

  // Create an GradientDescentOptimizer
  typedef itk::GradientDescentOptimizer GradientDescentOptimizerType;
  GradientDescentOptimizerType::Pointer gradientDescentOptimizer =
    GradientDescentOptimizerType::New();

  typedef itk::GradientDescentOptimizerSerializer SerializerType;
  SerializerType::Pointer serializer = SerializerType::New();

  gradientDescentOptimizer->SetDebug( true );
  gradientDescentOptimizer->SetMaximize( true );
  gradientDescentOptimizer->SetLearningRate( 0.8 );
  gradientDescentOptimizer->SetNumberOfIterations( 44 );
  GradientDescentOptimizerType::ScalesType scales( 3 );
  scales[0] = 33.3;
  scales[1] = 45.3;
  scales[2] = 98.4;
  gradientDescentOptimizer->SetScales( scales );
  GradientDescentOptimizerType::ParametersType initialPosition( 3 );
  initialPosition[0] = 33.3;
  initialPosition[1] = 45.3;
  initialPosition[2] = 98.4;
  gradientDescentOptimizer->SetInitialPosition( initialPosition );
  serializer->SetTargetObject( gradientDescentOptimizer );
  serializer->Serialize();

  std::cout << serializer << std::endl;

  itk::JsonCppArchiver::Pointer archiver =
    dynamic_cast< itk::JsonCppArchiver * >( serializer->GetArchiver() );
  archiver->WriteToFile( archiveFileName );

  archiver->ReadFromFile( archiveFileName );
  gradientDescentOptimizer->SetLearningRate( 0.2 );
  gradientDescentOptimizer->SetNumberOfIterations( 99 );
  scales[0] = -23.3;
  scales[1] = -55.3;
  scales[2] = -88.4;
  gradientDescentOptimizer->SetScales( scales );
  serializer->DeSerialize();
  if( gradientDescentOptimizer->GetDebug() != true ||
      gradientDescentOptimizer->GetMaximize() != true ||
      gradientDescentOptimizer->GetLearningRate() != 0.8 ||
      gradientDescentOptimizer->GetNumberOfIterations() != 44 ||
      gradientDescentOptimizer->GetScales()[0] != 33.3 ||
      gradientDescentOptimizer->GetInitialPosition()[0] != 33.3 )
    {
    std::cerr << "DeSerialization did not occur correctly: "
      << gradientDescentOptimizer << std::endl;
    return EXIT_FAILURE;
    }

  std::ostringstream oStream;
  archiver->WriteToStdStream( oStream );

  std::istringstream iStream( oStream.str() );
  archiver->ReadFromStdStream( iStream );

  std::cout << "Writing to std::cout: " << std::endl;
  archiver->WriteToStdStream( std::cout );

  return EXIT_SUCCESS;
}
