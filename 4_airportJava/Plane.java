package oopjava;

import java.util.Random;

public class Plane{
        
        private static Random rnd;
        static{ rnd = new Random(); }
        
        protected int id;        // The airplane Id
        protected String title;  // The airplane title
	protected int capacity;  // The airplane capacity
        private static int idCount;
        static{ idCount=0; }

	protected CargoBay crg;                 // The Cargo bay area
	protected EquipmentCompartment eqc[];	// The Equipment Compartment area
	protected PassengerCompartment pas[];	// The Passenger Compartment area
        
        
        // The requested getters
        public int get_id(){ return id; }
	public String get_title(){ return title; }
	public int get_capacity(){ return capacity; }
	public CargoBay get_cargoBay(){ return crg; }
	public EquipmentCompartment[] get_eqpCmp(){ return eqc; }
	public PassengerCompartment[] get_pasCmp(){ return pas; }

	// Getters needed for equal()
	protected EquipmentCompartment get_eqp(int i){ return eqc[i]; } // Returns the ith EquipmentCompartment
	protected PassengerCompartment get_pas(int i){ return pas[i]; } // Returns the ith PassengerCompartment
        
        
        public Plane(){
            // Get an id
            id=idCount++;
            
            // Get a random plane model
            title=new String();
            title=randTitle();	

            // Get a random passenger capacity in [50, 250]
            capacity=rnd.nextInt((250 - 50) + 1) + 50;

            // Get a Cargo Bay by default constrctor
            crg=new CargoBay();
            // Equipment Compartments are 3
            eqc=new EquipmentCompartment[3];
            for(int i=0; i<3; i++){
                eqc[i]=new EquipmentCompartment();
            }
            
            // Passenger Compartments generated as a function of capacity
            int amount=pasCompAmnt(capacity);
            pas=new PassengerCompartment[amount];
            for(int i=0; i<amount; i++){
                pas[i]=new PassengerCompartment();
            }
            System.out.print(" Plane ");
            System.out.print(id);
            System.out.println(" just created!");
        }
	public Plane(Plane obj){
            // First copy the id and the simple data members
            id=obj.get_id();
            title=obj.get_title();
            capacity=obj.get_capacity();
            // And then using copy constructors create the new corresponding 
            // compartments with the correct values
            crg=new CargoBay(obj.get_cargoBay());

            eqc=new EquipmentCompartment[3];
            for(int i=0; i<3; i++){
                eqc[i]=new EquipmentCompartment(obj.get_eqp(i));
            }

            int amount=pasCompAmnt(capacity);
            pas=new PassengerCompartment[amount];
            for(int i=0; i<amount; i++){
                pas[i]=new PassengerCompartment(obj.get_pas(i));
            }
            System.out.print(" Plane ");
            System.out.print(id);
            System.out.println(" just created!");
        }
        
        @Override
	public String toString(){
            String tmp=new String();

            // Get the id
            tmp=tmp.concat(">Id= ");
            tmp=tmp.concat(String.valueOf(id));

            // Pass the title
            tmp=tmp.concat(" Title= ");
            tmp=tmp.concat(title);

            // Then the capacity
            tmp=tmp.concat(" Capacity= ");
            tmp=tmp.concat(String.valueOf(capacity));

            //Then the rest of the existing plane compartments
            tmp=tmp.concat("\n");
            tmp=tmp.concat(crg.toString());
            for(int i=0; i<3; i++){
                    tmp=tmp.concat("\n");
                    tmp=tmp.concat(eqc[i].toString());
            }
            int t=pasCompAmnt(capacity);
            for(int i=0; i<t; i++){
                    tmp=tmp.concat("\n");
                    tmp=tmp.concat(pas[i].toString());
            }
            return tmp;
        }
        @Override
	public boolean equals(Object obj){
            if(id!=((Plane)obj).get_id()){ return false; }

            if( !(title.equals(((Plane)obj).get_title())) ){ return false; }
            if( capacity!=((Plane)obj).get_capacity()){ return false; }

            if( !(crg.equals(((Plane)obj).get_cargoBay())) ){ return false; }
            for(int i=0; i<3; i++){
                    if( !(eqc[i].equals(((Plane)obj).get_eqp(i))) ){ return false; }
            }
            int t=pasCompAmnt(capacity);
            for(int i=0; i<t; i++){
                    if( !(pas[i].equals(((Plane)obj).get_pas(i))) ){ return false; }
            }
            return true;
        }
        @Override
        public Object clone(){
            Plane obj=new Plane(this);
            return obj;
        }

	public void process(SecurityEmployee emp){
            // Work on Cargo Bay
            crg.process(emp);

            // Work on Equipment Compartments
            for(int i=0; i<3; i++){
                eqc[i].process(emp);
            }

            // Work on Passenger Compartments
            int tmp=pasCompAmnt(capacity);
            for(int i=0; i<tmp; i++){
                pas[i].process(emp);
            }

            // Employee's work here is done
            emp.workComplete();
        }
	public void process(MaintenanceEmployee emp){
            // Work on Cargo Bay
            crg.process(emp);

            // Work on Equipment Compartments
            for(int i=0; i<3; i++){
                eqc[i].process(emp);
            }

            // Employee's work here is done
            emp.workComplete();
        }
	public void process(CleaningEmployee emp){
            // Work on Cargo Bay
            crg.process(emp);

            // Work on Passenger Compartments
            int tmp=pasCompAmnt(capacity);
            for(int i=0; i<tmp; i++){
                pas[i].process(emp);
            }

            // Employee's work here is done
            emp.workComplete();
        }

	public boolean ready_check(){
            // Check Cargo Bay
            if( !crg.ready_check() ){ return false; }

            // Check Equipment Compartments
            for(int i=0; i<3; i++){
                    if( !eqc[i].ready_check() ){ return false; }
            }

            // Check Passenger Compartments
            int tmp=pasCompAmnt(capacity);
            for(int i=0; i<tmp; i++){
                    if( !pas[i].ready_check() ){ return false; }
            }
            return true;
        }

	
        private static int pasCompAmnt(int cap){ 
            // For this assignment i consider the "maximum capacity" of a
            // PassengerCompartment to be 50 passengers
            if(cap<=50){ return 1; }
            else if(cap<=100){ return 2; }
            else if(cap<=150){ return 3; }
            else if(cap<=200){ return 4; }
            else if(cap<=250){ return 5; }
            else { return 0; } // < will never reach this, here just for security
        }
        
        private static String[] Titles={"A330-300", "A330-200", "A321", "A320", 
        "A319", "A350-800", "A350-900", "A350-1000", "Beluga", "A380-900"};
        
        private static String randTitle(){ return Titles[rnd.nextInt(10)]; }
}
