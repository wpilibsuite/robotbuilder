#set($cmd = $robot.getProperty("Autonomous Command").getValue())
#foreach( $component in $components )
#if($component.getBase().getType() == "Command" && !($component.getProperty("Parameters").getValue().isEmpty()) && $component.name == $cmd)
m_setpoint,
#end
#if ($component.getBase().getType() == "Command" && $component.name == $cmd)
        #if( $component.getProperty("Parameter presets").getValue().isEmpty() )
                #if ($component.getProperty("Requires").getValue() != "None")
&m_#required_subsystem($component))#if($component.getProperty("Add Timeout").value == true).withTimeout($component.getProperty("Timeout").value)#end{
                #else
){
               #end
        #end
#end
#end
