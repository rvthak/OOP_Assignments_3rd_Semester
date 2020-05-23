#ifndef BST
#define BST

#include <string>
#include "postlist.h"
#include "thread.h"
#include "post.h"

struct BSTree{
	public:
		BSTree(Thread& th); 		// Take the thread's posts one by one and insert them all to the tree creating the needed users
		~BSTree();

		void mergeWith(BSTree& tree);	// Recursive function - Merges two BSTrees - pushes the parameter on in the targeted one
		void print()const;				// Recursive function - print all the tree inorder (with creator name)

	private:
		// These three functions are needed only internally so i made them private
		BSTree(Post& p); 			// Create a tree node, initialized from a single post
		BSTree(std::string name);	// Create a tree node, initialized from a single string 

		void addPost(Post& p);			// Recursive function - add a given post to the tree if creator doesnt exist add him too // used mainly for constructing BSTree
		void insertNode(BSTree& tree); // Recursive function - gets a tree node and moves deeper into the tree until it finds the correct place to add it // used mainly for merging
		void copyPosts(BSTree& tree);  // Copies over all the posts to the target the source's postlist (adds them in the end)
		std::string creator;	// The name of the creator of this node's posts
		BSTree *left;			// The left and right children of the node NULL if the dont exist
		BSTree *right;
		PostList list;			// The node's list of posts
};

#endif