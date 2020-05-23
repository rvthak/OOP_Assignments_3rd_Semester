#ifndef THREAD
#define THREAD

#include <string>
#include "date.h"
#include "post.h"

class Thread{
	public:
		Thread(const std::string th, const std::string cr, Date& dt);
		~Thread();

		void print(void)const;					// Print the thread
		std::string getSubject()const; 			// Return the Thread's subject
		bool findAndPrint(const int id)const;	// Search the Thread for a Post with id and print it if it exists

	private:
		int postnum;			// A counter of how many posts are currently in the thread
		std::string subject;	// The Thread's subject
		std::string creator;	// The Thread's creator
		Date creation_date;		// The Thread's creation date
		Post **list;			// A list of the Thread's posts
};

#endif