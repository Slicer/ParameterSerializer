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
#ifndef __itkFloatValue_h
#define __itkFloatValue_h

#include "itkParameterValue.h"

namespace itk
{

/**
 * \class FloatValue
 *
 * \brief Holds the value of a FLOAT ParameterValueType.
 *
 * \sa ParameterValue
 * */
class FloatValue: public ParameterValue
{
public:
  FloatValue()
    {
    this->m_ValueType = FLOAT;
    }

  float GetValue() const
    {
    return m_Float;
    }

  void SetValue( float value )
    {
    m_Float = value;
    }

private:
  float m_Float;
};

} // end namespace itk

#endif
