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
#ifndef __itkParameterSerializerArrayValue_h
#define __itkParameterSerializerArrayValue_h

#include "itkParameterValue.h"

namespace itk
{

/**
 * \class ParameterSerializerArrayValue
 *
 * \brief Holds the value of a PARAMETER_SERIALIZER_ARRAY ParameterValueType.
 *
 * \sa ParameterValue
 * */
class ParameterSerializerArrayValue: public ParameterValue
{
public:
  typedef std::vector< ParameterSerializer * > ParameterSerializerArrayType;
  typedef std::vector< ParameterSerializer::Pointer > ParameterSerializerSmartArrayType;

  ParameterSerializerArrayValue()
    {
    this->m_ValueType = PARAMETER_SERIALIZER_ARRAY;
    }

  const ParameterSerializerSmartArrayType & GetValue() const
    {
    return m_ParameterSerializerArray;
    }

  void SetValue( const ParameterSerializerArrayType & value )
    {
    m_ParameterSerializerArray.resize( value.size() );
    for( size_t ii = 0; ii < value.size(); ++ii )
      {
      m_ParameterSerializerArray[ii] = value[ii];
      }
    }

  void SetValue( const ParameterSerializerSmartArrayType & value )
    {
    m_ParameterSerializerArray.resize( value.size() );
    for( size_t ii = 0; ii < value.size(); ++ii )
      {
      m_ParameterSerializerArray[ii] = value[ii];
      }
    }

private:
  ParameterSerializerSmartArrayType m_ParameterSerializerArray;
};

} // end namespace itk

#endif
