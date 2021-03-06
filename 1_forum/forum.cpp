#include <iostream>
#include <cstdlib>
#include <ctime>
#include "date.h"
#include "forum.h"
#include "random.h"
#include "namespace.h"

using namespace std;

Forum::Forum(const std::string ttl):title(ttl){
	Date date;		// Temp date for random values
	threadnum=1; 	// Because we manually write the first thread
	list=new Thread*[ Values::Max_Number_Of_Threads ];	// Allocate memory for the thread array
	// basic setup done

	// we manually write the first thread
	date.random();	// Get a random date
	list[0]=new Thread("Κανόνες και χρήσιμες πληροϕορίες", randomName(), date);

	// add some more threads
	while( threadnum<Values::Number_Of_Threads ){
		date.random();
		list[threadnum]=new Thread( randomPhrase(), randomName(), date);
		threadnum++;
	}
	cout << "#########################################################################################" << endl;
	cout << "###### Forum with title: " << title << " has just been created!" << endl;
	cout << "#########################################################################################" << endl;
	return;
}

Forum::~Forum(){
	//free the space we previously allocated
	for(int i=0; i<threadnum; i++){
		delete list[i];
	}
	delete[] list;
	cout << "#########################################################################################" << endl;
	cout << "###### Forum with title: " << title << " is about to be destroyed" << endl;
	cout << "#########################################################################################" << endl;
	return;
}

void Forum::print(void)const{ // Print all the Forum's Thread subjects
	cout << "> Forum Threads: " << endl;
	for(int i=0; i<threadnum; i++){
		cout << " -" << list[i]->getSubject() << endl;
	}
	return;
}

void Forum::printThread(const string sub)const{ // Find the thread with the given subject and print it
	for(int i=0; i<threadnum; i++){
		if(list[i]->getSubject()==sub){
			list[i]->print();
			return;
		}
	}
	cout << " Could not find Thread with subject: " << sub << endl;
	return;
}

void Forum::printPost(const int id)const{ // Find the post with the given id and print it    // !!serial search not fast can think of a binary way to do it
	for(int i=0; i<threadnum; i++){ // check in every thread
		if( list[i]->findAndPrint(id) ){ return; } // and every one of its posts
	}
	cout << " Post with id: " << id << " not found." << endl;
	return;
}

void Forum::printRandomPosts(const int amount)const{ // Using printPost print amount DIFFERENT random posts
	int i=0, tmp, count=Post::getCurID();
	bool buf[count];
	srand(time(NULL));

	// initialize post buf to 0 = no post printed yet
	for (int k=0; k<count; k++){
		buf[k]=0; 
	}
	
	// print posts ensuring they are all different
	while(i<amount){
		tmp=rand()%count; 	// get a random value in [0,count]
		if(buf[tmp]==0){ 	// if the post with id==tmp has not yet been printed
			printPost(tmp); // print the post
			buf[tmp]=1;		// ensure it wont be printed again
			i++;			// move one step
		}
	}
	return;
}
