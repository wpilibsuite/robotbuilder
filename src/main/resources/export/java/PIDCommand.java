#header()
// ROBOTBUILDER TYPE: PIDCommand.

package ${package}.commands;

import edu.wpi.first.wpilibj.controller.PIDController;
import edu.wpi.first.wpilibj2.command.PIDCommand;
import ${package}.Robot;

#@autogenerated_code("imports", "")
#parse("${exporter_path}PIDCommand-imports.java")
#end

#set($command = $helper.getByName($command_name, $robot))
/**
 *
 */
public class #class($command.name) extends PIDCommand {


#@autogenerated_code("constructors", "    ")
#parse("${exporter_path}PIDCommand-constructors.java")
#end
#@autogenerated_code("pid", "        ")
#parse("${exporter_path}PIDCommand-pid.java")
#end

    }
    @Override
    public boolean isFinished() {
      // End when the controller is at the reference.
      return getController().atSetpoint();
    }
}
