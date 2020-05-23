// Giannis Rovithakis | sdi1800164 | Oop assignment 2
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
./oop2

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

1. We can easily, with not many changes also make the forum threads also into a list instead of an array.
In that case we could completely remove the namespace(.h/.cpp) files since the program would be able to run
dynamically. But data structures are not the point of this assignment.
I actually attempted to create a linked list template to use for both posts and threads, but i run into 
problems so i quit the idea and moved on with the safe solution.

2. The same general notes from assignment 1 README apply

> Date, random and namespace implementations are exactly the same with assignment 1. See their
comments on its README.

> Post:
	I added a constructor without parameters that sets "garbage" to the post node
and -1 as post id to "flag" this post as a dummy so it wont print out creation/deletion messages.
Since this constructor is used externally from postlist it must be public. I made these changes in order to 
get cleaner output since the way i chose to implement postlist would fill the output with useless 
info.
	The rest of the Post class info is the same with the previous version so for more see README of
assignment 1.

>Thread:
	I made minor nessesary changes to the way thread handles the list of posts since i changed 
the implementation from the first exercice from array of post to a linked list. The general idea,
design and functionallity remains the same with assignment 1.

>Forum:
	I just added the print_sorted function everything else remains the same

>Postlist:
	A simple linked list struct just to store posts, all the functions are accessors or mutators 
so they are all public. Data members are private for security. The public constructor takes no 
parameters and creates the first "dummy node" only to make the struct ready for push. Its the one 
that is used from outside the class to initialize it and get it ready for push. 
The private constructor takes a post, and creates a list node with that post (used from push only). 
	Norally in a similar situation i would make a list of pointers to posts in order to avoid creating and 
deleting class objects (it is very easy to change the current implementation to this) but from the assignment 
explanations and the drawing i understood that we should have a list of posts in every tree node.

>BSTree:
	Its practically a data structure so i made it a struct.
The public constructor is used for creating a tree from a thread,
the other two constructors are used for expanding and merging trees internally only so they are private.
Only the mutator merge and the accessor print are public to provide the functionality required.
The functionality is explained pretty good in the comments.

> Main just runs a test on the input from namespace and then does exactly what the exercice asks.

// You can also take a look in the comments
// I dont know what else to say, most other things are simple and self-explanatory.
// In case i forgot to make anything clear, missed something important, or for any possible
// ideas and feedback, please feel free to contact me. ( sdi1800164@di.uoa.gr )