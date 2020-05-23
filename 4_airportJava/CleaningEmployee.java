package oopjava;

public class CleaningEmployee extends Employee{
    public CleaningEmployee(){
        System.out.print(" CleaningEmployee ");
        System.out.print(id);
        System.out.println(" just created!");
    }
    public CleaningEmployee(CleaningEmployee obj){
        id=obj.getId();
	name=obj.getName();
	worked=obj.checkWork();
        System.out.print(" CleaningEmployee ");
        System.out.print(id);
        System.out.println(" just created!");
    }

    @Override
    public Object clone(){
        CleaningEmployee obj;
        obj = new CleaningEmployee(this);
	return obj;
    }

    @Override
    public void workOn(PlaneComponent cmp){
        System.out.print(" Cleaning Employee checking plane compartment: ");
        System.out.println(cmp.getDesc());
	cmp.setCln(true);
    }
    @Override
    public void report(){
        if(worked){System.out.println(" Cleaning Check: OK");}
	else{System.out.println(" Cleaning Check: NOT OK");}
    }
}
