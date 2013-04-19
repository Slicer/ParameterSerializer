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
#ifndef __itkBoolValue_h
#define __itkBoolValue_h

#include "itkParameterValue.h"

namespace itk
{

/**
 * \class BoolValue
 *
 * \brief Holds the value of a BOOL ParameterValueType.
 *
 * \sa ParameterValue
 * */
class ITK_EXPORT BoolValue: public ParameterValue
{
public:
  BoolValue()
    {
    this->m_ValueType = BOOL;
    }

  bool GetValue() const
    {
    return m_Bool;
    }

  void SetValue( bool value )
    {
    m_Bool = value;
    }

private:
  bool m_Bool;
};

} // end namespace itk

#endif
