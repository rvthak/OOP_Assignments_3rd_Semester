// Giannis Rovithakis | sdi1800164 | Oop assignment 1
// The program was Developed partly on Windows 10 64-bit using wsl and partly on pop!_os 19.10 64-bit
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
./oop1

# The makefile i am using was made using a tool of mine: https://github.com/rvthak/Makefile-Maker
# The github version is quite old, this makefile was made with the new version that is not yet
# complete (Its a much more professional, clean and feature-rich version). In case you need any 
# info about it or the source code let me know. ( sdi1800164@di.uoa.gr )


! IMPORTANT: You can change the options of the program from the namespace.h file
edit the constant values however you like THEN use "make clean" and THEN "make " to compile the 
program to "update" it with the changes ( A better way would be to store them in a file instead 
of a namespace so the program wouldn't need recompilation) ( See explanation below, the program 
can run without changes i have set some defaults)


 => Implementation Info:

> General Notes:

1. I chose to not use "using namespace" command in any of the header files, to avoid possible 
complications and as a generally good programming practice.

2. In this exercise (the first one) for simplicity and in order to save time i chose to use
simple arrays for storing Threads and Posts. They can do the required job and an upgrade to 
using a linked list structure for this porpose is very simple and it can be seen implemented
in the second exercise. ( I implemented it later for the second exersice and since the porpose 
of this exercise is to practice abstruction principles and not data structures, i decided not 
to go back and update the first one).

3. I generaly tried to break down the problem to as many parts as possible and implemented
each one separately and independently. (classes, structs, extra source files...)
So they can also be used independently (if they have the correct/required files)

4. I set whatever i could to const for a cleaner and safer result

5. For random value generation, since it is usually implemented in corresponding functions, in 
order to get a satisfying random result i decided to use a static global variable holding the 
seed for srand, initialized to time from UNIX timestamp with time(NULL). Each time the seed is 
used i increment it to get a different result next time i call the corresponding function since 
srand gets run in the beginning of each function. The seed is ONLY available in the file where 
it is located since it is static(+it holds its value) and does not interfere with anything else.

6. Whenever i needed to pass a struct or a class as a parameter to a function i always passed
a reference to avoid making new objects

7. I know we said its good programming practice to always implement a copy constructor
but the default constructor (bitwise copy) was good enough for what i needed so
i decided not to implement any

> Date Notes: (date.h, date.cpp)
	I decided to use a simple struct with 3 integers to represent date since i just need to 
store  some simple data without any special behaviour. Since all the data members are simple 
integers the Constructor initializes it with a simple initialization list(i added default 
values, in order to have the ability to initialize a Date without parameters whenever needed (
for example when i create a "dummy" date to write on the random dates later) ) and no destructor is needed.
	The data members of the struct (day, month, year) are private since no access to them should 
be possible from outside the class. They can only be accessible from the corresponding accessors 
and mutators ( set, get and random ) that are publicly available (but not used in our case) 
along with the class constructor.


> Post Notes: (post.h, post.cpp)
	I used a class for the post since it does not only store data. At the same moment it has
specific behaviour and traits, it is practically a kind of entity. Its data members are initialized
from the constructor through an initialization list ( ints and strings are fine, data's constructor
is called from the list using the corresponding given parameters). A destructor is once again not 
necessary but its required for the exercise. 
	Once again the Class's data members are private and not accessible from outside. Public accessors
and mutators ( print and getID ) are the only way to interact with them.
	Special note: In order to have unique post ids (needed for the exercise) i used a static integer
counter initialized to 0 from which i get an id and then increment it ( Not a good choice if we plan 
on making a big forum we can run out of ids). idcount is private can only be accessed from its static public functions 
getCurID and getCurIDInc.


// These two are similar so i grouped the comments to avoid writing the same things again
> Thread Notes: (thread.h, thread.cpp)
> Forum Notes: (forum.h, forum.cpp)
	Used classes for the same reason i used a class for post. They are entities. Constructors 
initialize normal members and then allocate an array for the threads or posts and populate
it accordingly with as many members as requested from the Values namespace (namespace.h)
and insert random data from random.h. Destructors just free the previously alocated space.
	Once again the Class data members are private and not accessible from outside. Public accessors
and mutators ( print, printThread, printPost, printRandomPosts, print, getSubject, findAndPrint) are 
the only way to interact with them. Both classes have an extra private integer data member (threadnum
and postnum) used from the other functions internally.


> Namespace Notes: (namespace.h, namespace.cpp)
	As i said in general notes i initially implemented the lists of Threads and Posts using arrays.
The array sizes, how many threads/posts the user wants and how many posts should be printed, should be 
written on the corresponding constants BEFORE the program compiles.
	Along with the constants are some functions to ensure that the given values are correct
and the program can run using them as options.
	I used a namespace for better organization and easy accessibility.


> Random Notes: (random.h, random.cpp)
	Some simple functions grouped with a namespace that holds all the "text data libraries".
I separated them for a more clean result and to make it easier to use them where they are needed
across the program. I chose a namespace(Database) to "group-up" the arrays since they hold similar 
information to stay organized.
	Only the functions are available from outside. They return a random string from the corresponding 
namespace data array. The randomness works with the same way explained above


> Main just runs a test on the input from namespace and then does exactly what the exercice asks.

// You can also take a look in the comments
// I dont know what else to say, most other things are simple and self-explanatory.
// In case i forgot to make anything clear, missed something important, or for any possible
// ideas and feedback, please feel free to contact me. ( sdi1800164@di.uoa.gr )
