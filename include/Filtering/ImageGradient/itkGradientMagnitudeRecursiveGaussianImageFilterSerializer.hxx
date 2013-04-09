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
#ifndef __itkGradientMagnitudeRecursiveGaussianImageFilterSerializer_hxx
#define __itkGradientMagnitudeRecursiveGaussianImageFilterSerializer_hxx

#include "itkGradientMagnitudeRecursiveGaussianImageFilterSerializer.h"

namespace itk
{

template< class TGradientMagnitudeRecursiveGaussianImageFilter >
GradientMagnitudeRecursiveGaussianImageFilterSerializer< TGradientMagnitudeRecursiveGaussianImageFilter >
::GradientMagnitudeRecursiveGaussianImageFilterSerializer()
{
  this->m_Sigma = new DoubleValue;
  this->m_Sigma->SetValue( 1.0 );
  this->m_Parameters["Sigma"] = this->m_Sigma;

  this->m_NormalizeAcrossScale = new BoolValue;
  this->m_NormalizeAcrossScale->SetValue( false );
  this->m_Parameters["NormalizeAcrossScale"] = this->m_NormalizeAcrossScale;
}


template< class TGradientMagnitudeRecursiveGaussianImageFilter >
GradientMagnitudeRecursiveGaussianImageFilterSerializer< TGradientMagnitudeRecursiveGaussianImageFilter >
::~GradientMagnitudeRecursiveGaussianImageFilterSerializer()
{
  delete m_Sigma;
  delete m_NormalizeAcrossScale;
}


template< class TGradientMagnitudeRecursiveGaussianImageFilter >
void
GradientMagnitudeRecursiveGaussianImageFilterSerializer< TGradientMagnitudeRecursiveGaussianImageFilter >
::Serialize()
{
  GradientMagnitudeRecursiveGaussianImageFilterType * filter =
    dynamic_cast< GradientMagnitudeRecursiveGaussianImageFilterType * >
      ( this->GetTargetObject() );
  if( filter == NULL )
    {
    itkWarningMacro("GradientMagnitudeRecursiveGaussianImageFilterSerializer target object not set");
    }
  else
    {
    this->m_Sigma->SetValue( filter->GetSigma() );
    this->m_Parameters["Sigma"] = this->m_Sigma;

    this->m_NormalizeAcrossScale->SetValue( filter->GetNormalizeAcrossScale() );
    this->m_Parameters["NormalizeAcrossScale"] = this->m_NormalizeAcrossScale;
    }

  Superclass::Serialize();
}


template< class TGradientMagnitudeRecursiveGaussianImageFilter >
void
GradientMagnitudeRecursiveGaussianImageFilterSerializer< TGradientMagnitudeRecursiveGaussianImageFilter >
::DeSerialize()
{
  Superclass::DeSerialize();

  GradientMagnitudeRecursiveGaussianImageFilterType * filter =
    dynamic_cast< GradientMagnitudeRecursiveGaussianImageFilterType * >
      ( this->GetTargetObject() );

  if( filter != NULL )
    {
    filter->SetSigma( this->m_Sigma->GetValue() );
    filter->SetNormalizeAcrossScale( this->m_NormalizeAcrossScale->GetValue() );
    }
}

} // end namespace itk

#endif
