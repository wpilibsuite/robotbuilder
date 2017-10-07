#header()

package ${package}.commands;

import edu.wpi.first.wpilibj.command.PIDCommand;
import ${package}.Robot;
import ${package}.RobotMap;

#set($command = $helper.getByName($command-name, $robot))
/**
 *
 */
public class #class($command.name) extends PIDCommand {

#@autogenerated_code("variable_declarations", "    ")
#parse("${exporter-path}Command-variable-declarations.java")
#end

#@autogenerated_code("constructor", "    ")
#parse("${exporter-path}Command-constructor.java")
#end
#@autogenerated_code("pid", "        ")
#parse("${exporter-path}PIDCommand-pid.java")
#end
#@autogenerated_code("variable_setting", "        ")
#parse("${exporter-path}Command-variable-setting.java")
#end

        // Use requires() here to declare subsystem dependencies
        // eg. requires(chassis);
#@autogenerated_code("requires", "        ")
#parse("${exporter-path}Command-requires.java")
#end
    }

    @Override
    protected double returnPIDInput() {
        // Return your input value for the PID loop
        // e.g. a sensor, like a potentiometer:
        // yourPot.getAverageVoltage() / kYourMaxVoltage;

#@autogenerated_code("source", "        ")
#parse("${exporter-path}PIDCommand-source.java")
#end
    }

    @Override
    protected void usePIDOutput(double output) {
        // Use output to drive your system, like a motor
        // e.g. yourMotor.set(output);

#@autogenerated_code("output", "        ")
#parse("${exporter-path}PIDCommand-output.java")
#end
    }

    // Called just before this Command runs the first time
    @Override
    protected void initialize() {
    }

    // Called repeatedly when this Command is scheduled to run
    @Override
    protected void execute() {
    }

    // Make this return true when this Command no longer needs to run execute()
    @Override
    protected boolean isFinished() {
        return false;
    }

    // Called once after isFinished returns true
    @Override
    protected void end() {
    }

    // Called when another command which requires one or more of the same
    // subsystems is scheduled to run
    @Override
    protected void interrupted() {
    }
}
