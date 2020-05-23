#include <ctime>
#include <cstdlib>
#include <iostream>
#include "employee.h"
#include "planeComponent.h"

using namespace std;

//========================================
//      --- PlaneComponent ---
//========================================

// Constructor + Destructor
PlaneComponent::PlaneComponent(){
	// Prepare Component for checks
	securityCheck=0;
	maintenanceCheck=0;
	cleanCheck=0;
	cout << " PlaneComponent " << id << " just created!" << endl;
}
PlaneComponent::~PlaneComponent(){
	cout << " PlaneComponent " << id << "  just destroyed!" << endl;
}

// The needed virtual functions
String PlaneComponent::toString()const{
	String tmp;

	// Get the id
	tmp.concat(">Id= ");
	tmp.concat(int_to_String(id));

	// The description
	tmp.concat(" ");
	tmp.concat(desc);

	// The work flags
	tmp.concat(" securityCheck=");
	tmp.concat(bool_to_String(securityCheck));
	tmp.concat(" maintenanceCheck=");
	tmp.concat(bool_to_String(maintenanceCheck));
	tmp.concat(" cleanCheck=");
	tmp.concat(bool_to_String(cleanCheck));

	return tmp;
}
bool PlaneComponent::equal(const Object *obj)const{
	if(id!=obj->getId()){ return 0; }
	if( !(desc.equal(((PlaneComponent *)obj)->getDescPtr())) ){ return 0; }
	if( securityCheck!=((PlaneComponent *)obj)->getSec()){ return 0; }
	if( maintenanceCheck!=((PlaneComponent *)obj)->getMnt()){ return 0; }
	if( cleanCheck!=((PlaneComponent *)obj)->getCln()){ return 0; }
	return 1;
}

// PlaneComponent virtual functions
void PlaneComponent::process(SecurityEmployee& emp){
	// Work on the targeted component
	emp.workOn(*this);
}
void PlaneComponent::process(MaintenanceEmployee& emp){
	// Work on the targeted component
	emp.workOn(*this);
}
void PlaneComponent::process(CleaningEmployee& emp){
	// Work on the targeted component
	emp.workOn(*this);
}

// Setters + Getters
void PlaneComponent::setSec(bool v){ securityCheck=v; }
void PlaneComponent::setMnt(bool v){ maintenanceCheck=v; }
void PlaneComponent::setCln(bool v){ cleanCheck=v; }
bool PlaneComponent::getSec()const{ return securityCheck; }
bool PlaneComponent::getMnt()const{ return maintenanceCheck; }
bool PlaneComponent::getCln()const{ return cleanCheck; }
const String& PlaneComponent::getDesc()const{ return desc; }


//========================================
//     --- PassengerCompartment ---
//========================================
static unsigned int seed=time(NULL); // For "randomness" in creating internal PassengerCompartments
static unsigned int pasCmpCount=0;   // For giving PassengerCompartments their own unique id 

PassengerCompartment::PassengerCompartment(){
	// Set a description for the compartment
	desc.concat("Passenger Compartment ");
	desc.concat(int_to_String(pasCmpCount++));

	// A "usual" passenger compartment has a 50% chance of actually
	// being "split" into two smaller ones
	srand(seed++);
	if( rand()%2==1 ){ // ~50% chance to have an internal Passenger Compartment
		intrn=new PassengerCompartment(0);
	}
	else{ // no internal compartment
		intrn=NULL;
	}
	cout << " PassengerCompartment " << id << " just created!" << endl;
}
PassengerCompartment::PassengerCompartment(const PassengerCompartment& obj){
	// Copy the data member values
	id=obj.getId();
	desc=obj.getDesc();
	securityCheck=obj.getSec();
	maintenanceCheck=obj.getMnt();
	cleanCheck=obj.getCln();

	// Finally copy the internal, if any
	if(obj.getIntrn()==NULL){
		intrn=NULL;
	}
	else{// Create a new internal copy constructed from the old one
		intrn=new PassengerCompartment(*obj.getIntrn());
	}
	cout << " PassengerCompartment " << id << " just created!" << endl;
}
PassengerCompartment::PassengerCompartment(int dummy){
	// this is the constructor of a internal passenger compartment so this
	// cant be split to smaller ones - used only from class public constructor

	// Set a description for the compartment
	desc.concat("Passenger Compartment ");
	desc.concat(int_to_String(pasCmpCount++));

	// This can't have an internal
	intrn=NULL;
	cout << " PassengerCompartment " << id << " just created!" << endl;
}
PassengerCompartment::~PassengerCompartment(){
	if( intrn!=NULL ){ delete intrn; } // remember to also free the internal
	cout << " PassengerCompartment " << id << " just destroyed!" << endl;
}

// The needed virtual functions
Object *PassengerCompartment::clone(){
	PassengerCompartment *obj=new PassengerCompartment(*this);
	return obj;
}
String PassengerCompartment::toString()const{
	String tmp;

	// Get the id
	tmp.concat(">Id= ");
	tmp.concat(int_to_String(id));

	// The description
	tmp.concat(" ");
	tmp.concat(desc);

	// The work flags
	tmp.concat(" securityCheck=");
	tmp.concat(bool_to_String(securityCheck));
	tmp.concat(" maintenanceCheck=");
	tmp.concat(bool_to_String(maintenanceCheck));
	tmp.concat(" cleanCheck=");
	tmp.concat(bool_to_String(cleanCheck));

	// The internal compartment data if it exists
	tmp.concat(" Internal Data: ");
	if(intrn==NULL){
		tmp.concat("NONE");
	}
	else{
		tmp.concat("VVVV\n\t");
		tmp.concat(intrn->toString());
	}
	return tmp;
}
bool PassengerCompartment::equal(const Object *obj)const{
	if(id!=obj->getId()){ return 0; }
	if( !(desc.equal(((PassengerCompartment *)obj)->getDescPtr())) ){ return 0; }
	if( securityCheck!=((PassengerCompartment *)obj)->getSec()){ return 0; }
	if( maintenanceCheck!=((PassengerCompartment *)obj)->getMnt()){ return 0; }
	if( cleanCheck!=((PassengerCompartment *)obj)->getCln()){ return 0; }

	if(intrn==NULL && (((PassengerCompartment *)obj)->getIntrn()==NULL)){ return 1; }
	else if(intrn!=NULL && (((PassengerCompartment *)obj)->getIntrn()!=NULL) ){
		if( intrn->equal(((PassengerCompartment *)obj)->getIntrn())){ return 1; }
	}
	return 0;
}

// PlaneComponent virtual functions
bool PassengerCompartment::ready_check()const{
	if( intrn!=NULL){ // If there is an internal check it too
		if( !intrn->ready_check() ){ return 0; }
	}
	if(securityCheck && cleanCheck){ 
		toString().print(); // Print the description
		cout << " > PassengerCompartment " << id << " OK!" << endl; 
		return 1; // Success
	}
	return 0;
}
void PassengerCompartment::process(CleaningEmployee& emp){
	// Work on the targeted component
	emp.workOn(*this);

	// If there is another compartment inside work on it
	if(intrn!=NULL){
		emp.workOn(*intrn);
	}
}
void PassengerCompartment::process(SecurityEmployee& emp){
	// Work on the targeted component
	emp.workOn(*this);

	// If there is another compartment inside work on it
	if(intrn!=NULL){
		emp.workOn(*intrn);
	}
}
void PassengerCompartment::process(MaintenanceEmployee& emp){
	// Work on the targeted component
	emp.workOn(*this);

	// If there is another compartment inside work on it
	if(intrn!=NULL){
		emp.workOn(*intrn);
	}
}

// Getter
PassengerCompartment *PassengerCompartment::getIntrn()const{ return intrn; }


//========================================
//      --- PrivateCompartment ---
//========================================
static unsigned int privCmpCount=0;

PrivateCompartment::PrivateCompartment(){
	// Set a description for the compartment
	desc.concat("Private Compartment ");
	desc.concat(int_to_String(privCmpCount++));
	desc.concat(" ");

	cout << " PrivateCompartment " << id << " just created!" << endl;
}
PrivateCompartment::PrivateCompartment(const PrivateCompartment& obj){
	// Copy the data member values
	id=obj.getId();
	desc=obj.getDesc();
	securityCheck=obj.getSec();
	maintenanceCheck=obj.getMnt();
	cleanCheck=obj.getCln();
	cout << " PrivateCompartment " << id << " just created!" << endl;
}
PrivateCompartment::~PrivateCompartment(){
	cout << " PrivateCompartment " << id << " just destroyed!" << endl;
}

// The needed virtual functions
Object *PrivateCompartment::clone(){
	PrivateCompartment *obj=new PrivateCompartment(*this);
	return obj;
}

// PlaneComponent virtual function
bool PrivateCompartment::ready_check()const{
	// Since it is not clear in the assignment
	// i decided to consider it an "empty space"
	// so if used alone, it needs no work
	toString().print();
	cout << " > PrivateCompartment " << id << " OK!" << endl; 
	return 1;
}

//========================================
//          --- CargoBay ---
//========================================
static unsigned int crgBayCount=0;

CargoBay::CargoBay(){
	// Set a description for the compartment
	desc.concat("Cargo Bay ");
	desc.concat(int_to_String(crgBayCount++));

	// Create the internal EquipmentCompartment
	eqc=new EquipmentCompartment;

	cout << " CargoBay " << id << " just created!" << endl;
}
CargoBay::CargoBay(const CargoBay& obj){
	// Copy the data member values
	id=obj.getId();
	desc=obj.getDesc();
	securityCheck=obj.getSec();
	maintenanceCheck=obj.getMnt();
	cleanCheck=obj.getCln();

	// Create a new internal copy constructed from the old one
	eqc=new EquipmentCompartment(*obj.getEqc());

	cout << " CargoBay " << id << " just created!" << endl;
}
CargoBay::~CargoBay(){
	if(eqc!=NULL){ delete eqc; }
	cout << " CargoBay " << id << " just destroyed!" << endl;
}

// The needed virtual functions
Object *CargoBay::clone(){
	CargoBay *obj=new CargoBay(*this);
	return obj;
}
String CargoBay::toString()const{
	String tmp;

	// Get the id
	tmp.concat(">Id= ");
	tmp.concat(int_to_String(id));

	// The description
	tmp.concat(" ");
	tmp.concat(desc);

	// The work flags
	tmp.concat(" securityCheck=");
	tmp.concat(bool_to_String(securityCheck));
	tmp.concat(" maintenanceCheck=");
	tmp.concat(bool_to_String(maintenanceCheck));
	tmp.concat(" cleanCheck=");
	tmp.concat(bool_to_String(cleanCheck));

	// The internal compartment data
	tmp.concat(" Internal Data: VVVV\n\t");
	tmp.concat(eqc->toString());

	return tmp;
}
bool CargoBay::equal(const Object *obj)const{
	if(id!=obj->getId()){ return 0; }
	if( !(desc.equal(((CargoBay *)obj)->getDescPtr())) ){ return 0; }
	if( securityCheck!=((CargoBay *)obj)->getSec()){ return 0; }
	if( maintenanceCheck!=((CargoBay *)obj)->getMnt()){ return 0; }
	if( cleanCheck!=((CargoBay *)obj)->getCln()){ return 0; }

	if( !(eqc->equal(((CargoBay *)obj)->getEqc()))){ return 0; }
	return 1;
}

// PlaneComponent virtual function
bool CargoBay::ready_check()const{
	if( !eqc->ready_check() ){ return 0; }
	 
	if(securityCheck && cleanCheck && maintenanceCheck){ 
		toString().print();
		cout << " > CargoBay " << id << " OK!" << endl; 
		return 1; 
	}
	return 0;
}
void CargoBay::process(CleaningEmployee& emp){
	// Work on the targeted component
	emp.workOn(*this);
}
void CargoBay::process(SecurityEmployee& emp){
	// Work on the targeted component
	emp.workOn(*this);

	// Work on the internal equipment comp
	emp.workOn(*eqc);
}
void CargoBay::process(MaintenanceEmployee& emp){
	// Work on the targeted component
	emp.workOn(*this);

	// Work on the internal equipment comp
	emp.workOn(*eqc);
}

// Getter
EquipmentCompartment *CargoBay::getEqc()const{ return eqc; }

//========================================
//     --- EquipmentCompartment ---
//========================================
static unsigned int eqpCmpCount=0;

EquipmentCompartment::EquipmentCompartment(){
	// Set a description for the compartment
	desc.concat("Equipment Compartment ");
	desc.concat(int_to_String(eqpCmpCount++));

	cout << " EquipmentCompartment " << id << " just created!" << endl;
}
EquipmentCompartment::EquipmentCompartment(const EquipmentCompartment& obj){
	// Copy the data member values
	id=obj.getId();
	desc=obj.getDesc();
	securityCheck=obj.getSec();
	maintenanceCheck=obj.getMnt();
	cleanCheck=obj.getCln();
	cout << " EquipmentCompartment " << id << " just created!" << endl;
}
EquipmentCompartment::~EquipmentCompartment(){
	cout << " EquipmentCompartment " << id << " just destroyed!" << endl;
}

// The needed virtual functions
Object *EquipmentCompartment::clone(){
	EquipmentCompartment *obj=new EquipmentCompartment(*this);
	return obj;
}

// PlaneComponent virtual function
bool EquipmentCompartment::ready_check()const{
	if(securityCheck && maintenanceCheck){ 
		toString().print();
		cout << " > EquipmentCompartment " << id << " OK!" << endl; 
		return 1; 
	}
	return 0;
}
