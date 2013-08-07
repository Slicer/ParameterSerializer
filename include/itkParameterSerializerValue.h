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
#ifndef __itkParameterSerializerValue_h
#define __itkParameterSerializerValue_h

#include "itkParameterValue.h"
#include "itkParameterSerializer.h"

namespace itk
{

/**
 * \class ParameterSerializerValue
 *
 * \brief Holds the value of a PARAMETER_SERIALIZER ParameterValueType.
 *
 * \sa ParameterValue
 * */
class ParameterSerializerValue: public ParameterValue
{
public:
  ParameterSerializerValue()
    {
    this->m_ValueType = PARAMETER_SERIALIZER;
    }

  ParameterSerializer * GetValue() const
    {
    return m_ParameterSerializer.GetPointer();
    }

  void SetValue( ParameterSerializer * serializer )
    {
    m_ParameterSerializer = serializer;
    }

private:
  ParameterSerializer::Pointer m_ParameterSerializer;
};

} // end namespace itk

#endif
