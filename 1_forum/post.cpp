#include <iostream>
#include "post.h"

using namespace std;

int Post::idcount=0; // initialize it

Post::Post(const Date& dt, const int i, const string t, const string c, const string txt)
	:creation_date(dt), id(i), title(t), creator(c), text(txt){
	print();
}

Post::~Post(){ cout << "     Post number: " << id << " is about to be destroyed" << endl; }

void Post::print()const{
	cout << "   Post id:  " << id << endl;
	cout << "   Title:    " << title << endl;
	cout << "   Creator:  " << creator << endl;
	cout << "   Created:  ";
	creation_date.print();
	cout << text << endl;
	cout << "________________________________________________________________" << endl << endl;
}

int Post::getID(void)const{ return id; }

int Post::getCurID(){ return idcount; }

int Post::getCurIDInc(){ return idcount++; }