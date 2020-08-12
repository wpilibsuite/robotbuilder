#set($subsystem = $helper.getByName($subsystem_name, $robot))
#macro( klass $cmd )#if( "#type($cmd)" == "" ) frc::Subsystem #else frc::#type($cmd) #end#end
#header()
#pragma once

\#include <frc2/command/SubsystemBase.h>

#@autogenerated_code("includes", "")
#parse("${exporter_path}Subsystem-includes.h")
#end

/**
 *
 *
 * @author ExampleAuthor
 */
class #class($subsystem.name): public frc2::SubsystemBase {
private:
	// It's desirable that everything possible is private except
	// for methods that implement subsystem capabilities
#@autogenerated_code("declarations", "	")
#parse("${exporter_path}Subsystem-declarations.h")
#end
public:
	#class($subsystem.name)();
	// void InitDefaultCommand() override;
	// void Periodic() override;
#@autogenerated_code("cmdpidgetters", "	")
#parse("${exporter_path}Subsystem-pidgetters.h")
#end
#@autogenerated_code("constants", "	")
#parse("${exporter_path}Subsystem-constants.h")
#end


};

