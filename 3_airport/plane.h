#ifndef PLANE
#define PLANE

#include "object.h"
#include "string.h"
#include "employee.h"
#include "planeComponent.h"

class Plane : public Object
{
	public:
		// Constructors + Destructor
		Plane();
		Plane(const Plane& obj);
		virtual ~Plane();

		// The needed virtual functions
		virtual Object *clone();
		virtual String toString()const;
		virtual bool equal(const Object *obj)const;

		// The requested getters
		String get_title()const;
		unsigned int get_capacity()const;
		CargoBay *get_cargoBay()const;
		EquipmentCompartment **get_eqpCmp()const;
		PassengerCompartment **get_pasCmp()const;

		// proccess overloaded to serve the different employee types.
		// Get the employee to work on the plane, every employee does different
		// job so we have a different function for each Employee type
		void process(SecurityEmployee& emp);
		void process(MaintenanceEmployee& emp);
		void process(CleaningEmployee& emp);

		bool ready_check();	// Returns 1 if the plane is ready to take off

	protected:
		String title;			// The airplane identifier
		unsigned int capacity;	// The airplane capacity

		CargoBay *crg;				// The Cargo bay area (constructor can only make one in current implementation)
		EquipmentCompartment **eqc;	// The Equipment Compartment area (constructor makes 3 of them)
		PassengerCompartment **pas;	// The Passenger Compartment area (constructor makes enough for capacity)

		// Getters needed for equal()
		const String *get_title_Ptr()const{ return &title; }
		const EquipmentCompartment *get_eqp(int i)const{ return eqc[i]; } // Returns the ith EquipmentCompartment
		const PassengerCompartment *get_pas(int i)const{ return pas[i]; } // Returns the ith PassengerCompartment
};

#endif