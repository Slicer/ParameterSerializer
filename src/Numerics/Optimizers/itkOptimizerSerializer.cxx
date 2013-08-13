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
#include "itkOptimizerSerializer.h"

namespace itk
{

OptimizerSerializer
::OptimizerSerializer()
{
  this->m_Scales = new DoubleArrayValue;
  this->m_Parameters["Scales"] = this->m_Scales;

  this->m_InitialPosition = new DoubleArrayValue;
  this->m_Parameters["InitialPosition"] = this->m_InitialPosition;
}


OptimizerSerializer
::~OptimizerSerializer()
{
  delete m_Scales;
  delete m_InitialPosition;
}


void
OptimizerSerializer
::Serialize()
{
  Optimizer * object =
    dynamic_cast< Optimizer * >
      ( this->GetTargetObject() );
  if( object == NULL )
    {
    itkWarningMacro("OptimizerSerializer target object not set");
    }
  else
    {
    const Optimizer::ScalesType & targetScales = object->GetScales();
    DoubleArrayValue::DoubleArrayType & theseScales =
      this->m_Scales->GetModifiableValue();
    theseScales.resize( targetScales.Size() );
    for( size_t ii = 0; ii < targetScales.size(); ++ii )
      {
      theseScales[ii] = targetScales[ii];
      }
    this->m_Parameters["Scales"] = this->m_Scales;

    const Optimizer::ParametersType & targetInitialPosition = object->GetInitialPosition();
    DoubleArrayValue::DoubleArrayType & theseInitialPosition =
      this->m_InitialPosition->GetModifiableValue();
    theseInitialPosition.resize( targetInitialPosition.Size() );
    for( size_t ii = 0; ii < targetInitialPosition.size(); ++ii )
      {
      theseInitialPosition[ii] = targetInitialPosition[ii];
      }
    this->m_Parameters["InitialPosition"] = this->m_InitialPosition;
    }

  Superclass::Serialize();
}


void
OptimizerSerializer
::DeSerialize()
{
  Superclass::DeSerialize();

  Optimizer * object =
    dynamic_cast< Optimizer * >
      ( this->GetTargetObject() );
  if( object != NULL )
    {
    const DoubleArrayValue::DoubleArrayType & theseScales =
      this->m_Scales->GetValue();
    Optimizer::ScalesType targetScales( theseScales.size() );
    for( size_t ii = 0; ii < targetScales.size(); ++ii )
      {
      targetScales[ii] = theseScales[ii];
      }
    object->SetScales( targetScales );

    const DoubleArrayValue::DoubleArrayType & theseInitialPosition =
      this->m_InitialPosition->GetValue();
    Optimizer::ParametersType targetInitialPosition( theseInitialPosition.size() );
    for( size_t ii = 0; ii < targetInitialPosition.size(); ++ii )
      {
      targetInitialPosition[ii] = theseInitialPosition[ii];
      }
    object->SetInitialPosition( targetInitialPosition );
    }
}

} // end namespace itk
