package oopjava;

public class EquipmentCompartment extends PlaneComponent{
    public EquipmentCompartment(){
        // Set a description for the compartment
        desc=new String();
	desc=desc.concat("Equipment Compartment ");
	desc=desc.concat(String.valueOf(id));
        System.out.print(" Equipment Compartment ");
        System.out.print(id);
        System.out.println(" just created!");
    }
    public EquipmentCompartment(EquipmentCompartment obj){
        // Copy the data member values
	id=obj.getId();
	desc=obj.getDesc();
	securityCheck=obj.getSec();
	maintenanceCheck=obj.getMnt();
	cleanCheck=obj.getCln();
        System.out.print(" Equipment Compartment ");
        System.out.print(id);
        System.out.println(" just created!");
    }
    
    @Override
    public Object clone(){
        EquipmentCompartment obj=new EquipmentCompartment(this);
	return obj;
    }
    
    @Override
    public boolean ready_check(){
        if(securityCheck && maintenanceCheck){ 
            System.out.print(toString());
            System.out.print(" > EquipmentCompartment ");
            System.out.print(id);
            System.out.println(" OK!");
            return true; 
	}
        System.out.println(" 45345 ");
	return false;
    }
}