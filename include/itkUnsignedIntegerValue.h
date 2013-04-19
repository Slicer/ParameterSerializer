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
#ifndef __itkUnsignedIntegerValue_h
#define __itkUnsignedIntegerValue_h

#include "itkIntTypes.h"

#include "itkParameterValue.h"

namespace itk
{

/**
 * \class UnsignedIntegerValue
 *
 * \brief Holds the value of a UNSIGNED_INTEGER ParameterValueType.
 *
 * \sa ParameterValue
 * */
class ITK_EXPORT UnsignedIntegerValue: public ParameterValue
{
public:
  typedef itk::uint64_t UIntType;

  UnsignedIntegerValue()
    {
    this->m_ValueType = UNSIGNED_INTEGER;
    }

  UIntType GetValue() const
    {
    return m_UnsignedInteger;
    }

  void SetValue( UIntType value )
    {
    m_UnsignedInteger = value;
    }

private:
  UIntType m_UnsignedInteger;
};

} // end namespace itk

#endif
