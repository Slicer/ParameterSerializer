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
#ifndef __itkJsonCppArchiver_h
#define __itkJsonCppArchiver_h

#include "itkObjectFactory.h"

#include "itkParameterArchiver.h"
#include "ParameterSerializerExport.h"

#include "json/json.h"

namespace itk
{

/**
 * \class JsonCppArchiver
 *
 * \brief Serializes parameters to a JsonCpp object.
 *
 * */
class ParameterSerializer_EXPORT JsonCppArchiver: public ParameterArchiver
{
public:
  /** Standard class typedefs. */
  typedef JsonCppArchiver            Self;
  typedef ParameterArchiver          Superclass;
  typedef SmartPointer< Self >       Pointer;
  typedef SmartPointer< const Self > ConstPointer;

  /** Run-time type information (and related methods). */
  itkTypeMacro( JsonCppArchiver, ParameterArchiver );

  itkNewMacro( Self );

  /** Set/Get the Json::Value that holds the archive. */
  void SetJsonValue( Json::Value * value );
  const Json::Value * GetJsonValue() const;

  virtual void ReadFromFile( const std::string & fileName );
  virtual void WriteToFile( const std::string & fileName ) const;

  virtual void ReadFromStdStream( std::istream & stream );
  virtual void WriteToStdStream( std::ostream & stream ) const;

protected:
  JsonCppArchiver();
  virtual ~JsonCppArchiver();

  virtual void Serialize( const std::string & name );
  virtual void Serialize( const std::string & name,
    const ParameterSerializerValue * value );
  virtual void Serialize( const std::string & name,
    const ParameterSerializerArrayValue * value );
  virtual void Serialize( const std::string & name,
    const StringValue * value );
  virtual void Serialize( const std::string & name,
    const StringArrayValue * value );
  virtual void Serialize( const std::string & name,
    const BoolValue * value );
  virtual void Serialize( const std::string & name,
    const BoolArrayValue * value );
  virtual void Serialize( const std::string & name,
    const IntegerValue * value );
  virtual void Serialize( const std::string & name,
    const IntegerArrayValue * value );
  virtual void Serialize( const std::string & name,
    const UnsignedIntegerValue * value );
  virtual void Serialize( const std::string & name,
    const UnsignedIntegerArrayValue * value );
  virtual void Serialize( const std::string & name,
    const FloatValue * value );
  virtual void Serialize( const std::string & name,
    const FloatArrayValue * value );
  virtual void Serialize( const std::string & name,
    const DoubleValue * value );
  virtual void Serialize( const std::string & name,
    const DoubleArrayValue * value );

  virtual void DeSerialize( ParametersType & parameters );

private:
  JsonCppArchiver( const Self & ); // purposely not implemented
  void operator=( const Self & ); // purposely not implemented

  Json::Value * m_JsonValue;
  bool          m_OwnJsonValueMemory;
};

} // end namespace itk

#endif
