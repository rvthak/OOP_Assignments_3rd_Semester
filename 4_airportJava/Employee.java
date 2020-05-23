package oopjava;

import java.util.Random;

public abstract class Employee extends Object{
        
        protected int id;           // The employee's unique id
	protected String name;      // The employee's name
	protected boolean worked;   // The employee's work state
        private static int idCount; // A counter to ensure unique id's are given
        private static Random rnd;
        static{ rnd = new Random(); }
        static{ idCount=0; }    // Initialize the static id Counter
        
        private static String[] Names={"izambo", "errikos", "spyros", "nikosPerdikopanis", 
        "alexkalts", "vaggelisd", "pstamat", "harry", "stef", "sdi1800164"};
        
        private static String randName(){ return Names[rnd.nextInt(10)]; }
        
        // Getters / Setter
        public int getId(){ return id; }
	public String getName(){ return name; }
	public boolean checkWork(){ return worked; }
	public void workComplete(){ worked=true;  } 
    
        public Employee(){
            id=idCount++;
            name=new String();
            name=randName();
            worked=false;
        }

        @Override
	public abstract Object clone();
        @Override
	public String toString(){
            String tmp=new String();
            // Pass the object id
            tmp=tmp.concat(">Id= ");
            tmp=tmp.concat(String.valueOf(id));

            // Pass the employee's name
            tmp=tmp.concat(" Name= ");
            tmp=tmp.concat(name);

            // And his work status
            tmp=tmp.concat(" Work= ");
            tmp=tmp.concat(String.valueOf(worked));
            return tmp;
        }
        @Override
        public boolean equals(Object obj){
            if( id!=((Employee)obj).getId()){ return false; }
            if( !(name.equals(((Employee)obj).getName()))){ return false; }
            if( worked!=((Employee)obj).checkWork()){ return false; }
            return true;
        };

	public abstract void workOn(PlaneComponent cmp);
	public abstract void report();
}
