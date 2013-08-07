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
#ifndef __itkUnsignedIntegerArrayValue_h
#define __itkUnsignedIntegerArrayValue_h

#include "itkIntTypes.h"

#include "itkParameterValue.h"

namespace itk
{

/**
 * \class UnsignedIntegerArrayValue
 *
 * \brief Holds the value of a UNSIGNED_INTEGER_ARRAY ParameterValueType.
 *
 * \sa ParameterValue
 * */
class UnsignedIntegerArrayValue: public ParameterValue
{
public:
  typedef itk::uint64_t UIntType;
  typedef std::vector< UIntType > UnsignedIntegerArrayType;

  UnsignedIntegerArrayValue()
    {
    this->m_ValueType = UNSIGNED_INTEGER_ARRAY;
    }

  UnsignedIntegerArrayType GetValue() const
    {
    return m_UnsignedIntegerArray;
    }

  void SetValue( const UnsignedIntegerArrayType & value )
    {
    m_UnsignedIntegerArray = value;
    }

private:
  UnsignedIntegerArrayType m_UnsignedIntegerArray;
};

} // end namespace itk

#endif
