#ifndef FORUM
#define FORUM

#include <string>
#include "thread.h"

class Forum{
	public:
		Forum(const std::string);
		~Forum();
		
		void print()const;								// Print a list of all the threads of the forum
		void print_sorted()const;						// Turn the forum into a bst and then print it
		void printThread(const std::string sub)const;	// If there is a Thread with the given subject, print it
		void printPost(const int id)const;				// Search all the forum for the post with id and print it if it exists
		void printRandomPosts(const int amount)const;	// Using printPost print amount DIFFERENT random posts
	private:
		int threadnum;		// A counter of how many threads are currently in the forum
		std::string title;	// The forum's title
		Thread **list;		// A list of the forum's threads
};

#endif