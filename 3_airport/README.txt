// Giannis Rovithakis | sdi1800164 | Oop assignment 3
// The program was Developed on pop!_os 19.10 64-bit
// The compiler used during development is g++


 => For simplicity I chose to build the program using a makefile

> Compile the program using command:
make

> Debug the program using commands:
make gdb 	// for gdb
make vg		// for valgrind
( There are more sophisticated options available for memory leaks, read the makefile itself )

> Clean the object files with:
make clean

> Run the program with:
./oop3
( I suggest running the program in full screen console to make reading easier)
( I use c++11 for the to_string() function in string.cpp > int_to_string() )
# The makefile i am using was made using a tool of mine: https://github.com/rvthak/Makefile-Maker
# The github version is quite old, this makefile was made with the new version that is not yet
# complete (Its a much more professional, clean and feature-rich version). In case you need any 
# info about it or the source code let me know. ( sdi1800164@di.uoa.gr )


 => Implementation Info:

> General Notes:

1. The output is long and bloated with mostly useless constructor/destructor
prints, the assignment requested that we add them so sorry for the long output

2. The classes are built as independent modules and they can work independently
(provided their required dependencies) (clone_encrypt_and_print also works with
every other class)

3. The only reason i wrote the "virtual" tag before every virtual function, even in
subclasses when it was not needed, is to make it easier for me to remember that this
function is virtual during development

4. As requested, every class has getters for all its data members.

5. For all non-abstruct classes, i also implemented a copy constructor to use in 
clone function

6. As requested, all the classes provide externally only the requested functionality.
The only exception is: (4 simple setters)
	The Employee workComplete() function that is just a setter, that when called,
sets the targeted employee's work state to complete after he is done visiting
EVERY existing compartment that he needs to workOn. His work state is later used to
ensure he completed his job when calling report(). ( The assignment did not give a
clear explanation of report function and i could not draw any conclusion from what
i read at DIT lists so i implemented it in a way that made more sense to me).
	This goes together with three other setters in PlaneComponent: setSec, setMnt,
setCln that set the "job flags" after an employee has finished his job in the
compartment, so when we run ready check we have a way to check if every compartment
has passed the required "tests".
> I know this collides with the assignment requirement to have no other external
functionality but there is no other way to achieve the communication needed for 
the required functionality(if there is another way please let me know). The 
assignment was NOT clear to exactly what it needed and i despite the time i spent 
trying to figure it out in Lists i could not reach a clear conclusion.
Please in the future try to be more clear on the implementation info to save us
from confusion and wasting time trying to figure out what the assignment needs 
and also save you time from trying to explain to us.

7. Whenever it is needed, a class has protected members allow access from its
subclasses

8. I would make PrivateCompartment an abstruct class but there was a conflict
in DIT Lists so i left it as it is.

> Main Notes:
-Main and clone_encrypt_and_print do exactly what they are supposed to do, with
some added prints for easier understanding of the program's state
- In clone_encrypt_and_print the assignment asks to print the one or two chars from
the middle of the string after the concat. concatenating two same stings, is like
doubling the char count => We will always have to print two chars. Why does the
assignment give a chance of one char print? (despite that, i implemented the
needed code, but it just never runs)

> Object Notes:
-Needed the destructor virtual to ensure the correct destructor will be called each 
time we delete an object created by clone()
-Since object is the abstract "Master-class" we have no information about the 
subclasses so we need to make most of its functions pure virtual, and implement them 
specifically for each sub class, to achieve the needed functionality.

> Plane Notes:
-I overloaded the proccess function in order to give it different functionality
depending on the Employee type that gets passed as a parameter, to allow different
types of employees do different jobs

> Plane Component Notes:
-Once again, i overloaded the proccess function (to ensure that the cleaning employee 
does not work on the internal EquipmentCompartment of CargoBay
-I re-implemented the PlaneComponent's general virtual function "proccess" for the two 
subclasses that needed a different implementation( PassengerCompartment and CargoBay ).
(same for equal())
-PassengerCompartment has a "pseudo" 50% chance to have another internal one. A second,
private class "dummy" constructor is used to ensure that the internal 
PassengerCompartment can't have another one inside it.
-Since it is not clear what exactly is the requested functionality for Private
Compartment, i gave it the requested characteristics and considered it always ready,
requiring no work.
-In .h i wrote the EquipmentCompartment class above the CargoBay class so i wont
need to make a forward declaration of EquipmentCompartment

> Employee Notes:
-Nothing to comment. Everything is simple and straightforward, or has been already 
covered from previous comments

> String Notes:
-A basic string class implementation based on the standard c++ string
-For the random data needed in some cases and for simplicity i decided to add a 
couple of String arrays for easy to access data for the corresponding functions
-Decided for ease of use to implement a variety of copy constructors and overload
the concat function. Also added OUTSIDE the class a couple of converting functions
and random returners from the above stored String arrays + A variation of print
for ease of use

// You can also take a look in the comments
// I dont know what else to say, most other things are simple and self-explanatory.
// In case i forgot to make anything clear, missed something important, or for any 
// possible ideas and feedback, please feel free to contact me.
// ( sdi1800164@di.uoa.gr )
