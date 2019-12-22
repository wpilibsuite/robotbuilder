#set($command = $helper.getByName($command_name, $robot))
#header()

#pragma once


\#include "frc/commands/Subsystem.h"
\#include "Robot.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class #class($command.name): public frc::InstantCommand {
public:
#@autogenerated_code("constructor", "    ")
#parse("${exporter_path}Command-constructor-header.h")
#end

	void Initialize() override;

private:
#@autogenerated_code("variables", "	")
#parse("${exporter_path}Command-constructor-variables.h")
#end
};

