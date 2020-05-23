#ifndef THREAD
#define THREAD

#include <string>
#include "postlist.h"
#include "post.h"
#include "date.h"

class Thread{
	public:
		Thread(const std::string sb, const std::string cr, Date& dt);
		~Thread();

		void print(void)const;					// Print the thread
		std::string getSubject()const; 			// Return the Thread's subject
		bool findAndPrint(const int id)const;	// Search the Thread for a Post with id and print it if it exists
		int getPostCount()const;				// Return postnum
		
		Post *getNpost(int n); 		// return pointer to list's nth post | n=1 == 1st real node i dont count the dummy
		PostList *getPostList();	// Return a pointer to thread's postlist

	private:
		int postnum;			// A counter of how many posts are currently in the thread
		std::string subject;	// The Thread's subject
		std::string creator;	// The Thread's creator
		Date creation_date;		// The Thread's creation date
		PostList list;			// A list of the Thread's posts
};

#endif