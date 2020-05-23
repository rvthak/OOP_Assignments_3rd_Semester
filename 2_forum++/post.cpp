#include <iostream>
#include "post.h"

using namespace std;

int Post::idcount=0; // initialize it

Post::Post(const Date& dt, const int i, const std::string t, const std::string c, const std::string txt)
	:creation_date(dt), id(i), title(t), creator(c), text(txt){
	print();
}

Post::~Post(){
	if( id!=-1){
		//cout << " Post number: " << id << " is about to be destroyed" << endl; // 1rst exercice output
		// i added the creator to the output to make it easier to understand what is happening
		cout << "     Post number: " << id << " from " << creator << " is about to be destroyed" << endl; 
	}
}

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

void Post::set(Post& post){
	id=post.id;
	title=post.title;
	creator=post.creator;
	creation_date.set(post.creation_date);
	text=post.text;
	return;
}

void Post::set(Date& dt, const int i, const std::string t, const std::string c, const std::string txt){
	id=i;
	title=t;
	creator=c;
	creation_date.set(dt);
	text=txt;
	return;
}

std::string Post::getName()const{ return creator; }

int Post::getCurID(){ return idcount; }

int Post::getCurIDInc(){ return idcount++; }