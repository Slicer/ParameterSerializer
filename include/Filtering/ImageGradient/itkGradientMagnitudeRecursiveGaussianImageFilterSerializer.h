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
#ifndef __itkGradientMagnitudeRecursiveGaussianImageFilterSerializer_h
#define __itkGradientMagnitudeRecursiveGaussianImageFilterSerializer_h

#include "itkInPlaceImageFilterSerializer.h"

namespace itk
{

/** \class GradientMagnitudeRecursiveGaussianImageFilterSerializer
 *
 * \brief Parameter serializer for GradientMagnitudeRecursiveGaussianImageFilter.
 *
 * \sa ParameterSerializer
 *
 */
template< class TGradientMagnitudeRecursiveGaussianImageFilter >
class ITK_EXPORT GradientMagnitudeRecursiveGaussianImageFilterSerializer:
  public InPlaceImageFilterSerializer
    < typename TGradientMagnitudeRecursiveGaussianImageFilter::Superclass >
{
public:
  /** Standard class typedefs. */
  typedef GradientMagnitudeRecursiveGaussianImageFilterSerializer
                                        Self;
  typedef InPlaceImageFilterSerializer
    < typename TGradientMagnitudeRecursiveGaussianImageFilter::Superclass >
                                        Superclass;
  typedef SmartPointer< Self >          Pointer;
  typedef SmartPointer< const Self >    ConstPointer;

  /** Method for creation through the object factory. */
  itkNewMacro( Self );

  /** Run-time type information (and related methods). */
  itkTypeMacro( GradientMagnitudeRecursiveGaussianImageFilterSerializer,
    InPlaceImageFilterSerializer );

  typedef TGradientMagnitudeRecursiveGaussianImageFilter
    GradientMagnitudeRecursiveGaussianImageFilterType;

  virtual void Serialize();
  virtual void DeSerialize();

protected:
  GradientMagnitudeRecursiveGaussianImageFilterSerializer();
  virtual ~GradientMagnitudeRecursiveGaussianImageFilterSerializer();

  DoubleValue * m_Sigma;
  BoolValue *   m_NormalizeAcrossScale;

private:
  GradientMagnitudeRecursiveGaussianImageFilterSerializer( const Self & );
  void operator=( const Self & ); // purposely not implemented
};

} // end namespace itk

#ifndef ITK_MANUAL_INSTANTIATION
#include "itkGradientMagnitudeRecursiveGaussianImageFilterSerializer.hxx"
#endif

#endif
