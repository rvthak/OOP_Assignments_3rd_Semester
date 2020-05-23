#include <ctime>
#include <cstdlib>
#include <iostream>
#include "plane.h"

using namespace std;


// Used to produce better random results every time the program runs
static unsigned int seed=time(NULL);

// Returns the amount of passenger compartments that should exist in the plane 
// as a function of its total capacity - Used only in plane class constructor
unsigned int pasCompAmnt(unsigned int cap){ 
	// For this assignment i consider the "maximum capacity" of a
	// PassengerCompartment to be 50 passengers
	if(cap<=50){ return 1; }
	else if(cap<=100){ return 2; }
	else if(cap<=150){ return 3; }
	else if(cap<=200){ return 4; }
	else if(cap<=250){ return 5; }
	else { return 0; } // < will never reach this, here just for security
}


// Constructors + Destructor
Plane::Plane(){
	// Get a random plane model
	title=randTitle();	

	// Get a random passenger capacity in [50, 250]
	srand(seed++);
	capacity=50+rand()%(250-50+1); 

	// Get a Cargo Bay by default constrctor
	crg=new CargoBay;
	// Equipment Compartments are 3
	eqc=new EquipmentCompartment *[3];
	for(int i=0; i<3; i++){
		eqc[i]=new EquipmentCompartment;
	}
	// Passenger Compartments generated as a function of capacity
	int amount=pasCompAmnt(capacity);
	pas=new PassengerCompartment *[amount];
	for(int i=0; i<amount; i++){
		pas[i]=new PassengerCompartment;
	}
	cout << " Plane " << id << " just created!" << endl;
}
Plane::Plane(const Plane& obj){
	// First copy the id and the simple data members
	id=obj.getId();
	title=obj.get_title();
	capacity=obj.get_capacity();
	// And then using copy constructors create the new corresponding 
	// compartments with the correct values
	crg=new CargoBay(*obj.get_cargoBay());

	eqc=new EquipmentCompartment *[3];
	for(int i=0; i<3; i++){
		eqc[i]=new EquipmentCompartment(*obj.get_eqp(i));
	}

	int amount=pasCompAmnt(capacity);
	pas=new PassengerCompartment *[amount];
	for(int i=0; i<amount; i++){
		pas[i]=new PassengerCompartment(*obj.get_pas(i));
	}
	cout << " Plane " << id << " just created!" << endl;
}
Plane::~Plane(){
	// Do the reverse procedure
	// Check if the compartment is NULL and if not free it
	if( crg!=NULL ){ delete crg; }
	if( eqc!=NULL ){
		for(int i=0; i<3; i++){
			delete eqc[i];
		}
		delete[] eqc;
	}
	if( pas!=NULL ){
		int amount=pasCompAmnt(capacity);
		for(int i=0; i<amount; i++){
			delete pas[i];
		}
		delete[] pas;
	}

	cout << " Plane " << id << " just destroyed!" << endl;
}


// The needed virtual functions
Object *Plane::clone(){
	// Create the new Plane
	Plane *obj=new Plane(*this);

	// and return it
	return obj;
}
String Plane::toString()const{
	String tmp;

	// Get the id
	tmp.concat(">Id= ");
	tmp.concat(int_to_String(id));

	// Pass the title
	tmp.concat(" Title= ");
	tmp.concat(title);

	// Then the capacity
	tmp.concat(" Capacity= ");
	tmp.concat(int_to_String(capacity));

	//Then the rest of the existing plane compartments
	tmp.concat("\n");
	tmp.concat(crg->toString());
	for(int i=0; i<3; i++){
		tmp.concat("\n");
		tmp.concat(eqc[i]->toString());
	}
	int t=pasCompAmnt(capacity);
	for(int i=0; i<t; i++){
		tmp.concat("\n");
		tmp.concat(pas[i]->toString());
	}
	return tmp;
}
bool Plane::equal(const Object *obj)const{ // Just check if every single data member is equal
	if(id!=obj->getId()){ return 0; }
	if( !(title.equal(((Plane *)obj)->get_title_Ptr())) ){ return 0; }
	if( capacity!=((Plane *)obj)->get_capacity()){ return 0; }

	if( !(crg->equal(((Plane *)obj)->get_cargoBay())) ){ return 0; }
	for(int i=0; i<3; i++){
		if( !(eqc[i]->equal(((Plane *)obj)->get_eqp(i))) ){ return 0; }
	}
	int t=pasCompAmnt(capacity);
	for(int i=0; i<t; i++){
		if( !(pas[i]->equal(((Plane *)obj)->get_pas(i))) ){ return 0; }
	}
	return 1;
}


// Getters
String Plane::get_title()const{ return title; }
unsigned int Plane::get_capacity()const{ return capacity; }
CargoBay *Plane::get_cargoBay()const{ return crg; }
EquipmentCompartment **Plane::get_eqpCmp()const{ return eqc; }
PassengerCompartment **Plane::get_pasCmp()const{ return pas; }


// Process variations + ready_check
void Plane::process(SecurityEmployee& emp){ // pass, cargo, eqc
	// Work on Cargo Bay
	crg->process(emp);

	// Work on Equipment Compartments
	for(int i=0; i<3; i++){
		eqc[i]->process(emp);
	}

	// Work on Passenger Compartments
	int tmp=pasCompAmnt(capacity);
	for(int i=0; i<tmp; i++){
		pas[i]->process(emp);
	}

	// Employee's work here is done
	emp.workComplete();
}
void Plane::process(MaintenanceEmployee& emp){	// cargo, eqc
	// Work on Cargo Bay
	crg->process(emp);

	// Work on Equipment Compartments
	for(int i=0; i<3; i++){
		eqc[i]->process(emp);
	}

	// Employee's work here is done
	emp.workComplete();
}
void Plane::process(CleaningEmployee& emp){	// cargo, pass
	// Work on Cargo Bay
	crg->process(emp);

	// Work on Passenger Compartments
	int tmp=pasCompAmnt(capacity);
	for(int i=0; i<tmp; i++){
		pas[i]->process(emp);
	}

	// Employee's work here is done
	emp.workComplete();
}
bool Plane::ready_check(){
	// Check Cargo Bay
	if( !crg->ready_check() ){ return 0; }

	// Check Equipment Compartments
	for(int i=0; i<3; i++){
		if( !eqc[i]->ready_check() ){ return 0; }
	}

	// Check Passenger Compartments
	int tmp=pasCompAmnt(capacity);
	for(int i=0; i<tmp; i++){
		if( !pas[i]->ready_check() ){ return 0; }
	}
	return 1;
}
