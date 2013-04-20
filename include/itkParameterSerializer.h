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
#ifndef __itkParameterSerializer_h
#define __itkParameterSerializer_h

#include "itkObject.h"
#include "itkObjectFactory.h"

#include "itkParameterArchiver.h"
#include "itkParameterValue.h"
#include "ParameterSerializerExport.h"

namespace itk
{

/** \class ParameterSerializer
 *
 * \brief Serialize and deserialize the parameters associated with an object.
 *
 * This is a base class for performing serialization and deserialization of the
 * "parameters" of another class. The "parameters" of another class are usually
 * the members that can be changed with public Set/Get methods.
 *
 * The parameters are deflated or inflated by the associated ParameterArchiver.
 * The archiver is responsible for writing and reading the parameter data
 * to/from a specific format, e.g. Json, HDF5, etc.
 *
 * The object whose parameters are to be serialized or deserialized is set with
 * the \c SetTargetObject method.
 *
 * Derived classes should have members corresponding with the parameters they
 * want to serialize.  The default values for these parameters should be set
 * in the constructor.  They should override the \c Serialize() and
 * \c DeSerialize() methods.  The \c Serialize method should set the
 * internal ParameterValue's from the TargetObject and then call
 * Superclass::Serialize().  The \c DeSerialize method should call
 * Superclass::DeSerialize(), then set parameters on the TargetObject from the
 * internal ParameterValues.
 *
 * \sa ParameterArchiver
 */
class ParameterSerializer_EXPORT ParameterSerializer: public Object
{
public:
  /** Standard class typedefs. */
  typedef ParameterSerializer        Self;
  typedef Object                     Superclass;
  typedef SmartPointer< Self >       Pointer;
  typedef SmartPointer< const Self > ConstPointer;

  /** Run-time type information (and related methods). */
  itkTypeMacro( ParameterSerializer, Object );

  /** Standard New macro. */
  itkNewMacro( Self );

  /** Type of the archiver.  The archiver writes the parameter data to a
   * specific format, e.g. Json, HDF5, etc. */
  typedef ParameterArchiver                 ArchiverType;
  typedef ParameterArchiver::ParametersType ParametersType;

  /** Set/Get the archiver.  The default Archiver is a JsonCpp archiver. */
  itkSetObjectMacro( Archiver, ArchiverType );
  itkGetObjectMacro( Archiver, ArchiverType );

  /** Set/Get the target object whose parameters this class is
   * serializing/deserializing. */
  itkSetObjectMacro( TargetObject, LightObject );
  itkGetObjectMacro( TargetObject, LightObject );

  /** Serialize the parameters to the archive. */
  virtual void Serialize();

  /** Deserialize the parameters from an archive. */
  virtual void DeSerialize();

protected:
  ParameterSerializer();
  virtual ~ParameterSerializer();

  void PrintSelf( std::ostream & os, Indent indent ) const;

  ParametersType m_Parameters;

private:
  ParameterSerializer( const Self & ); // purposely not implemented
  void operator=( const Self & ); // purposely not implemented

  ArchiverType::Pointer m_Archiver;
  LightObject::Pointer  m_TargetObject;
};

} // end namespace itk

#endif
