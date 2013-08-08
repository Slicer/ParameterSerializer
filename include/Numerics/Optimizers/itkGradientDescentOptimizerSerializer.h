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
#ifndef __itkGradientDescentOptimizerSerializer_h
#define __itkGradientDescentOptimizerSerializer_h

#include "itkObjectFactory.h"

#include "itkBoolValue.h"
#include "itkDoubleValue.h"
#include "itkIntegerValue.h"
#include "itkUnsignedIntegerValue.h"
#include "itkObjectSerializer.h"

namespace itk
{

/** \class GradientDescentOptimizerSerializer
 *
 * \brief Parameter serializer for GradientDescentOptimizer.
 *
 * \sa GradientDescentOptimizer
 *
 */
class GradientDescentOptimizerSerializer:
  public ObjectSerializer
{
public:
  /** Standard class typedefs. */
  typedef GradientDescentOptimizerSerializer Self;
  typedef ParameterSerializer                Superclass;
  typedef SmartPointer< Self >               Pointer;
  typedef SmartPointer< const Self >         ConstPointer;

  /** Method for creation through the object factory. */
  itkNewMacro( Self );

  /** Run-time type information (and related methods). */
  itkTypeMacro( GradientDescentOptimizerSerializer, ObjectSerializer );

  virtual void Serialize();
  virtual void DeSerialize();

protected:
  GradientDescentOptimizerSerializer();
  virtual ~GradientDescentOptimizerSerializer();

  BoolValue *            m_Maximize;
  DoubleValue *          m_LearningRate;
  UnsignedIntegerValue * m_NumberOfIterations;

private:
  GradientDescentOptimizerSerializer( const Self & );
  void operator=( const Self & ); // purposely not implemented
};

} // end namespace itk

#ifndef ITK_MANUAL_INSTANTIATION
#include "itkGradientDescentOptimizerSerializer.hxx"
#endif

#endif
