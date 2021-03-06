/**********************************************************************

   Audacity - A Digital Audio Editor
   Copyright 1999-2009 Audacity Team
   License: GPL v2 - see LICENSE.txt

   Dan Horgan

******************************************************************//**

\file SelectCommand.h
\brief Declarations for SelectCommand and SelectCommandType classes

*//*******************************************************************/

#ifndef __SELECTCOMMAND__
#define __SELECTCOMMAND__

#include "CommandType.h"
#include "Command.h"

class SelectCommandType final : public CommandType
{
public:
   wxString BuildName() override;
   void BuildSignature(CommandSignature &signature) override;
   Command *Create(CommandOutputTarget *target) override;
};

class SelectCommand final : public CommandImplementation
{
public:
   SelectCommand(SelectCommandType &type, CommandOutputTarget *target)
      : CommandImplementation(type, target) { }
   bool Apply(CommandExecutionContext context) override;
};

#endif /* End of include guard: __SELECTCOMMAND__ */
