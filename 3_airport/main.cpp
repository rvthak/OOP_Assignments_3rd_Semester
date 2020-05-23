#include <ctime>
#include <cstdlib>
#include <iostream>
#include "plane.h"
#include "employee.h"

using namespace std;

void clone_encrypt_and_print(Object& o);

int main(){
	// 1.Create plane object
	Plane plane;
	cout << endl << endl;

	// 2.Create an object from each one of the Employee classes
	SecurityEmployee emp1; 		cout << endl;
	MaintenanceEmployee emp2;	cout << endl;
	CleaningEmployee emp3;		cout << endl;

	cout << "===========================================" << endl;
	// 3. Provide the employees to the plane
	plane.process(emp1);
	plane.process(emp2);
	plane.process(emp3);
	cout << endl;

	// 4. Get Employee reports
	emp1.report();
	emp2.report();
	emp3.report();
	cout << endl;

	// 5. Confirm the plane is ready to fly
	if( plane.ready_check() ){
		cout << " Plane ready to take off!" << endl;
	}
	else{
		cout << " Plane NOT ready to take off!" << endl;
	}
	
	// 6. Call clone_encrypt_and_print for plain
	cout << "===========================================" << endl;
	cout << "    Cloning, encrypting and printing...    " << endl;
	cout << "===========================================" << endl;
	clone_encrypt_and_print(plane);

	cout << endl << " > Everything Done! Terminating program..." << endl;
	return 0;
}

void clone_encrypt_and_print(Object& o){
	Object *n;		// create an object
	cout << endl << " > Cloning original object..." << endl;
	n=o.clone(); 	// clone the original object to the new one
	cout << " > Clone Created! " << endl;

	// Check them
	cout << endl << " > Checking equal: " << endl;
	if( n->equal(&o) ){ cout << " >The two objects are equal" << endl; }
	else{ cout << " >The two objects are NOT equal > exiting..." << endl; return;}

	cout << endl << " > Checking identical: " << endl;
	if( n->identical(o) ){ cout << " >The two objects are identical > exiting..." << endl; return;}
	else{ cout << " >The two objects are NOT identical " << endl << endl; }

	// Turn them to strings
	cout << " > Turning both objects to strings..." << endl;
	String os(o.toString());
	String ns(n->toString());
	cout << " > Objects turned to strings!" << endl << endl;

	// We dont need the clone any more => delete it
	cout << " > Deleting the clone..." << endl;
	delete n;
	cout << " > Clone Deleted!" << endl;

	// Print them
	cout << endl << " > The resulting strings are:" << endl;
	os.print();
	cout << endl;
	ns.print();

	// Swap random chars
	cout << endl << endl << " > Encrypting the cloned object's string..." << endl;
	srand(time(NULL));
	int ch1, ch2;
	int pos1, pos2;
	int len=ns.length();
	for(int i=0; i<600; i++){	// Decided to swap chars 600 times, trial and error showed its a good enough visual sweetspot
		pos1=rand()%len;
		pos2=rand()%len;

		// Here we know from before that pos is always smaller than sting length
		// so there is on reason to check for possible at return error code
		ch1=ns.at(pos1);
		ch2=ns.at(pos2);

		ns.updateAt(pos1, ch2);
		ns.updateAt(pos2, ch1);
	}

	// Print them
	cout << endl << " > The resulting strings are: " << endl;
	os.print();
	cout << endl;
	ns.print();

	cout << endl << endl << " > Original String length: " << os.length() << endl;
	cout << " > New String length: " << ns.length() << endl;

	// Concat them
	cout << " > Concatenate them..." << endl;
	ns.concat(os);

	cout << endl << " > The new string is: " << endl;
	ns.print();
	cout << endl;

	// Get and print the concat length
	int conlen=ns.length();
	cout << " > Concat length= " << conlen << endl;

	// Print the middle char/chars
	int pos=conlen/2;
	if(conlen%2==1){
		// odd length => one middle char
		cout << " > Middle char: " << endl;
		cout << " ASCII - (code) " << ns.at(pos) << " => (char) " << (char)ns.at(pos) << endl;
	}
	else{
		// even length => two middle chars
		cout << " > Middle chars: " << endl;
		cout << " ASCII - (code) " << ns.at(pos-1) << " => (char) " << (char)ns.at(pos-1) << endl;
		cout << " ASCII - (code) " << ns.at(pos)   << " => (char) " << (char)ns.at(pos)   << endl;
	}

	// Clear the string
	cout << endl << " Clearing string..." << endl;
	ns.clear();

	// Print the length of the now empty string
	cout << " Cleared String's length= " << ns.length() << endl << endl;

	cout << " > Clone Encrypt and print Done" << endl;
	return;
}