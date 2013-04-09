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
#ifndef __itkInPlaceImageFilterSerializer_hxx
#define __itkInPlaceImageFilterSerializer_hxx

#include "itkInPlaceImageFilterSerializer.h"

namespace itk
{

template< class TInPlaceImageFilter >
InPlaceImageFilterSerializer< TInPlaceImageFilter >
::InPlaceImageFilterSerializer()
{
  this->m_InPlace = new BoolValue;
  this->m_InPlace->SetValue( true );
  this->m_Parameters["InPlace"] = this->m_InPlace;
}


template< class TInPlaceImageFilter >
InPlaceImageFilterSerializer< TInPlaceImageFilter >
::~InPlaceImageFilterSerializer()
{
  delete m_InPlace;
}


template< class TInPlaceImageFilter >
void
InPlaceImageFilterSerializer< TInPlaceImageFilter >
::Serialize()
{
  InPlaceImageFilterType * filter =
    dynamic_cast< InPlaceImageFilterType * >
      ( this->GetTargetObject() );
  if( filter == NULL )
    {
    itkWarningMacro("InPlaceImageFilterSerializer target object not set");
    }
  else
    {
    this->m_InPlace->SetValue( filter->GetInPlace() );
    this->m_Parameters["InPlace"] = this->m_InPlace;
    }

  Superclass::Serialize();
}


template< class TInPlaceImageFilter >
void
InPlaceImageFilterSerializer< TInPlaceImageFilter >
::DeSerialize()
{
  InPlaceImageFilterType * filter =
    dynamic_cast< InPlaceImageFilterType * >
      ( this->GetTargetObject() );

  Superclass::DeSerialize();

  if( filter != NULL )
    {
    filter->SetInPlace( this->m_InPlace->GetValue() );
    }
}

} // end namespace itk

#endif
