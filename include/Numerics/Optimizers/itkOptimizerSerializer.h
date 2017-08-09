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
#ifndef __itkOptimizerSerializer_h
#define __itkOptimizerSerializer_h

#include "itkObjectFactory.h"

#include "itkDoubleArrayValue.h"
#include "itkObjectSerializer.h"

#include "itkOptimizer.h"

namespace itk
{

/** \class OptimizerSerializer
 *
 * \brief Parameter serializer for Optimizer.
 *
 * \sa Optimizer
 *
 */
class OptimizerSerializer:
  public ObjectSerializer
{
public:
  /** Standard class typedefs. */
  typedef OptimizerSerializer        Self;
  typedef ObjectSerializer           Superclass;
  typedef SmartPointer< Self >       Pointer;
  typedef SmartPointer< const Self > ConstPointer;

  /** Method for creation through the object factory. */
  itkNewMacro( Self );

  /** Run-time type information (and related methods). */
  itkTypeMacro( OptimizerSerializer, ObjectSerializer );

  virtual void Serialize() ITK_OVERRIDE;
  virtual void DeSerialize() ITK_OVERRIDE;

protected:
  OptimizerSerializer();
  virtual ~OptimizerSerializer();

  DoubleArrayValue * m_Scales;
  DoubleArrayValue * m_InitialPosition;

private:
  OptimizerSerializer( const Self & );
  void operator=( const Self & ); // purposely not implemented
};

} // end namespace itk

#endif
