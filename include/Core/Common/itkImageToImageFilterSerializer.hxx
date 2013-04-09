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
#ifndef __itkImageToImageFilterSerializer_hxx
#define __itkImageToImageFilterSerializer_hxx

namespace itk
{

template< class TImageToImageFilter >
ImageToImageFilterSerializer< TImageToImageFilter >
::ImageToImageFilterSerializer()
{
  this->m_CoordinateTolerance = new DoubleValue;
  this->m_CoordinateTolerance->SetValue( 1.0 );
  this->m_Parameters["CoordinateTolerance"] = this->m_CoordinateTolerance;

  this->m_DirectionTolerance = new DoubleValue;
  this->m_DirectionTolerance->SetValue( 1.0 );
  this->m_Parameters["DirectionTolerance"] = this->m_DirectionTolerance;
}


template< class TImageToImageFilter >
ImageToImageFilterSerializer< TImageToImageFilter >
::~ImageToImageFilterSerializer()
{
  delete m_CoordinateTolerance;
  delete m_DirectionTolerance;
}


template< class TImageToImageFilter >
void
ImageToImageFilterSerializer< TImageToImageFilter >
::Serialize()
{
  ImageToImageFilterType * filter =
    dynamic_cast< ImageToImageFilterType * >
      ( this->GetTargetObject() );
  if( filter == NULL )
    {
    itkWarningMacro("ImageToImageFilterSerializer target object not set");
    }
  else
    {
    this->m_CoordinateTolerance->SetValue( filter->GetCoordinateTolerance() );
    this->m_Parameters["CoordinateTolerance"] = this->m_CoordinateTolerance;

    this->m_DirectionTolerance->SetValue( filter->GetDirectionTolerance() );
    this->m_Parameters["DirectionTolerance"] = this->m_DirectionTolerance;
    }

  Superclass::Serialize();
}


template< class TImageToImageFilter >
void
ImageToImageFilterSerializer< TImageToImageFilter >
::DeSerialize()
{
  Superclass::DeSerialize();

  ImageToImageFilterType * filter =
    dynamic_cast< ImageToImageFilterType * >
      ( this->GetTargetObject() );
  if( filter != NULL )
    {
    filter->SetCoordinateTolerance( this->m_CoordinateTolerance->GetValue() );
    filter->SetDirectionTolerance( this->m_DirectionTolerance->GetValue() );
    }
}

} // end namespace itk

#endif
