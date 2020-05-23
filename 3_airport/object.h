#ifndef OBJECT
#define OBJECT

class String; // Needed String class Forward declaration

class Object{

	public:
		// Constructor + Destructor
		Object();
		virtual ~Object(); // Needed virtual to ensure the correct destructor will be called each time after deleting a pointer
		
		// The requested functions
		virtual Object *clone()=0;		   				// Returns a pointer to a clone of the targeted object
		virtual String toString()const=0;  				// Returns a String with all of its data member values
		virtual bool equal(const Object *obj)const=0;	// Returns 1 if the target Object is a copy of the parameter one
		bool identical(const Object& obj)const;			// Returns 1 if the target Object and the parameter one are identical in memory 

		// The requested getter
		unsigned int getId()const;	// Returns the object's id
	
	protected:
		unsigned int id; // The object's unique id

		// Used only from class constructor for unique id functionality
		static unsigned int idCount;	// Unique id counter
		static unsigned int getNewId();	// Returns a unique id for a new object
};

#endif