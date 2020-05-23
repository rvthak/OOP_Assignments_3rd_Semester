package oopjava;

public class OopJava{
    public static void main(String[] args){
       // 1.Create plane object
        System.out.println(" > Creating Plane:");
	Plane plane=new Plane();
	System.out.println("\n");
        
	// 2.Create an object from each one of the Employee classes
        System.out.println(" > Creating Employees:");
	SecurityEmployee emp1=new SecurityEmployee();
	MaintenanceEmployee emp2=new MaintenanceEmployee();
	CleaningEmployee emp3=new CleaningEmployee();

        System.out.println("\n===========================================");
	// 3. Provide the employees to the plane
        System.out.println(" > Employees work on the Plane:");
	plane.process(emp1);
	plane.process(emp2);
	plane.process(emp3);
	System.out.println("\n");

	// 4. Get Employee reports
        System.out.println(" > Get Employee reports:");
	emp1.report();
	emp2.report();
	emp3.report();
	System.out.println("\n");

	// 5. Confirm the plane is ready to fly
        System.out.println(" > Final check:");
	if( plane.ready_check() ){
            System.out.println(" Plane ready to take off!");
	}
	else{
            System.out.println(" Plane NOT ready to take off!");
	}
        
        System.out.println(" > Everything Done! Terminating program...");
    }
    
}
