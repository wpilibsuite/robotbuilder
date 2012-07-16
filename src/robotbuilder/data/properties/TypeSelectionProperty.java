/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package robotbuilder.data.properties;

import java.util.Vector;
import javax.swing.JComboBox;
import robotbuilder.data.RobotComponent;

/**
 *
 * @author Alex Henning
 */
public class TypeSelectionProperty extends Property {
    protected String type;
    protected Object value;
    private RobotComponent valueComponent;
    protected JComboBox combo;
    
    public TypeSelectionProperty() {}
    
    public TypeSelectionProperty(String name, Object defaultValue, String[] validators, RobotComponent component,
            String type, Object value) {
        super(name, defaultValue, validators, component);
        this.type = type;
        this.value = value;
        if (value != null) valueComponent = component.getRobotTree().getComponentByName(value.toString());
    }

    @Override
    public Property copy() {
        return new TypeSelectionProperty(name, defaultValue, validators, component, type, value);
    }

    @Override
    public Object getValue() {
        if (valueComponent != null) return valueComponent.getFullName();
        return (value != null) ? value : defaultValue;
    }
    
    @Override
    public Object getDisplayValue() {
        update();
        return combo;
    }

    @Override
    public void _setValue(Object value) {
        this.value = value;
        if (value != null && component != null)
            valueComponent = component.getRobotTree().getComponentByName(value.toString());
    }
    
    
    @Override
    public void update() {
        super.update();
        Object selection = getValue();
        if (valueComponent != null) selection = valueComponent.getFullName();
        Vector<String> options = component.getRobotTree().getRoot().getChildrenOfTypeNames(type);
        options.add(0, defaultValue.toString());
        combo = new JComboBox(options);
        combo.setSelectedIndex(0);
        if (options.contains(selection)) {
            combo.setSelectedItem(selection);
        }
        value = combo.getSelectedItem() != null ? combo.getSelectedItem() : value;
    }
    
    public String getType() {
        return type;
    }
    public void setType(String type) {
        this.type = type;
    }
}