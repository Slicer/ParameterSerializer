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
#ifndef __itkParameterArchiver_h
#define __itkParameterArchiver_h

#include "itkObject.h"

#include "itkBoolValue.h"
#include "itkBoolArrayValue.h"
#include "itkDoubleValue.h"
#include "itkDoubleArrayValue.h"
#include "itkFloatValue.h"
#include "itkFloatArrayValue.h"
#include "itkIntegerValue.h"
#include "itkIntegerArrayValue.h"
#include "itkStringValue.h"
#include "itkStringArrayValue.h"
#include "itkUnsignedIntegerValue.h"
#include "itkUnsignedIntegerArrayValue.h"
#include "ParameterSerializerExport.h"

namespace itk
{

class BoolValue;
class BoolArrayValue;
class DoubleValue;
class DoubleArrayValue;
class FloatValue;
class FloatArrayValue;
class IntegerValue;
class IntegerArrayValue;
class ParameterSerializerValue;
class ParameterSerializerArrayValue;
class StringValue;
class StringArrayValue;
class UnsignedIntegerValue;
class UnsignedIntegerArrayValue;

/** \class ParameterArchiver
 *
 * \brief Write and read ParameterSerializer data to/from an archive format.
 *
 * This class is associated with the ParameterSerializer.  It is responsible for
 * writing and reading the parameter values stored in a ParameterSerializer.
 *
 * This is an abstract base class.  Classes that inherit from it will use
 * specific formats, e.g. Json, HDF5, etc.
 *
 * Classes that inherit from this class will need to define ways to inflate
 * and deflate the ParameterSerializer::ParameterValue classes.
 *
 */
class ParameterSerializer_EXPORT ParameterArchiver: public Object
{
public:
  /** Standard class typedefs. */
  typedef ParameterArchiver          Self;
  typedef Object                     Superclass;
  typedef SmartPointer< Self >       Pointer;
  typedef SmartPointer< const Self > ConstPointer;

  /** Run-time type information (and related methods). */
  itkTypeMacro( ParameterArchiver, Object );

  /** This type is intentionally protected.  Only classes that inherit from
   * ParameterSerializer will deal with m_Parameters. */
  typedef std::map< std::string, ParameterValue * > ParametersType;


  /** Read the parameters from a file. */
  virtual void ReadFromFile( const std::string & fileName );

  /** Write the parameters to a file. */
  virtual void WriteToFile( const std::string & fileName ) const;

  /** Read from a stream. */
  virtual void ReadFromStdStream( std::istream & stream );

  /** Write to a stream. */
  virtual void WriteToStdStream( std::ostream & stream ) const;


  /** Write the parameter to a file, etc. */
  virtual void Serialize( const std::string & name ) = 0;
  virtual void Serialize( const std::string & name,
    const ParameterSerializerValue * value ) = 0;
  virtual void Serialize( const std::string & name,
    const ParameterSerializerArrayValue * value ) = 0;
  virtual void Serialize( const std::string & name,
    const StringValue * value ) = 0;
  virtual void Serialize( const std::string & name,
    const StringArrayValue * value ) = 0;
  virtual void Serialize( const std::string & name,
    const BoolValue * value ) = 0;
  virtual void Serialize( const std::string & name,
    const BoolArrayValue * value ) = 0;
  virtual void Serialize( const std::string & name,
    const IntegerValue * value ) = 0;
  virtual void Serialize( const std::string & name,
    const IntegerArrayValue * value ) = 0;
  virtual void Serialize( const std::string & name,
    const UnsignedIntegerValue * value ) = 0;
  virtual void Serialize( const std::string & name,
    const UnsignedIntegerArrayValue * value ) = 0;
  virtual void Serialize( const std::string & name,
    const FloatValue * value ) = 0;
  virtual void Serialize( const std::string & name,
    const FloatArrayValue * value ) = 0;
  virtual void Serialize( const std::string & name,
    const DoubleValue * value ) = 0;
  virtual void Serialize( const std::string & name,
    const DoubleArrayValue * value ) = 0;

  /** Load the parameters from a file, etc. */
  virtual void DeSerialize( ParametersType & parameters ) = 0;

protected:
  ParameterArchiver();
  virtual ~ParameterArchiver();

private:
  ParameterArchiver( const Self & ); // purposely not implemented
  void operator=( const Self & ); // purposely not implemented
};

} // end namespace itk

#endif
