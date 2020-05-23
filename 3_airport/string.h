#ifndef STRING 
#define STRING

#include "object.h"

class String : public Object
{
	private:
		std::string str; // The string itself

	public:
		String(); 					 // Initialize an empty string
		String(const char *s); 		 // Initialize a string with a char *
		String(const std::string s); // Initialize a string with a string
		String(const String &s);	 // Class copy constructor
	
		virtual ~String(); // Simple Destructor

		// The needed virtual functions
		virtual Object *clone();
		virtual String toString()const;
		virtual bool equal(const Object *obj)const;

		// The requested getter
		const std::string getStr()const; // Get the internal std::string
		
		// The requested functions
		int length()const;								// Returns the length of the string
		void print()const;								// Prints the string
		int at(const int index)const;					// Returns the char from "index" position, EOF if there is no "index" position
		void updateAt(const int index, const char c);	// Changes the char of "index" position if possible
		void concat(const char *s);						// Copies the parameter string after the targeted one
		void concat(const std::string s);				// Copies the string of the parameter string object to the targeted
		void concat(const String& s);					// Copies the string of the parameter String object to the targeted
		void clear();									// Clear the string
};

const String int_to_String(unsigned int n);	// Turns the given unsigned int to a string and returns it
const String bool_to_String(bool val);		// Turns the given bool to a string and returns it

const String& randName();	// Returns a random name
const String& randTitle();	// Returns a random plane identifier

void print(const String& s); // A variation of print

#endif