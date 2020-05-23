#ifndef PLANE_COMPONENT
#define PLANE_COMPONENT

#include "object.h"
#include "string.h"

class SecurityEmployee;
class MaintenanceEmployee;
class CleaningEmployee;

//========================================

class PlaneComponent : public Object
{
	public:
		// Constructor + Destructor
		PlaneComponent();
		virtual ~PlaneComponent();

		// The needed virtual functions
		virtual Object *clone()=0;
		virtual String toString()const;
		virtual bool equal(const Object *obj)const;

		// PlaneComponent virtual functions
		virtual bool ready_check()const=0;
		virtual void process(SecurityEmployee& emp);
		virtual void process(MaintenanceEmployee& emp);
		virtual void process(CleaningEmployee& emp);

		// Setters
		virtual void setSec(bool v);
		virtual void setMnt(bool v);
		virtual void setCln(bool v);

		// Getters
		virtual bool getSec()const;
		virtual bool getMnt()const;
		virtual bool getCln()const;
		const String& getDesc()const;

	protected:
		// The component's description describes its type (example PassengerCompartment)
		String desc; 

		// Boolean variables used to check work state
		bool securityCheck;
		bool maintenanceCheck;
		bool cleanCheck;

		const String *getDescPtr()const{ return &desc; }
};

//========================================

class PassengerCompartment : public PlaneComponent
{
	public:
		// Constructors + Destructor
		PassengerCompartment();
		PassengerCompartment(const PassengerCompartment& obj);
		virtual ~PassengerCompartment();

		// The needed virtual functions
		virtual Object *clone();
		virtual String toString()const;
		virtual bool equal(const Object *obj)const;

		// PlaneComponent virtual functions
		virtual bool ready_check()const;
		virtual void process(CleaningEmployee& emp);
		virtual void process(SecurityEmployee& emp);
		virtual void process(MaintenanceEmployee& emp);

		// Getter
		PassengerCompartment *getIntrn()const;

	private:
		// Possible location of another passenger compartment, NULL if empty
		PassengerCompartment *intrn; 

		// An internal constructor used only from the public constructor
		// only in case a passenger compartment is split in two, to ensure the
		// new passenger compartment wont also be split
		PassengerCompartment(int dummy);
};

//========================================

class PrivateCompartment : public PlaneComponent
{ // makes more sense to make abstruct but they say no so why not
	public:
		// Constructors + Destructor
		PrivateCompartment();
		PrivateCompartment(const PrivateCompartment& obj);
		virtual ~PrivateCompartment();

		// The needed virtual function
		virtual Object *clone();

		// PlaneComponent virtual function
		virtual bool ready_check()const;
};

class EquipmentCompartment : public PrivateCompartment
{
	public:
		// Constructors + Destructor
		EquipmentCompartment();
		EquipmentCompartment(const EquipmentCompartment& obj);
		virtual ~EquipmentCompartment();

		// The needed virtual function
		virtual Object *clone();

		// PlaneComponent virtual function
		virtual bool ready_check()const;
};

class CargoBay : public PrivateCompartment
{
	public:
		// Constructors + Destructor
		CargoBay();
		CargoBay(const CargoBay& obj);
		virtual ~CargoBay();

		// The needed virtual functions
		virtual Object *clone();
		virtual String toString()const;
		virtual bool equal(const Object *obj)const;

		// PlaneComponent virtual functions
		virtual bool ready_check()const;
		virtual void process(CleaningEmployee& emp);
		virtual void process(SecurityEmployee& emp);
		virtual void process(MaintenanceEmployee& emp);
		
		// Getter
		EquipmentCompartment *getEqc()const;
	private:
		EquipmentCompartment *eqc;
};

//========================================

#endif