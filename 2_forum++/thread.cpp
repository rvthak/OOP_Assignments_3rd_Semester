#include <iostream>
#include "namespace.h"
#include "thread.h"
#include "random.h"

using namespace std;

Thread::Thread(const string sb, const string cr, Date& dt)
	:subject(sb), creator(cr), creation_date(dt){
	postnum=0;
	// basic setup done
	
	// add some posts
	Post tmp;
	for(int i=0; i<Values::Number_Of_Posts; i++){
		dt.random(); 	// get a random gate
		tmp.set(dt, Post::getCurIDInc(), randomPhrase(), randomName(), randomText()); // set the post data
		tmp.print(); 	// print the post data
		list.push(tmp); // push it on the list
		postnum++;
	}
	
	tmp.set(dt, -1, "", "", ""); // set id to -1 to disable destructor output
	
	cout << endl << " ------------------------------------------------------------------------------------------------------ " << endl;
	cout << "> Thread with subject: " << subject << " has just been created!" << endl;
	cout << " ------------------------------------------------------------------------------------------------------ " << endl << endl << endl;
	return;
}

Thread::~Thread(){
	cout << " ------------------------------------------------------------------------------------------------------ " << endl;
	cout << "> Thread with subject: " << subject << " is about to be destroyed" << endl;
	cout << " ------------------------------------------------------------------------------------------------------ " << endl;
	return;
}

void Thread::print()const{ // Print the thread
	cout << subject << endl;
	cout << creator << endl;
	creation_date.print();
	list.print();
	return;
}

string Thread::getSubject()const{ return subject; } // Return the Thread's subject

int Thread::getPostCount()const{ return postnum; } // Return the Thread's subject

bool Thread::findAndPrint(int id)const{ // Search the Thread for a Post with id and print it if it exists
	Post *ls;
	for(int i=1; i<=postnum; i++){
		ls=list.popN(i);
		if(ls->getID()==id){
			ls->print();
			return 1;
		}
	}
	return 0;
}

Post *Thread::getNpost(int n){ return list.popN(n); } // return pointer to list's nth post

PostList *Thread::getPostList(){ return &list; } // Return a pointer to thread's postlist
