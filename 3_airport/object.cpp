#include <iostream>
#include "object.h"
#include "string.h"

using namespace std;

// Initialize the Object unique id counter to Zero
unsigned int Object::idCount=0;
unsigned int Object::getNewId(){ return idCount++; }

// Constructor + Destructor
Object::Object():id( getNewId() ){
	cout << " Object " << id << " just created!" << endl;
}
Object::~Object(){
	cout << " Object " << id << " just destroyed!" << endl;
}

// The getter
unsigned int Object::getId()const{ return id; }

// The rest of the functionality
bool Object::identical(const Object& obj)const{
	if(this==&obj){ return 1; }	// just check if the memory addresses are the same
	return 0;
}
