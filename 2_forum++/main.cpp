#include <iostream>
#include "forum.h"
#include "namespace.h"

using namespace std;

int main(){
	// Check input integrity
	if( Values::CheckInput()!=0 ){ return 1; }

	// 1 - Create Forum
	Forum ditLists("Αντικειμενοστραφής Προγραμματισμός");

	cout << endl << endl << "    #########   Printing forum sorted:   #########" << endl << endl;
	// 2 - Print Forum sorted
	ditLists.print_sorted();

	return 0;
}