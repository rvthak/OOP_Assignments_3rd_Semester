#include <iostream>
#include "employee.h"
#include "planeComponent.h"

using namespace std;

//========================================
//          --- Employee ---
//========================================

// Constructor + Destructor
Employee::Employee():name(randName()){
	worked=0;
	cout << " Employee " << id << " just created!" << endl;
}
Employee::~Employee(){
	cout << " Employee " << id << " just destroyed!" << endl;
}


// Getters + Setter
const String &Employee::getName()const{ return name; }
bool Employee::checkWork()const{ return worked; }
void Employee::workComplete(){ worked=1; }


// toString virtual implementation for Employee class and sub-classes
String Employee::toString()const{
	String tmp;
	// Pass the object id
	tmp.concat(">Id= ");
	tmp.concat(int_to_String(id));

	// Pass the employee's name
	tmp.concat(" Name= ");
	tmp.concat(name);

	// And his work status
	tmp.concat(" Work= ");
	tmp.concat(bool_to_String(worked));

	return tmp;
}
bool Employee::equal(const Object *obj)const{
	if(id!=obj->getId()){ return 0; }
	if( !(name.equal(((Employee *)obj)->getNamePtr())) ){ return 0; }
	if( worked!=((Employee *)obj)->checkWork()){ return 0; }
	return 1;
}


//========================================
//       --- SecurityEmployee ---
//========================================

// Constructors + Destructor
SecurityEmployee::SecurityEmployee(){
	cout << " SecurityEmployee " << id << " just created!" << endl;
}
SecurityEmployee::SecurityEmployee(const SecurityEmployee& obj){
	id=obj.getId();
	name=obj.getName();
	worked=obj.checkWork();
	cout << " SecurityEmployee " << id << " just created!" << endl;
}
SecurityEmployee::~SecurityEmployee(){
	cout << " SecurityEmployee " << id << " just destroyed!" << endl;
}

// Clone functions
Object *SecurityEmployee::clone(){
	SecurityEmployee *obj=new SecurityEmployee(*this);
	return obj;
}

// Employee virtuals
void SecurityEmployee::workOn(PlaneComponent& cmp){
	cout << " Security Employee checking plane compartment: ";
	print(cmp.getDesc());
	cmp.setSec(1);
}
void SecurityEmployee::report()const{
	if(worked){cout << " Security Check: OK" << endl;}
	else{cout << " Security Check: NOT OK" << endl;}
}


//========================================
//      --- MaintenanceEmployee ---
//========================================

// Constructors + Destructor
MaintenanceEmployee::MaintenanceEmployee(){
	cout << " MaintenanceEmployee " << id << " just created!" << endl;
}
MaintenanceEmployee::MaintenanceEmployee(const MaintenanceEmployee& obj){
	id=obj.getId();
	name=obj.getName();
	worked=obj.checkWork();
	cout << " MaintenanceEmployee " << id << " just created!" << endl;
}
MaintenanceEmployee::~MaintenanceEmployee(){
	cout << " MaintenanceEmployee " << id << " just destroyed!" << endl;
}

// Clone functions
Object *MaintenanceEmployee::clone(){
	MaintenanceEmployee *obj=new MaintenanceEmployee(*this);
	return obj;
}

// Employee virtuals
void MaintenanceEmployee::workOn(PlaneComponent& cmp){
	cout << " Maintenance Employee checking plane compartment: ";
	print(cmp.getDesc());
	cmp.setMnt(1);
}
void MaintenanceEmployee::report()const{
	if(worked){cout << " Maintenance Check: OK" << endl;}
	else{cout << " Maintenance Check: NOT OK" << endl;}
}


//========================================
//       --- CleaningEmployee ---
//========================================

// Constructors + Destructor
CleaningEmployee::CleaningEmployee(){
	cout << " CleaningEmployee " << id << " just created!" << endl;
}
CleaningEmployee::CleaningEmployee(const CleaningEmployee& obj){
	id=obj.getId();
	name=obj.getName();
	worked=obj.checkWork();
	cout << " CleaningEmployee " << id << " just created!" << endl;
}
CleaningEmployee::~CleaningEmployee(){
	cout << " CleaningEmployee " << id << " just destroyed!" << endl;
}

// Clone functions
Object *CleaningEmployee::clone(){
	CleaningEmployee *obj=new CleaningEmployee(*this);
	return obj;
}

// Employee virtuals
void CleaningEmployee::workOn(PlaneComponent& cmp){
	cout << " Cleaning Employee checking plane compartment: ";
	print(cmp.getDesc());
	cmp.setCln(1);
}
void CleaningEmployee::report()const{
	if(worked){cout << " Cleaning: OK" << endl;}
	else{cout << " Cleaning: NOT OK" << endl;}
}
