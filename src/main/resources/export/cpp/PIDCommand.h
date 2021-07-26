#set($command = $helper.getByName($command_name, $robot))

#header()
// ROBOTBUILDER TYPE: PIDCommand.

#pragma once

#@autogenerated_code("constructor", "    ")
#parse("${exporter_path}PIDCommand-includes.h")
#end

/**
 *
 *
 * @author ExampleAuthor
 */
class #class($command.name): public frc2::CommandHelper<frc2::PIDCommand, #class($command.name)> {
public:
#@autogenerated_code("constructor", "    ")
#parse("${exporter_path}Command-constructor-header.h")
#end

    double ReturnPIDInput();
    void UsePIDOutput(double output);
    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();

#@autogenerated_code("cmdpidgetters","    ")
#parse("${exporter_path}Subsystem-pidgetters.h")
#end
private:
#@autogenerated_code("variables", "    ")
#parse("${exporter_path}Command-constructor-variables.h")
#end
};

