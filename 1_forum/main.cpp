#include <iostream>
#include "forum.h"
#include "namespace.h"

using namespace std;

int main(){
	// Check input integrity
	if( Values::CheckInput()!=0 ){ return 1; }

	cout << " ####################### DIT LISTS ####################### " << endl << endl;

	// 1 - Create Forum
	Forum ditLists("Αντικειμενοστραφής Προγραμματισμός");

	// 2 - Print Forum
	cout << endl << endl << " 2. ####### Printing Forum ####### " << endl;
	ditLists.print();
	
	// 3 - Print Thread
	cout << endl << endl << " 3. ####### Printing Wanted Thread ####### " << endl;
	ditLists.printThread("Κανόνες και χρήσιμες πληροϕορίες");

	// 4 - Print Random Posts
	cout << endl << endl << " 4. ####### Printing Random Posts ####### " << endl << endl;
	ditLists.printRandomPosts(Values::Number_Of_Posts_To_Print);

	cout << endl << " ##### Done! Exiting program... #####" << endl;
	return 0;
}