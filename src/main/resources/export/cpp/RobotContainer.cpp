#header()

\#include "RobotContainer.h"
\#include <frc2/command/button/JoystickButton.h>

#@autogenerated_code("includes", "")
#parse("${exporter_path}OI-includes.h")
#end

#set($cmd = $robot.getProperty("Autonomous Command").getValue())

#foreach ($component in $components)
#if ($helper.exportsTo("OI", $component)
     && "#type($component)" != "" 
     && "#type($component)" == "Joystick")
    #set($joy = $component)

#end
#end

RobotContainer::RobotContainer() : m_autonomousCommand(
#foreach( $component in $components )
#if($component.getBase().getType() == "Command" && !($component.getProperty("Parameters").getValue().isEmpty()))
m_setpoint,
#end
#if ($component.getBase().getType() == "Command"
     && $component.getProperty("Button on SmartDashboard").getValue())
        #if( $component.getProperty("Parameter presets").getValue().isEmpty() )
                #if ($component.getProperty("Requires").getValue() != "None")
m_#required_subsystem($component))#if($component.getProperty("Add Timeout").value == true).withTimeout($component.getProperty("Timeout").value)#end{
               #end
        #end
#end
#end
    // Process operator interface input here.
#@autogenerated_code("constructors", "    ")
#parse("${exporter_path}OI-constructors.cpp")
#end
ConfigureButtonBindings();

#@autogenerated_code("default-commands", "    ")
#parse("${exporter_path}Subsystem-default_command.cpp")
#end

}

void RobotContainer::ConfigureButtonBindings() {

#foreach( $component in $components )
#if ($helper.exportsTo("OI", $component) && ("#type($component)" == "JoystickButton") && ("#constructor($component)" != "" || "#extra($component)" != ""))
#foreach ($command in $commands)
#if($command.name == $component.getProperty("Command").value)
#constructor($component)
#end
#end       
#end
#end

#foreach( $component in $components )
#if ($helper.exportsTo("OI", $component) && ("#type($component)" != "Joystick") && ("#constructor($component)" != "" || "#extra($component)" != ""))
#foreach ($command in $commands)
#if($command.name == $component.getProperty("Command").value)
m_#variable($component.name).$component.getProperty("When to Run").getValue().substring(0,1).toUpperCase()$component.getProperty("When to Run").getValue().substring(1)(#class($command.name)(m_#required_subsystem($command))#if($command.getProperty("Add Timeout").value == true).withTimeout($component.getProperty("Timeout").value)#end);#else#if($command.getProperty("Add Timeout").value == true).withTimeout($command.getProperty("Timeout").value));#end#end
#end
#end       
#end
}

#@autogenerated_code("functions", "")
#parse("${exporter_path}OI-functions.cpp")
#end


frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return &m_autonomousCommand;
}