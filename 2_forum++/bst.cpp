#include <iostream>
#include "bst.h"

using namespace std;

BSTree::BSTree(Thread& th){ // Take the thread's posts one by one and insert them all to the tree creating the needed users
	int i=2; // 2 cause 0 is the dummy and 1 we take first manually
	Post *tmp;
	PostList *ls=th.getPostList();

	// Initialize left and right
	left=NULL;
	right=NULL;
	// Postlist is created and initialized automatically with default constructor => dummy node ready
	
	// Get first post name to use for first tree node name and add the post
	tmp=ls->popN(1);
	creator=tmp->getName();
	list.push(*tmp);

	// Handle the rest of the thread's posts:
	tmp=ls->popN(i);
	while(tmp!=NULL){
		addPost(*tmp);
		i++;
		tmp=ls->popN(i);
	}
	return;
}

BSTree::BSTree(Post& p){ // Create a tree node, initialized from a single post
	// Initialize left and right
	left=NULL;
	right=NULL;
	// Postlist is created and initialized automatically with default constructor => dummy node ready

	// Set name and add the post
	creator=p.getName();
	list.push(p);
	return;
}

BSTree::BSTree(const string name){ // Create a tree node, initialized from a single string 
	// the postlist gets created empty only with dummy but is ready for push
	// used for ease when merging trees when there is need to copy over a whole postlist
	left=NULL;
	right=NULL;
	creator=name;
	return;
}

BSTree::~BSTree(){ // just free the tree struct
	// when we trigger the deletion of a tree node it checks if it has child nodes to delete also
	cout << " Tree node for creator: " << creator << " is about to be destroyed" << endl;
	if(left!=NULL){ delete left; }
	if(right!=NULL){ delete right; }
	return;
}

void BSTree::addPost(Post& p){ // Recursive function - add a given post to the tree if creator doesnt exist add him too // used mainly for constructing BSTree
	string name=p.getName();		// Get the creator name
	if(name.compare(creator)==0){	// If we are on the correct node 
		list.push(p);				// copy over the postlist
	}
	else if(name.compare(creator)<0){	// if the name is "smaller" we move left on the tree
		if(left!=NULL){			// if there is already a node left
			left->addPost(p);	// move there recursively to check the name
		}
		else{	// else, the post belongs there => create a new tree node initialized with the post
			left=new BSTree(p);
		}
	}
	else{	// Same in case the name is "bigger" and we need to do the same but go right
		if(right!=NULL){
			right->addPost(p);
		}
		else{
			right=new BSTree(p);
		}
	}
	return;
}

void BSTree::print()const{ // Recursive function - print all the tree inorder (with creator name)
	if(left!=NULL){ left->print(); }
	list.print();
	if(right!=NULL){ right->print(); }
	return;
}

void BSTree::mergeWith(BSTree& tree){ // Recursive function - Merges two BSTrees - pushes the parameter on in the targeted one
	// we first add to the main tree the contents of the current parameter tree node
	insertNode(tree); 

	// if this tree node has children call merge recursively to merge them with main tree too
	if( tree.left!=NULL ){
		mergeWith( *(tree.left) );
	}
	
	if( tree.right!=NULL ){
		mergeWith( *(tree.right) );
	}
	return;
}

void BSTree::insertNode(BSTree& tree){	// Recursive function - gets a tree node and moves deeper into the tree until it finds the correct place to add it // used mainly for merging
	// very similar functionality with addPost function
	if(tree.creator.compare(creator)==0){	 // if we find a tree node from the creator we need
		copyPosts(tree); // copy over all posts
	}
	else if(tree.creator.compare(creator)<0){	// else move deeper until we find the correct location
		if(left!=NULL){
			left->insertNode(tree);		// and either copy the posts if there is already a tree node for this creator
		}
		else{
			left=new BSTree(tree.creator);	// either create one and then copy the posts
			// copy over posts
			left->copyPosts(tree);
		}
	}
	else{	// same for the right
		if(right!=NULL){
			right->insertNode(tree);
		}
		else{
			right=new BSTree(tree.creator);
			// copy over posts
			right->copyPosts(tree);
		}
	}
	return;
}

// just copies over the whole post list of the parameter tree node to the targeted main tree node
void BSTree::copyPosts(BSTree& tree){
	int i=1;
	Post *tmp;
	// if the ith pop-ed post is not null, push it and move to the next
	while( (tmp=tree.list.popN(i) )!=NULL){
		list.push(*tmp);
		i++;
	}
	return;
}
