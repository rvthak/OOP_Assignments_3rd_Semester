package oopjava;

public class SecurityEmployee extends Employee{
    
    public SecurityEmployee(){
        System.out.print(" SecurityEmployee ");
        System.out.print(id);
        System.out.println(" just created!");
    }
    public SecurityEmployee(SecurityEmployee obj){
        id=obj.getId();
	name=obj.getName();
	worked=obj.checkWork();
        System.out.print(" SecurityEmployee ");
        System.out.print(id);
        System.out.println(" just created!");
    }
    
    @Override
    public Object clone(){
        SecurityEmployee obj;
        obj = new SecurityEmployee(this);
	return obj;
    }
	
    @Override
    public void workOn(PlaneComponent cmp){
        System.out.print(" Security Employee checking plane compartment: ");
        System.out.println(cmp.getDesc());
	cmp.setSec(true);
    }
    @Override
    public void report(){
        if(worked){System.out.println(" Security Check: OK");}
	else{System.out.println(" Security Check: NOT OK");}
    }
}
