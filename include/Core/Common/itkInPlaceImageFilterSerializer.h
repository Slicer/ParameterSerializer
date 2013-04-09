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
#ifndef __itkInPlaceImageFilterSerializer_h
#define __itkInPlaceImageFilterSerializer_h

#include "itkImageToImageFilterSerializer.h"

namespace itk
{

/** \class InPlaceImageFilterSerializer
 *
 * \brief Parameter serializer for InPlaceImageFilter.
 *
 * \sa ParameterSerializer
 *
 */
template< class TInPlaceImageFilter >
class ITK_EXPORT InPlaceImageFilterSerializer:
  public ImageToImageFilterSerializer< typename TInPlaceImageFilter::Superclass >
{
public:
  /** Standard class typedefs. */
  typedef InPlaceImageFilterSerializer  Self;
  typedef ImageToImageFilterSerializer
    < typename TInPlaceImageFilter::Superclass >
                                                        Superclass;
  typedef SmartPointer< Self >                          Pointer;
  typedef SmartPointer< const Self >                    ConstPointer;

  /** Method for creation through the object factory. */
  itkNewMacro( Self );

  /** Run-time type information (and related methods). */
  itkTypeMacro( InPlaceImageFilterSerializer,
    ImageToImageFilterSerializer );

  typedef TInPlaceImageFilter InPlaceImageFilterType;

  virtual void Serialize();
  virtual void DeSerialize();

protected:
  InPlaceImageFilterSerializer();
  virtual ~InPlaceImageFilterSerializer();

  BoolValue * m_InPlace;

private:
  InPlaceImageFilterSerializer( const Self & );
  void operator=( const Self & ); // purposely not implemented
};

} // end namespace itk

#ifndef ITK_MANUAL_INSTANTIATION
#include "itkInPlaceImageFilterSerializer.hxx"
#endif

#endif
