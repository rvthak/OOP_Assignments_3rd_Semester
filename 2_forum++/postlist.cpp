#include "postlist.h"
using namespace std;

PostList::PostList(){ // dummy node constructor
	// first/"dummy" post is auto-initialized by its default constructor to the needed values (id=-1)
	next=NULL;
	return;
}

PostList::PostList(Post& data):data(data){ // normal use constructor 
	// the post data node is created from the list initialized correctly - no copy constructor overloading needed in our case
	next=NULL;
	return;
}

PostList::~PostList(){
	if( this->next != NULL ){
		delete this->next;
	}
	return;
}

void PostList::push(Post& data){ // Add given post to Postlist
	PostList *ptr=this; // start from the second node since the first one is a dummy
	// reach the end of the list
	while((ptr->next)!=NULL){
		ptr=ptr->next;
	}
	// create new node and connect it
	ptr->next=new PostList(data);
	return;
}

void PostList::print()const{ // Print all the list skipping the targeted one (to skip the dummy)
	if( this->next == NULL ){ return; }
	PostList *ptr=this->next;
	ptr->printNode();

	while( (ptr=ptr->next)!=NULL){
		ptr->printNode();
	}
	return;
}

void PostList::printNode()const{ // Print the target node's data
	data.print();
	return;
}

Post *PostList::popN(const int n)const{ // Return pointer to post number n (with 1 being the first real post not the dummy)
	if(n<=0){ return NULL; }
	int i=1;
	PostList *tmp=this->next;

	// Move deeper into the list until you reach nth element or the end
	while( i!=n && tmp!=NULL ){
		i++;
		tmp=tmp->next;
	}

	// return pointer to the data of the nth node
	if(i==n){ return &(tmp->data); } 

	return NULL;	// return NULL if for any reaso you fail to find the nth element
}
