package oopjava;

import java.util.Random;

public class PassengerCompartment extends PlaneComponent{
    
        // Possible location of another passenger compartment, NULL if empty
        private PassengerCompartment intrn;
        
        // Make a static random num generator to decide if there is or not an internal compartment
        private static Random rnd;
        static{ rnd = new Random(); }
        
        // Getter
        public PassengerCompartment getIntrn(){ return intrn; }
        
	public PassengerCompartment(){
            // Set a description for the compartment
            desc=new String();
            desc=desc.concat("Passenger Compartment ");
            desc=desc.concat(String.valueOf(id));

            // A "usual" passenger compartment has a 50% chance of actually
            // being "split" into two smaller ones
            
            if( rnd.nextInt()%2==1 ){ // ~50% chance to have an internal Passenger Compartment
                intrn=new PassengerCompartment(0);
            }
            else{ // no internal compartment
                intrn=null;
            }
            System.out.print(" Passenger Compartment ");
            System.out.print(id);
            System.out.println(" just created!");
        }
	public PassengerCompartment(PassengerCompartment obj){
            // Copy the data member values
            id=obj.getId();
            desc=obj.getDesc();
            securityCheck=obj.getSec();
            maintenanceCheck=obj.getMnt();
            cleanCheck=obj.getCln();

            // Finally copy the internal, if any
            if(obj.getIntrn()==null){
                intrn=null;
            }
            else{// Create a new internal copy constructed from the old one
                    intrn=new PassengerCompartment(obj.getIntrn());
            }
            System.out.print(" Passenger Compartment ");
            System.out.print(id);
            System.out.println(" just created!");
        }
        private PassengerCompartment(int dummy){
            // Set a description for the compartment
            desc=new String();
            desc=desc.concat("Passenger Compartment ");
            desc=desc.concat(String.valueOf(id));

            // This can't have an internal
            intrn=null;
            System.out.print(" Passenger Compartment ");
            System.out.print(id);
            System.out.println(" just created!");
        }
        
        @Override
	public Object clone(){
            PassengerCompartment obj=new PassengerCompartment(this);
            return obj;
        }
        @Override
	public String toString(){
            String tmp=new String();
            // Get the id
            tmp=tmp.concat(">Id= ");
            tmp=tmp.concat(String.valueOf(id));

            // The description
            tmp=tmp.concat(" ");
            tmp=tmp.concat(desc);

            // The work flags
            tmp=tmp.concat(" securityCheck=");
            tmp=tmp.concat(String.valueOf(securityCheck));
            tmp=tmp.concat(" maintenanceCheck=");
            tmp=tmp.concat(String.valueOf(maintenanceCheck));
            tmp=tmp.concat(" cleanCheck=");
            tmp=tmp.concat(String.valueOf(cleanCheck));

            // The internal compartment data if it exists
            tmp=tmp.concat(" Internal Data: ");
            if(intrn==null){
                    tmp=tmp.concat("NONE");
            }
            else{
                    tmp=tmp.concat("VVVV\n\t");
                    tmp=tmp.concat(intrn.toString());
            }
            return tmp;
        }
        @Override
	public boolean equals(Object obj){
            if(id!=((PlaneComponent)obj).getId()){ return false; }
            if( !(desc.equals( ((PlaneComponent)obj).getDesc())) ){ return false; }
            if( securityCheck!=(((PlaneComponent)obj).getSec())){ return false; }
            if( maintenanceCheck!=(((PlaneComponent)obj).getMnt())){ return false; }
            if( cleanCheck!=(((PlaneComponent)obj).getCln())){ return false; }

            if(intrn==null && (((PassengerCompartment)obj).getIntrn()==null)){ return true; }
            else if(intrn!=null && (((PassengerCompartment)obj).getIntrn()!=null) ){
                    if( intrn.equals(((PassengerCompartment)obj).getIntrn())){ return true; }
            }
            return false;
        }
        
        @Override
	public boolean ready_check(){
            if(securityCheck && cleanCheck){
                    System.out.print(toString()); // Print the description
                    System.out.print(" > PassengerCompartment ");
                    System.out.print(id);
                    System.out.println(" OK!");
                    if( intrn!=null){ // If there is an internal check it too
                            if( !intrn.ready_check() ){ return false; }
                    }
                    return true; // Success
            }
            return false;
        }
        
        @Override
	public void process(CleaningEmployee emp){
            // Work on the targeted component
            emp.workOn(this);

            // If there is another compartment inside work on it
            if(intrn!=null){
                emp.workOn(intrn);
            }
        }
        @Override
	public void process(SecurityEmployee emp){
            // Work on the targeted component
            emp.workOn(this);

            // If there is another compartment inside work on it
            if(intrn!=null){
                emp.workOn(intrn);
            }
        }
        @Override
	public void process(MaintenanceEmployee emp){
            // Work on the targeted component
            emp.workOn(this);

            // If there is another compartment inside work on it
            if(intrn!=null){
                emp.workOn(intrn);
            }
        }
}