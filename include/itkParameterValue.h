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
#ifndef __itkParameterValue_h
#define __itkParameterValue_h

namespace itk
{

/**
 * \class ParameterValue
 *
 * \brief Base class for parameter values.
 *
 * This is the base class for parameter values used by the ParameterSerializer
 * and ParameterArchiver classes.  These are very light weight classes.
 *
 * It defines a ParameterValueType enum that lists all available parameter value
 * types.  Its ParameterValueType is NIL.  Classes corresponding to the
 * other ParameterValueType's inherit from this class.
 *
 * \sa ParameterSerializer
 * \sa ParameterArchiver
 *
 * */
class ParameterValue
{
public:
  /** Types of parameter values. A restricted set of simple types are available so
   * that all archives can serialize and deserialize the parameter values. */
  enum ParameterValueType
    {
    NIL,
    PARAMETER_SERIALIZER,
    PARAMETER_SERIALIZER_ARRAY,
    STRING,
    STRING_ARRAY,
    BOOL,
    BOOL_ARRAY,
    INTEGER,
    INTEGER_ARRAY,
    UNSIGNED_INTEGER,
    UNSIGNED_INTEGER_ARRAY,
    FLOAT,
    FLOAT_ARRAY,
    DOUBLE,
    DOUBLE_ARRAY
    };

  ParameterValue(): m_ValueType( NIL )
    {}

  ParameterValueType GetValueType() const
    {
    return m_ValueType;
    }

protected:
  ParameterValueType m_ValueType;
};

} // end namespace itk

#endif
