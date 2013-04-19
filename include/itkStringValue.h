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
#ifndef __itkStringValue_h
#define __itkStringValue_h

#include "itkParameterValue.h"

namespace itk
{

/**
 * \class StringValue
 *
 * \brief Holds the value of a STRING ParameterValueType.
 *
 * \sa ParameterValue
 * */
class ITK_EXPORT StringValue: public ParameterValue
{
public:
  StringValue()
    {
    this->m_ValueType = STRING;
    }

  std::string GetValue() const
    {
    return m_String;
    }

  void SetValue( const std::string & value )
    {
    m_String = value;
    }

private:
  std::string m_String;
};

} // end namespace itk

#endif
