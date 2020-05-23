package oopjava;

public class PrivateCompartment extends PlaneComponent{
    public PrivateCompartment(){
        // Set a description for the compartment
        desc=new String();
	desc=desc.concat("Private Compartment ");
	desc=desc.concat(String.valueOf(id));
	desc=desc.concat(" ");
        System.out.print(" PrivateCompartment ");
        System.out.print(id);
        System.out.println(" just created!");
    }
    public PrivateCompartment(PrivateCompartment obj){
        // Copy the data member values
	id=obj.getId();
	desc=obj.getDesc();
	securityCheck=obj.getSec();
	maintenanceCheck=obj.getMnt();
	cleanCheck=obj.getCln();
	System.out.print(" PrivateCompartment ");
        System.out.print(id);
        System.out.println(" just created!");
    }
    
    @Override
    public Object clone(){
        PrivateCompartment obj=new PrivateCompartment(this);
	return obj;
    }
    
    @Override
    public boolean ready_check(){
        System.out.print(toString());
        System.out.print(" > PrivateCompartment ");
        System.out.print(id);
        System.out.println(" OK!");
	return true;
    }
}