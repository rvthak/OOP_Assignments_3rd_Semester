package oopjava;

public class CargoBay extends PlaneComponent{
    
        private EquipmentCompartment eqc;
        private EquipmentCompartment getEqc(){ return eqc; }

        public CargoBay(){
            // Set a description for the compartment
            desc=new String();
            desc=desc.concat("Cargo Bay ");
            desc=desc.concat(String.valueOf(id));
            
            // Create the internal EquipmentCompartment
            eqc=new EquipmentCompartment();

            System.out.print(" CargoBay ");
            System.out.print(id);
            System.out.println(" just created!");
        }
	public CargoBay(CargoBay obj){
            // Copy the data member values
            id=obj.getId();
            desc=obj.getDesc();
            securityCheck=obj.getSec();
            maintenanceCheck=obj.getMnt();
            cleanCheck=obj.getCln();

            // Create a new internal copy constructed from the old one
            eqc=new EquipmentCompartment(obj.getEqc());
            
            System.out.print(" CargoBay ");
            System.out.print(id);
            System.out.println(" just created!");
        }
        
        @Override
	public Object clone(){
            CargoBay obj=new CargoBay(this);
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

            // The internal compartment data
            tmp=tmp.concat(" Internal Data: VVVV\n\t");
            tmp=tmp.concat(eqc.toString());
            return tmp;
        }     
        @Override
	public boolean equals(Object obj){
            if(id!=((PlaneComponent)obj).getId()){ return false; }
            if( !(desc.equals( ((PlaneComponent)obj).getDesc())) ){ return false; }
            if( securityCheck!=(((PlaneComponent)obj).getSec())){ return false; }
            if( maintenanceCheck!=(((PlaneComponent)obj).getMnt())){ return false; }
            if( cleanCheck!=(((PlaneComponent)obj).getCln())){ return false; }

            if( !(eqc.equals(((CargoBay)obj).getEqc()))){ return false; }
            return true;
        }
        
        @Override
	public boolean ready_check(){
            if(securityCheck && cleanCheck && maintenanceCheck){    
                System.out.print(toString());
                System.out.print(" > CargoBay ");
                System.out.print(id);
                System.out.println(" OK!");
                if( !eqc.ready_check() ){ return false; }
                return true; 
            }
            return false;
        }
        @Override
	public void process(CleaningEmployee emp){ emp.workOn(this); }
        @Override
	public void process(SecurityEmployee emp){ 
            emp.workOn(this);
            emp.workOn(eqc);
        }
        @Override
	public void process(MaintenanceEmployee emp){ 
            emp.workOn(this);
            emp.workOn(eqc);
        }
}

