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
#ifndef __itkIntegerArrayValue_h
#define __itkIntegerArrayValue_h

#include "itkIntTypes.h"

#include "itkParameterValue.h"

namespace itk
{

/**
 * \class IntegerArrayValue
 *
 * \brief Holds the value of a INTEGER_ARRAY ParameterValueType.
 *
 * \sa ParameterValue
 * */
class IntegerArrayValue: public ParameterValue
{
public:
  typedef itk::int64_t IntType;
  typedef std::vector< IntType > IntegerArrayType;

  IntegerArrayValue()
    {
    this->m_ValueType = INTEGER_ARRAY;
    }

  IntegerArrayType GetValue() const
    {
    return m_IntegerArray;
    }

  void SetValue( const IntegerArrayType & value )
    {
    m_IntegerArray = value;
    }

private:
  IntegerArrayType m_IntegerArray;
};

} // end namespace itk

#endif
