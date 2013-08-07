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
#ifndef __itkGradientDescentOptimizerSerializer_hxx
#define __itkGradientDescentOptimizerSerializer_hxx

#include "itkGradientDescentOptimizer.h"

namespace itk
{

GradientDescentOptimizerSerializer
::GradientDescentOptimizerSerializer()
{
  this->m_Maximize = new BoolValue;
  this->m_Maximize->SetValue( false );
  this->m_Parameters["Maximize"] = this->m_Maximize;

  this->m_LearningRate = new DoubleValue;
  this->m_LearningRate->SetValue( 1.0 );
  this->m_Parameters["LearningRate"] = this->m_LearningRate;

  this->m_NumberOfIterations = new UnsignedIntegerValue;
  this->m_NumberOfIterations->SetValue( 0 );
  this->m_Parameters["NumberOfIterations"] = this->m_NumberOfIterations;
}


GradientDescentOptimizerSerializer
::~GradientDescentOptimizerSerializer()
{
  delete m_Maximize;
  delete m_LearningRate;
  delete m_NumberOfIterations;
}


void
GradientDescentOptimizerSerializer
::Serialize()
{
  GradientDescentOptimizer * filter =
    dynamic_cast< GradientDescentOptimizer * >
      ( this->GetTargetObject() );
  if( filter == NULL )
    {
    itkWarningMacro("GradientDescentOptimizerSerializer target object not set");
    }
  else
    {
    this->m_Maximize->SetValue( filter->GetMaximize() );
    this->m_Parameters["Maximize"] = this->m_Maximize;

    this->m_LearningRate->SetValue( filter->GetLearningRate() );
    this->m_Parameters["LearningRate"] = this->m_LearningRate;

    this->m_NumberOfIterations->SetValue( filter->GetNumberOfIterations() );
    this->m_Parameters["NumberOfIterations"] = this->m_NumberOfIterations;
    }

  Superclass::Serialize();
}


void
GradientDescentOptimizerSerializer
::DeSerialize()
{
  Superclass::DeSerialize();

  GradientDescentOptimizer * filter =
    dynamic_cast< GradientDescentOptimizer * >
      ( this->GetTargetObject() );
  if( filter != NULL )
    {
    filter->SetMaximize( this->m_Maximize->GetValue() );
    filter->SetLearningRate( this->m_LearningRate->GetValue() );
    filter->SetNumberOfIterations( this->m_NumberOfIterations->GetValue() );
    }
}

} // end namespace itk

#endif
