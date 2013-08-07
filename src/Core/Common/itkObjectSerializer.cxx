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
#include "itkObjectSerializer.h"

namespace itk
{

ObjectSerializer
::ObjectSerializer()
{
  this->m_Debug = new BoolValue;
  this->m_Debug->SetValue( false );
  this->m_Parameters["Debug"] = this->m_Debug;

  //this->m_ObjectName = new StringValue;
  //this->m_ObjectName->SetValue( "" );
  //this->m_Parameters["ObjectName"] = this->m_ObjectName;
}


ObjectSerializer
::~ObjectSerializer()
{
  delete m_Debug;
  //delete m_ObjectName;
}


void
ObjectSerializer
::Serialize()
{
  Object * filter =
    dynamic_cast< Object * >
      ( this->GetTargetObject() );
  if( filter == NULL )
    {
    itkWarningMacro("ObjectSerializer target object not set");
    }
  else
    {
    this->m_Debug->SetValue( filter->GetDebug() );
    this->m_Parameters["Debug"] = this->m_Debug;

    //this->m_ObjectName->SetValue( filter->GetObjectName() );
    //this->m_Parameters["ObjectName"] = this->m_ObjectName;
    }

  Superclass::Serialize();
}


void
ObjectSerializer
::DeSerialize()
{
  Superclass::DeSerialize();

  Object * filter =
    dynamic_cast< Object * >
      ( this->GetTargetObject() );
  if( filter != NULL )
    {
    filter->SetDebug( this->m_Debug->GetValue() );
    //filter->SetObjectName( this->m_ObjectName->GetValue() );
    }
}

} // end namespace itk
