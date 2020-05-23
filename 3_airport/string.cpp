#include <ctime>
#include <string>
#include <cstdlib>
#include <iostream>
#include "string.h"

using namespace std;

// Some random data stored in static arrays as a small "database"
// Could go in a text file if more data was needed
static const String Names[10]={"izambo", "errikos", "spyros", "nikosPerdikopanis", 
"alexkalts", "vaggelisd", "pstamat", "harry", "stef", "sdi1800164"};
static const String Titles[10]={"A330-300", "A330-200", "A321", "A320", 
"A319", "A350-800", "A350-900", "A350-1000", "Beluga", "A380-900"};

// Used to produce better random results every time the program runs
static unsigned int seed=time(NULL);


// Constructors + Destructor
String::String(){
	cout << " String " << id << " just created!" << endl;
}
String::String(const char *s):str(s){
	cout << " String " << id << " just created!" << endl;
}
String::String(const std::string s):str(s){
	cout << " String " << id << " just created!" << endl;
}
String::String(const String &s){
	id=s.getId();
	str=s.getStr();
	cout << " String " << id << " just created!" << endl;
}
String::~String(){
	cout << " String " << id << " just destroyed!" << endl;
}
	

// Getter
const string String::getStr()const{ return str; }


// Virtual Functions
Object *String::clone(){
	String *obj=new String(*this);
	return obj;
}
String String::toString()const{
	String tmp;
	// Pass the object id
	tmp.concat(">Id= ");
	tmp.concat(int_to_String(id));

	// Pass the string itself
	tmp.concat(" String= ");
	tmp.concat(str);

	return tmp;
}
bool String::equal(const Object *obj)const{
	if(id!=obj->getId()){ return 0; }
	if(str!=((String *)obj)->getStr()){ return 0; }
	return 1;
}

// The requested functions
int String::length()const{ return str.length(); }

void String::print()const{
	std::cout << str << std::endl;
}
int String::at(const int index)const{
	if(index<str.length()){		// If the string is big enough
		return str.at(index);	// Return the char from the required position
	}
	else{ return -1; }
}
void String::updateAt(const int index, const char c){
	if(index<str.length()){			// if the string is big enough
		string tmp(1, c); 			// create a string with only one char
		str.replace(index, 1, tmp); // finally replace the char in the required position
	}
	return;
}
void String::concat(const char *s){
	string tmp(s);
	str+=tmp;
}
void String::concat(const string s){
	str+=s;
}
void String::concat(const String& s){
	str+=s.str;
}
void String::clear(){
	str.clear();
}


// Support functions for additional functionality for ToString
const String int_to_String(unsigned int n){
	String tmp(to_string(n));
	return tmp;
}
const String bool_to_String(bool val){
	if(val){
		String tmp("1");
		return tmp;
	}
	String tmp("0");
	return tmp;
}
const String& randName(){
	srand(seed++);
	return Names[ rand()%10 ];
}
const String& randTitle(){
	srand(seed++);
	return Titles[ rand()%10 ];
}
void print(const String& s){
	std::cout << s.getStr() << std::endl;
}
