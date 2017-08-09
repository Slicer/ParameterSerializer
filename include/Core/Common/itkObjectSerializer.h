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
#ifndef __itkObjectSerializer_h
#define __itkObjectSerializer_h

#include "itkObjectFactory.h"

#include "itkBoolValue.h"
#include "itkStringValue.h"
#include "itkParameterSerializer.h"

namespace itk
{

/** \class ObjectSerializer
 *
 * \brief Parameter serializer for Object.
 *
 * \sa Object
 *
 */
class ObjectSerializer:
  public ParameterSerializer
{
public:
  /** Standard class typedefs. */
  typedef ObjectSerializer           Self;
  typedef ParameterSerializer        Superclass;
  typedef SmartPointer< Self >       Pointer;
  typedef SmartPointer< const Self > ConstPointer;

  /** Method for creation through the object factory. */
  itkNewMacro( Self );

  /** Run-time type information (and related methods). */
  itkTypeMacro( ObjectSerializer, ParameterSerializer );

  virtual void Serialize() ITK_OVERRIDE;
  virtual void DeSerialize() ITK_OVERRIDE;

protected:
  ObjectSerializer();
  virtual ~ObjectSerializer();

  BoolValue *   m_Debug;
  // TODO: Enable when using ITK 4.5
  StringValue * m_ObjectName;

private:
  ObjectSerializer( const Self & );
  void operator=( const Self & ); // purposely not implemented
};

} // end namespace itk

#endif
