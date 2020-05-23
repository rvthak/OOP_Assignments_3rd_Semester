// Giannis Rovithakis | sdi1800164 | Oop Java assignment
// The program was Developed on Windows 10 64-bit

> To compile the program:
1. cd to the oopjava directory with "cd oopjava"
2. compile the files with "javac *.java"
3. cd back to the parent directory with "cd .."
4. run the program with "java oopjava.OopJava"

=> Implementation Info:

> General Notes:

1. The classes are built as independent modules and they can work independently
(provided their required dependencies)

2. Despite not required from the assignment i implemented the functions
clone, toString and equals, and overridden the corresponding Object class 
functions to ensure the functionality is correct. They work fine for each
class independently (provided its required dependencies)

3. As requested, every class has getters for all its data members.

4. For all non-abstract classes, i also implemented a copy constructor to use in 
clone function

5.The only exception is: (4 simple setters)
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

6. The code works fine without the @Override tags but i added them to ensure that
is works correctly in case of different reference handling from the client program

7. Whenever it is needed, a class has protected members allow access from its
subclasses but not externally

8. I would make PrivateCompartment an abstract class but there was a conflict
in DIT Lists so i left it as it is.

9. For the object ids i just implemented a very basic system for every class-family
The new objects get their id from their base class which is unique in their "family"
I dont think we needed anything more complex in this assignment (Another 
cleaner option would be to make a "master" class for all of our classes that just 
has an id and handle it that way)

10. Sorry for the name "oopjava" instead of "askisijava" but the submit notes 
were not released when i completed the assignment so i decided there was no reason 
to go back and change the name

> Main Notes:
-No comments on main, everything is pretty simple

> Plane Notes:
-I overloaded the proccess function in order to give it different functionality
depending on the Employee type that gets passed as a parameter, to allow different
types of employees do different jobs

> Plane Component Notes: ( Includes Plane Component sub types)
-Once again, i overloaded the proccess function (to ensure that the cleaning employee 
does not work on the internal EquipmentCompartment of CargoBay
-I re-implemented(overridden) the PlaneComponent's general function "proccess" for the two 
subclasses that needed a different implementation( PassengerCompartment and CargoBay ). (same for equal())
-PassengerCompartment has a "pseudo" 50% chance to have another internal one. A second,
private class "dummy" constructor is used to ensure that the internal 
PassengerCompartment can't have another one inside it.
-Since it is not clear what exactly is the requested functionality for Private
Compartment, i gave it the requested characteristics and considered it always ready,
requiring no work.

> Employee Notes: ( Includes Employee sub types)
-i just override some functions for different employee type behaviour.  Nothing else 
to comment. Everything is simple and straightforward, or has been already  covered from previous comments.

// You can also take a look in the comments
// I dont know what else to say, most other things are simple and self-explanatory.
// In case i forgot to make anything clear, missed something important, or for any 
// possible ideas and feedback, please feel free to contact me.
// ( sdi1800164@di.uoa.gr )