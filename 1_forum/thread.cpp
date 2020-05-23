#include <iostream>
#include "namespace.h"
#include "thread.h"
#include "random.h"

using namespace std;

Thread::Thread(const string sb, const string cr, Date& dt)
	:subject(sb), creator(cr), creation_date(dt){
	postnum=0;
	list=new Post*[ Values::Max_Number_Of_Posts ];
	// basic setup done

	// add some posts with random values
	for(int i=0; i<Values::Number_Of_Posts; i++){
		dt.random();
		list[i]=new Post(dt, Post::getCurIDInc(), randomPhrase(), randomName(), randomText());
		postnum++;
	}

	/*
	//Used for testing, for clear output uncomment if you want
	cout << endl << "   ----New Thread Info---- " << endl;
	cout << "   Subject:  " << subject << endl;
	cout << "   Creator:  " << creator << endl;
	cout << "   Created:  ";
	creation_date.print();
	*/
	
	cout << endl << " ------------------------------------------------------------------------------------------------------ " << endl;
	cout << "> Thread with subject: " << subject << " has just been created!" << endl;
	cout << " ------------------------------------------------------------------------------------------------------ " << endl << endl << endl;
	return;
}

Thread::~Thread(){
	for(int i=0; i<postnum; i++){
		delete list[i];
	}
	delete[] list;
	cout << " ------------------------------------------------------------------------------------------------------ " << endl;
	cout << "> Thread with subject: " << subject << " is about to be destroyed" << endl;
	cout << " ------------------------------------------------------------------------------------------------------ " << endl;
	return;
}

void Thread::print(void)const{ // Print the thread
	cout << " ->" << subject << endl;
	cout << "   " << creator << " --- ";
	creation_date.print();
	cout << endl << " ______Thread posts______" << endl <<  endl;
	for(int i=0; i<postnum; i++){
		list[i]->print();
	}
	return;
}

string Thread::getSubject()const{ // Return the Thread's subject
	return subject;
}

bool Thread::findAndPrint(const int id)const{ // Search the Thread for a Post with id and print it if it exists
	for(int i=0; i<postnum; i++){
		if(list[i]->getID()==id){
			list[i]->print();
			return 1;
		}
	}
	return 0;
}
