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
#include "itkJsonCppArchiver.h"

#include "itkParameterSerializerValue.h"
#include "itkParameterSerializerArrayValue.h"

#include <fstream>

namespace itk
{

JsonCppArchiver
::JsonCppArchiver()
{
  m_JsonValue = new Json::Value;
  m_OwnJsonValueMemory = true;
}


JsonCppArchiver
::~JsonCppArchiver()
{
  if( m_OwnJsonValueMemory )
    {
    delete m_JsonValue;
    }
}


void
JsonCppArchiver
::SetJsonValue( Json::Value * value )
{
  if( m_JsonValue != value )
    {
    if( m_OwnJsonValueMemory )
      {
      delete m_JsonValue;
      m_OwnJsonValueMemory = false;
      }
    m_JsonValue = value;
    this->Modified();
    }
}


const Json::Value *
JsonCppArchiver
::GetJsonValue() const
{
  return m_JsonValue;
}


void
JsonCppArchiver
::ReadFromFile( const std::string & fileName )
{
  std::ifstream stream( fileName.c_str() );
  if( !stream.is_open() )
    {
    itkExceptionMacro(<< "Could not open file: " << fileName);
    }
  Json::Reader reader;
  reader.parse( stream, *m_JsonValue );
  stream.close();
}


void
JsonCppArchiver
::WriteToFile( const std::string & fileName ) const
{
  std::ofstream stream( fileName.c_str() );
  if( !stream.is_open() )
    {
    itkExceptionMacro(<< "Could not open file: " << fileName);
    }
  Json::StyledStreamWriter writer;
  writer.write( stream, *m_JsonValue );
  stream.close();
}


void
JsonCppArchiver
::ReadFromStdStream( std::istream & stream )
{
  Json::Reader reader;
  reader.parse( stream, *m_JsonValue );
}


void
JsonCppArchiver
::WriteToStdStream( std::ostream & stream ) const
{
  Json::StyledStreamWriter writer;
  writer.write( stream, *m_JsonValue );
}


void
JsonCppArchiver
::Serialize( const std::string & name )
{
  (*m_JsonValue)[name] = Json::Value( Json::nullValue );
}


void
JsonCppArchiver
::Serialize( const std::string & name,
  const ParameterSerializerValue * value )
{
  ParameterSerializer * serializer = value->GetValue();
  JsonCppArchiver * archiver =
    dynamic_cast< JsonCppArchiver * >( serializer->GetArchiver() );
  if( archiver == NULL )
    {
    JsonCppArchiver::Pointer newNestedArchiver = JsonCppArchiver::New();
    serializer->SetArchiver( newNestedArchiver );
    archiver = newNestedArchiver.GetPointer();
    }
  Json::Value nestedValue;
  archiver->SetJsonValue( &nestedValue );
  serializer->Serialize();
  (*m_JsonValue)[name] = nestedValue;
}


void
JsonCppArchiver
::Serialize( const std::string & name,
  const ParameterSerializerArrayValue * value )
{
  const ParameterSerializerArrayValue::ParameterSerializerSmartArrayType serializerArray =
    value->GetValue();
  Json::Value nestedValue( Json::arrayValue );
  for( size_t ii = 0; ii < serializerArray.size(); ++ii )
    {
    JsonCppArchiver * archiver =
      dynamic_cast< JsonCppArchiver * >( serializerArray[ii]->GetArchiver() );
    if( archiver == NULL )
      {
      JsonCppArchiver::Pointer newNestedArchiver = JsonCppArchiver::New();
      serializerArray[ii]->SetArchiver( newNestedArchiver );
      archiver = newNestedArchiver.GetPointer();
      }
    Json::Value arrayElement;
    archiver->SetJsonValue( &arrayElement );
    serializerArray[ii]->Serialize();
    nestedValue.append( arrayElement );
    }
  (*m_JsonValue)[name] = nestedValue;
}


void
JsonCppArchiver
::Serialize( const std::string & name,
  const StringValue * value )
{
  (*m_JsonValue)[name] = value->GetValue();
}


void
JsonCppArchiver
::Serialize( const std::string & name,
  const StringArrayValue * value )
{
  Json::Value arrayValue( Json::arrayValue );
  const StringArrayValue::StringArrayType stringArray =
    value->GetValue();
  for( size_t ii = 0; ii < stringArray.size(); ++ii )
    {
    Json::Value stringElement( stringArray[ii] );
    arrayValue.append( stringElement );
    }
  (*m_JsonValue)[name] = arrayValue;
}


void
JsonCppArchiver
::Serialize( const std::string & name,
  const BoolValue * value )
{
  (*m_JsonValue)[name] = value->GetValue();
}


void
JsonCppArchiver
::Serialize( const std::string & name,
  const BoolArrayValue * value )
{
  Json::Value arrayValue( Json::arrayValue );
  const BoolArrayValue::BoolArrayType boolArray =
    value->GetValue();
  for( size_t ii = 0; ii < boolArray.size(); ++ii )
    {
    Json::Value boolElement( boolArray[ii] );
    arrayValue.append( boolElement );
    }
  (*m_JsonValue)[name] = arrayValue;
}


void
JsonCppArchiver
::Serialize( const std::string & name,
  const IntegerValue * value )
{
  (*m_JsonValue)[name] =
    static_cast< Json::Value::Int >( value->GetValue() );
}


void
JsonCppArchiver
::Serialize( const std::string & name,
  const IntegerArrayValue * value )
{
  Json::Value arrayValue( Json::arrayValue );
  const IntegerArrayValue::IntegerArrayType integerArray =
    value->GetValue();
  for( size_t ii = 0; ii < integerArray.size(); ++ii )
    {
    Json::Value integerElement(
      static_cast< Json::Value::Int >( integerArray[ii] ));
    arrayValue.append( integerElement );
    }
  (*m_JsonValue)[name] = arrayValue;
}


void
JsonCppArchiver
::Serialize( const std::string & name,
  const UnsignedIntegerValue * value )
{
  (*m_JsonValue)[name] =
    static_cast< Json::Value::UInt >( value->GetValue() );
}


void
JsonCppArchiver
::Serialize( const std::string & name,
  const UnsignedIntegerArrayValue * value )
{
  Json::Value arrayValue( Json::arrayValue );
  const UnsignedIntegerArrayValue::UnsignedIntegerArrayType integerArray =
    value->GetValue();
  for( size_t ii = 0; ii < integerArray.size(); ++ii )
    {
    Json::Value integerElement(
      static_cast< Json::Value::UInt >( integerArray[ii] ));
    arrayValue.append( integerElement );
    }
  (*m_JsonValue)[name] = arrayValue;
}


void
JsonCppArchiver
::Serialize( const std::string & name,
  const FloatValue * value )
{
  (*m_JsonValue)[name] = value->GetValue();
}


void
JsonCppArchiver
::Serialize( const std::string & name,
  const FloatArrayValue * value )
{
  Json::Value arrayValue( Json::arrayValue );
  const FloatArrayValue::FloatArrayType floatArray =
    value->GetValue();
  for( size_t ii = 0; ii < floatArray.size(); ++ii )
    {
    Json::Value floatElement( floatArray[ii] );
    arrayValue.append( floatElement );
    }
  (*m_JsonValue)[name] = arrayValue;
}


void
JsonCppArchiver
::Serialize( const std::string & name,
  const DoubleValue * value )
{
  (*m_JsonValue)[name] = value->GetValue();
}


void
JsonCppArchiver
::Serialize( const std::string & name,
  const DoubleArrayValue * value )
{
  Json::Value arrayValue( Json::arrayValue );
  const DoubleArrayValue::DoubleArrayType doubleArray =
    value->GetValue();
  for( size_t ii = 0; ii < doubleArray.size(); ++ii )
    {
    Json::Value doubleElement( doubleArray[ii] );
    arrayValue.append( doubleElement );
    }
  (*m_JsonValue)[name] = arrayValue;
}


void
JsonCppArchiver
::DeSerialize( ParametersType & parameters )
{
  const Json::Value::Members members = m_JsonValue->getMemberNames();
  for( Json::Value::Members::const_iterator it = members.begin();
      it != members.end();
      ++it )
    {
    Json::Value & jsonValue = (*m_JsonValue)[*it];
    switch( jsonValue.type() )
      {
      case Json::nullValue:
        {
        break;
        }
      case Json::arrayValue:
        {
        if( jsonValue.empty() )
          {
          break;
          }
        switch( jsonValue[0].type() )
          {
          case Json::nullValue:
            break;
          case Json::objectValue:
            {
            // The specific parent serializer *must* populate the ParameterSerializerArray
            // with one of the correct inherited types.
            ParameterSerializerArrayValue * serializerArrayValue =
              static_cast< ParameterSerializerArrayValue * >( parameters[*it] );
            const ParameterSerializerArrayValue::ParameterSerializerSmartArrayType &
              oldSerializerArray = serializerArrayValue->GetValue();
            itkAssertInDebugAndIgnoreInReleaseMacro( oldSerializerArray.size() > 0 );
            LightObject::Pointer anotherSerializer = oldSerializerArray[0]->CreateAnother();
            ParameterSerializer::Pointer serializer =
              static_cast< ParameterSerializer * >( anotherSerializer.GetPointer() );

            ParameterSerializerArrayValue::ParameterSerializerSmartArrayType
              serializerArray( jsonValue.size() );
            for( size_t ii = 0; ii < serializerArray.size(); ++ii )
              {
              serializerArray[ii] =
                static_cast< ParameterSerializer * >( serializer->CreateAnother().GetPointer() );
              JsonCppArchiver * archiver =
                dynamic_cast< JsonCppArchiver * >( serializerArray[ii]->GetArchiver() );
              if( archiver == NULL )
                {
                JsonCppArchiver::Pointer newNestedArchiver = JsonCppArchiver::New();
                serializerArray[ii]->SetArchiver( newNestedArchiver );
                archiver = newNestedArchiver.GetPointer();
                }
              archiver->SetJsonValue(
                &(jsonValue[static_cast< Json::ArrayIndex >(ii)]) );
              serializerArray[ii]->DeSerialize();
              }
            serializerArrayValue->SetValue( serializerArray );
            break;
            }
          case Json::stringValue:
            {
            StringArrayValue::StringArrayType array( jsonValue.size() );
            for( size_t ii = 0; ii < array.size(); ++ii )
              {
              array[ii] = jsonValue[static_cast< Json::ArrayIndex >(ii)].asString();
              }
            StringArrayValue * arrayValue =
              static_cast< StringArrayValue * >( parameters[*it] );
            arrayValue->SetValue( array );
            break;
            }
          case Json::booleanValue:
            {
            BoolArrayValue::BoolArrayType array( jsonValue.size() );
            for( size_t ii = 0; ii < array.size(); ++ii )
              {
              array[ii] = jsonValue[static_cast< Json::ArrayIndex >(ii)].asBool();
              }
            BoolArrayValue * arrayValue =
              static_cast< BoolArrayValue * >( parameters[*it] );
            arrayValue->SetValue( array );
            break;
            }
          case Json::intValue:
            {
            IntegerArrayValue::IntegerArrayType array( jsonValue.size() );
            for( size_t ii = 0; ii < array.size(); ++ii )
              {
              array[ii] = jsonValue[static_cast< Json::ArrayIndex >(ii)].asInt64();
              }
            IntegerArrayValue * arrayValue =
              static_cast< IntegerArrayValue * >( parameters[*it] );
            arrayValue->SetValue( array );
            break;
            }
          case Json::uintValue:
            {
            UnsignedIntegerArrayValue::UnsignedIntegerArrayType array( jsonValue.size() );
            for( size_t ii = 0; ii < array.size(); ++ii )
              {
              array[ii] = jsonValue[static_cast< Json::ArrayIndex >(ii)].asUInt64();
              }
            UnsignedIntegerArrayValue * arrayValue =
              static_cast< UnsignedIntegerArrayValue * >( parameters[*it] );
            arrayValue->SetValue( array );
            break;
            }
          case Json::realValue:
            {
            ParameterValue * value = parameters[*it];
            switch( value->GetValueType() )
              {
              case ParameterValue::FLOAT:
                {
                FloatArrayValue::FloatArrayType array( jsonValue.size() );
                for( size_t ii = 0; ii < array.size(); ++ii )
                  {
                  array[ii] = jsonValue[static_cast< Json::ArrayIndex >(ii)].asFloat();
                  }
                FloatArrayValue * arrayValue =
                  static_cast< FloatArrayValue * >( parameters[*it] );
                arrayValue->SetValue( array );
                break;
                }
              case ParameterValue::DOUBLE:
                {
                DoubleArrayValue::DoubleArrayType array( jsonValue.size() );
                for( size_t ii = 0; ii < array.size(); ++ii )
                  {
                  array[ii] = jsonValue[static_cast< Json::ArrayIndex >(ii)].asDouble();
                  }
                DoubleArrayValue * arrayValue =
                  static_cast< DoubleArrayValue * >( parameters[*it] );
                arrayValue->SetValue( array );
                break;
                }
            default:
              itkExceptionMacro("Invalid ParameterValueType");
              }
            break;
            }
          default:
            itkExceptionMacro("Array value type not implemented (yet)");
          }
        break;
        }
      case Json::objectValue:
        {
        ParameterSerializerValue * serializerValue =
          static_cast< ParameterSerializerValue * >( parameters[*it] );
        ParameterSerializer * serializer = serializerValue->GetValue();
        JsonCppArchiver * archiver =
          dynamic_cast< JsonCppArchiver * >( serializer->GetArchiver() );
        if( archiver == NULL )
          {
          JsonCppArchiver::Pointer newNestedArchiver = JsonCppArchiver::New();
          serializer->SetArchiver( newNestedArchiver );
          archiver = newNestedArchiver.GetPointer();
          }
        archiver->SetJsonValue( &jsonValue );
        serializer->DeSerialize();
        break;
        }
      case Json::stringValue:
        {
        StringValue * value =
          static_cast< StringValue * >( parameters[*it] );
        value->SetValue( jsonValue.asString() );
        break;
        }
      case Json::booleanValue:
        {
        BoolValue * value =
          static_cast< BoolValue * >( parameters[*it] );
        value->SetValue( jsonValue.asBool() );
        break;
        }
      case Json::intValue:
        {
        IntegerValue * value =
          static_cast< IntegerValue * >( parameters[*it] );
        value->SetValue( jsonValue.asInt() );
        break;
        }
      case Json::uintValue:
        {
        UnsignedIntegerValue * value =
          static_cast< UnsignedIntegerValue * >( parameters[*it] );
        value->SetValue( jsonValue.asUInt() );
        break;
        }
      case Json::realValue:
        {
        ParameterValue * value = parameters[*it];
        switch( value->GetValueType() )
          {
          case ParameterValue::FLOAT:
            {
            FloatValue * floatValue =
              static_cast< FloatValue * >( value );
            floatValue->SetValue( jsonValue.asFloat() );
            break;
            }
          case ParameterValue::DOUBLE:
            {
            DoubleValue * doubleValue =
              static_cast< DoubleValue * >( value );
            doubleValue->SetValue( jsonValue.asDouble() );
            break;
              }
          default:
            itkExceptionMacro("Invalid ParameterValueType");
          }
        break;
        }
      default:
        itkExceptionMacro( "Unknown ParameterValueType!" );
      }
    }
}

} // end namespace itk
