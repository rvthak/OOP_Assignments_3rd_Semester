package oopjava;

public class MaintenanceEmployee extends Employee{
    public MaintenanceEmployee(){
        System.out.print(" MaintenanceEmployee ");
        System.out.print(id);
        System.out.println(" just created!");
    }
    public MaintenanceEmployee(MaintenanceEmployee obj){
        id=obj.getId();
	name=obj.getName();
	worked=obj.checkWork();
        System.out.print(" MaintenanceEmployee ");
        System.out.print(id);
        System.out.println(" just created!");
    }
    
    @Override
    public Object clone(){
        MaintenanceEmployee obj;
        obj = new MaintenanceEmployee(this);
	return obj;
    }

    @Override
    public void workOn(PlaneComponent cmp){
        System.out.print(" Maintenance Employee checking plane compartment: ");
        System.out.println(cmp.getDesc());
	cmp.setMnt(true);
    }
    @Override
    public void report(){
        if(worked){System.out.println(" Maintenance Check: OK");}
	else{System.out.println(" Maintenance Check: NOT OK");}
    }
}
