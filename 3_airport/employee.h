#ifndef EMPLOYEE
#define EMPLOYEE

#include "object.h"
#include "string.h"

class PlaneComponent;

//========================================

class Employee : public Object
{
	public:
		// Constructor + Destructor
		Employee();
		~Employee();

		// The needed virtual functions
		virtual Object *clone()=0;
		virtual String toString()const;
		virtual bool equal(const Object *obj)const;

		// Employee virtual functions
		virtual void workOn(PlaneComponent& cmp)=0;	// Sets the Employee to work on the parameter component
		virtual void report()const=0;				// Get the Employee's work report

		// The required getters
		const String& getName()const;	// get the employee's name
		bool checkWork()const;			// get the employee's current work state

		// Extra setter
		void workComplete();	// Set the Employee's work state to completed in order to be able to get a final report later on
		
	protected:
		String name;  // The employee's name
		bool worked;  // The employee's work state | set to 1 when job is done

		const String *getNamePtr()const{ return &name; } // Extra getter used from equal
};

//========================================

class SecurityEmployee : public Employee
{
	public:
		// Constructors + Destructor
		SecurityEmployee();
		SecurityEmployee(const SecurityEmployee& obj);
		~SecurityEmployee();

		// The needed virtual functions
		virtual Object *clone();

		// Employee virtual functions
		virtual void workOn(PlaneComponent& cmp);
		virtual void report()const;
};

class MaintenanceEmployee : public Employee
{
	public:
		// Constructors + Destructor
		MaintenanceEmployee();
		MaintenanceEmployee(const MaintenanceEmployee& obj);
		~MaintenanceEmployee();

		// The needed virtual functions
		virtual Object *clone();

		// Employee virtual functions
		virtual void workOn(PlaneComponent& cmp);
		virtual void report()const;
};

class CleaningEmployee : public Employee
{
	public:
		// Constructors + Destructor
		CleaningEmployee();
		CleaningEmployee(const CleaningEmployee& obj);
		~CleaningEmployee();

		// The needed virtual functions
		virtual Object *clone();

		// Employee virtual functions
		virtual void workOn(PlaneComponent& cmp);
		virtual void report()const;
};

//========================================

#endif