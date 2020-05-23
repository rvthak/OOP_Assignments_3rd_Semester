package oopjava;

public abstract  class PlaneComponent {
        
        // The component's description and id
	protected String desc;
        protected int id;
        private static int idCount;
        static{ idCount=0; }
        
	// Boolean variables used to check work state
	protected boolean securityCheck;
	protected boolean maintenanceCheck;
	protected boolean cleanCheck;
        
        // Setters
	public void setSec(boolean v){ securityCheck=v; }
	public void setMnt(boolean v){ maintenanceCheck=v; }
	public void setCln(boolean v){ cleanCheck=v; }

	// Getters
        public int getId(){ return id; }
	public boolean getSec(){ return securityCheck; }
	public boolean getMnt(){ return maintenanceCheck; }
	public boolean getCln(){ return cleanCheck; }
	public String getDesc(){ return desc; }
    
	public PlaneComponent(){
            id=idCount++;
            securityCheck=false;
            maintenanceCheck=false;
            cleanCheck=false;
            System.out.print(" PlaneComponent ");
            System.out.print(String.valueOf(id));
            System.out.println(" just created!");
        }
        
        @Override
	public abstract Object clone();
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
            return tmp;
        }
        @Override
	public boolean equals(Object obj){
            if(id!=((PlaneComponent)obj).getId()){ return false; }
            if( !(desc.equals( ((PlaneComponent)obj).getDesc())) ){ return false; }
            if( securityCheck!=(((PlaneComponent)obj).getSec())){ return false; }
            if( maintenanceCheck!=(((PlaneComponent)obj).getMnt())){ return false; }
            if( cleanCheck!=(((PlaneComponent)obj).getCln())){ return false; }
            return true;
        }

	public abstract boolean ready_check();
	public void process(SecurityEmployee emp){ emp.workOn(this); }
	public void process(MaintenanceEmployee emp){ emp.workOn(this); }
	public void process(CleaningEmployee emp){ emp.workOn(this); }
}
