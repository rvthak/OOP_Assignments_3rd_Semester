#ifndef LIST
#define LIST

#include "post.h"

struct PostList{
	public:
		PostList();		// Default constructor for creating the first node (dummy so we dont get spam messages)
		~PostList();

		void push(Post& data); 			// Add given post to Postlist
		Post *popN(const int n)const;	// Return pointer to post number n (with 1 being the first real post not the dummy)
		void print()const;				// Print all the list skipping the targeted one (to skip the dummy)
		void printNode()const;			// Print the target node's data

	private:
		PostList(Post& data);	// Constructor used for push
		Post data;
		PostList *next;
};

#endif