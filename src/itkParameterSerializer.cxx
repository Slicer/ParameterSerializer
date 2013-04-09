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
#include "itkParameterSerializer.h"

#include "itkBoolValue.h"
#include "itkBoolArrayValue.h"
#include "itkDoubleValue.h"
#include "itkDoubleArrayValue.h"
#include "itkFloatValue.h"
#include "itkFloatArrayValue.h"
#include "itkIntegerValue.h"
#include "itkIntegerArrayValue.h"
#include "itkParameterSerializerValue.h"
#include "itkParameterSerializerArrayValue.h"
#include "itkStringValue.h"
#include "itkStringArrayValue.h"
#include "itkUnsignedIntegerValue.h"
#include "itkUnsignedIntegerArrayValue.h"
#include "itkJsonCppArchiver.h"

namespace itk
{

ParameterSerializer
::ParameterSerializer()
{
  this->m_Archiver = JsonCppArchiver::New();
}


ParameterSerializer
::~ParameterSerializer()
{
}


void
ParameterSerializer
::Serialize()
{
  for( ParametersType::const_iterator it = m_Parameters.begin();
      it != m_Parameters.end();
      ++it )
    {
    switch( it->second->GetValueType() )
      {
      case ParameterValue::NIL:
        {
        this->m_Archiver->Serialize( it->first );
        break;
        }
      case ParameterValue::PARAMETER_SERIALIZER:
        {
        const ParameterSerializerValue * value =
          static_cast< ParameterSerializerValue * >( it->second );
        this->m_Archiver->Serialize( it->first, value );
        break;
        }
      case ParameterValue::PARAMETER_SERIALIZER_ARRAY:
        {
        const ParameterSerializerArrayValue * value =
          static_cast< ParameterSerializerArrayValue * >( it->second );
        this->m_Archiver->Serialize( it->first, value );
        break;
        }
      case ParameterValue::STRING:
        {
        const StringValue * value =
          static_cast< StringValue * >( it->second );
        this->m_Archiver->Serialize( it->first, value );
        break;
        }
      case ParameterValue::STRING_ARRAY:
        {
        const StringArrayValue * value =
          static_cast< StringArrayValue * >( it->second );
        this->m_Archiver->Serialize( it->first, value );
        break;
        }
      case ParameterValue::BOOL:
        {
        const BoolValue * value =
          static_cast< BoolValue * >( it->second );
        this->m_Archiver->Serialize( it->first, value );
        break;
        }
      case ParameterValue::BOOL_ARRAY:
        {
        const BoolArrayValue * value =
          static_cast< BoolArrayValue * >( it->second );
        this->m_Archiver->Serialize( it->first, value );
        break;
        }
      case ParameterValue::INTEGER:
        {
        const IntegerValue * value =
          static_cast< IntegerValue * >( it->second );
        this->m_Archiver->Serialize( it->first, value );
        break;
        }
      case ParameterValue::INTEGER_ARRAY:
        {
        const IntegerArrayValue * value =
          static_cast< IntegerArrayValue * >( it->second );
        this->m_Archiver->Serialize( it->first, value );
        break;
        }
      case ParameterValue::UNSIGNED_INTEGER:
        {
        const UnsignedIntegerValue * value =
          static_cast< UnsignedIntegerValue * >( it->second );
        this->m_Archiver->Serialize( it->first, value );
        break;
        }
      case ParameterValue::UNSIGNED_INTEGER_ARRAY:
        {
        const UnsignedIntegerArrayValue * value =
          static_cast< UnsignedIntegerArrayValue * >( it->second );
        this->m_Archiver->Serialize( it->first, value );
        break;
        }
      case ParameterValue::FLOAT:
        {
        const FloatValue * value =
          static_cast< FloatValue * >( it->second );
        this->m_Archiver->Serialize( it->first, value );
        break;
        }
      case ParameterValue::FLOAT_ARRAY:
        {
        const FloatArrayValue * value =
          static_cast< FloatArrayValue * >( it->second );
        this->m_Archiver->Serialize( it->first, value );
        break;
        }
      case ParameterValue::DOUBLE:
        {
        const DoubleValue * value =
          static_cast< DoubleValue * >( it->second );
        this->m_Archiver->Serialize( it->first, value );
        break;
        }
      case ParameterValue::DOUBLE_ARRAY:
        {
        const DoubleArrayValue * value =
          static_cast< DoubleArrayValue * >( it->second );
        this->m_Archiver->Serialize( it->first, value );
        break;
        }
      default:
        itkExceptionMacro( "Unknown ParameterValueType!" );
      }
    }
}


void
ParameterSerializer
::DeSerialize()
{
  this->m_Archiver->DeSerialize( this->m_Parameters );
}


void
ParameterSerializer
::PrintSelf( std::ostream & os, Indent indent ) const
{
  Superclass::PrintSelf( os, indent );

  os << indent << "Archiver: " << m_Archiver->GetNameOfClass() << std::endl;
  if( m_TargetObject.IsNull() )
    {
    os << indent << "TargetObject: NULL" << std::endl;
    }
  else
    {
    os << indent << "TargetObject: " << m_TargetObject->GetNameOfClass() << std::endl;
    }

  os << indent << "Parameters: " << std::endl;
  for( ParametersType::const_iterator it = m_Parameters.begin();
      it != m_Parameters.end();
      ++it )
    {
    os << indent << indent << it->first << ": ";
    const Indent nextIndent = indent.GetNextIndent();
    switch( it->second->GetValueType() )
      {
      case ParameterValue::NIL:
        {
        os << "NIL" << std::endl;
        break;
        }
      case ParameterValue::PARAMETER_SERIALIZER:
        {
        const ParameterSerializerValue * value =
          static_cast< ParameterSerializerValue * >( it->second );
        const ParameterSerializer * serializer = value->GetValue();
        serializer->Print( os, nextIndent );
        break;
        }
      case ParameterValue::PARAMETER_SERIALIZER_ARRAY:
        {
        const ParameterSerializerArrayValue * value =
          static_cast< ParameterSerializerArrayValue * >( it->second );
        const ParameterSerializerArrayValue::ParameterSerializerSmartArrayType & array =
          value->GetValue();
        os << '\n' << nextIndent << "[" << std::endl;
        for( size_t ii = 0; ii < array.size(); ++ii )
          {
          os << nextIndent << ii << ": ";
          array[ii]->Print( os, indent.GetNextIndent().GetNextIndent() );
          }
        os << nextIndent << "]" << std::endl;
        break;
        }
      case ParameterValue::STRING:
        {
        const StringValue * value =
          static_cast< StringValue * >( it->second );
        os << value->GetValue() << std::endl;
        break;
        }
      case ParameterValue::STRING_ARRAY:
        {
        const StringArrayValue * value =
          static_cast< StringArrayValue * >( it->second );
        const StringArrayValue::StringArrayType array =
          value->GetValue();
        os << '\n' << nextIndent << "[" << std::endl;
        for( size_t ii = 0; ii < array.size(); ++ii )
          {
          os << nextIndent << ii << ": " << array[ii] << std::endl;
          }
        os << nextIndent << "]" << std::endl;
        break;
        }
      case ParameterValue::BOOL:
        {
        const BoolValue * value =
          static_cast< BoolValue * >( it->second );
        if( value->GetValue() )
          {
          os << "true" << std::endl;
          }
        else
          {
          os << "false" << std::endl;
          }
        break;
        }
      case ParameterValue::BOOL_ARRAY:
        {
        const BoolArrayValue * value =
          static_cast< BoolArrayValue * >( it->second );
        const BoolArrayValue::BoolArrayType array =
          value->GetValue();
        os << '\n' << nextIndent << "[" << std::endl;
        for( size_t ii = 0; ii < array.size(); ++ii )
          {
          if( array[ii] )
            {
            os << nextIndent << ii << ": true" << std::endl;
            }
          else
            {
            os << nextIndent << ii << ": false" << std::endl;
            }
          }
        os << nextIndent << "]" << std::endl;
        break;
        }
      case ParameterValue::INTEGER:
        {
        const IntegerValue * value =
          static_cast< IntegerValue * >( it->second );
        os << value->GetValue() << std::endl;
        break;
        }
      case ParameterValue::INTEGER_ARRAY:
        {
        const IntegerArrayValue * value =
          static_cast< IntegerArrayValue * >( it->second );
        const IntegerArrayValue::IntegerArrayType array =
          value->GetValue();
        os << '\n' << nextIndent << "[" << std::endl;
        for( size_t ii = 0; ii < array.size(); ++ii )
          {
          os << nextIndent << ii << ": " << array[ii] << std::endl;
          }
        os << nextIndent << "]" << std::endl;
        break;
        }
      case ParameterValue::UNSIGNED_INTEGER:
        {
        const UnsignedIntegerValue * value =
          static_cast< UnsignedIntegerValue * >( it->second );
        os << value->GetValue() << std::endl;
        break;
        }
      case ParameterValue::UNSIGNED_INTEGER_ARRAY:
        {
        const UnsignedIntegerArrayValue * value =
          static_cast< UnsignedIntegerArrayValue * >( it->second );
        const UnsignedIntegerArrayValue::UnsignedIntegerArrayType array =
          value->GetValue();
        os << '\n' << nextIndent << "[" << std::endl;
        for( size_t ii = 0; ii < array.size(); ++ii )
          {
          os << nextIndent << ii << ": " << array[ii] << std::endl;
          }
        os << nextIndent << "]" << std::endl;
        break;
        }
      case ParameterValue::FLOAT:
        {
        const FloatValue * value =
          static_cast< FloatValue * >( it->second );
        os << value->GetValue() << std::endl;
        break;
        }
      case ParameterValue::FLOAT_ARRAY:
        {
        const FloatArrayValue * value =
          static_cast< FloatArrayValue * >( it->second );
        const FloatArrayValue::FloatArrayType array =
          value->GetValue();
        os << '\n' << nextIndent << "[" << std::endl;
        for( size_t ii = 0; ii < array.size(); ++ii )
          {
          os << nextIndent << ii << ": " << array[ii] << std::endl;
          }
        os << nextIndent << "]" << std::endl;
        break;
        }
      case ParameterValue::DOUBLE:
        {
        const DoubleValue * value =
          static_cast< DoubleValue * >( it->second );
        os << value->GetValue() << std::endl;
        break;
        }
      case ParameterValue::DOUBLE_ARRAY:
        {
        const DoubleArrayValue * value =
          static_cast< DoubleArrayValue * >( it->second );
        const DoubleArrayValue::DoubleArrayType array =
          value->GetValue();
        os << '\n' << nextIndent << "[" << std::endl;
        for( size_t ii = 0; ii < array.size(); ++ii )
          {
          os << nextIndent << ii << ": " << array[ii] << std::endl;
          }
        os << nextIndent << "]" << std::endl;
        break;
        }
    default:
      itkExceptionMacro( "Unknown ParameterValueType!" );
      }
    }
}

} // end namespace itk
