#set($command = $robot.getProperty("Autonomous Command").getValue())
#set($params = $robot.getProperty("Autonomous command parameters").getValue())

#foreach( $component in $components )
#if ($component.getBase().getType() == "Command"
     && $component.getProperty("Autonomous Selection").getValue())
#if( $component.getProperty("Parameter presets").getValue().isEmpty() )
        m_chooser.addOption("$component.getName()", new #class($component.getName())());
#else
#foreach( $set in $component.getProperty("Parameter presets").getValue() )
        m_chooser.addOption("$component.getName(): $set.getName()", #command_instantiation( $component.getName(), $set.getParameters() ));
#end
#end
#end
#end
#if($command != "None")
        m_chooser.setDefaultOption("$command", #command_instantiation( $command $params ));
#end
