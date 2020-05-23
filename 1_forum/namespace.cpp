#include <iostream>
#include "namespace.h"

int Values::CheckInputForErrors(){
	if(Max_Number_Of_Threads==0 || Max_Number_Of_Posts==0 || Number_Of_Threads==0 || Number_Of_Posts==0 ){ return 1; }
	if(Max_Number_Of_Threads < Number_Of_Threads){ return 2; }
	if(Max_Number_Of_Posts < Number_Of_Posts){ return 3; }

	if( Number_Of_Posts_To_Print > Number_Of_Posts*Number_Of_Threads ){ return 4; }
	return 0;
}

void Values::PrintErrors(const int err){
	std::cout << "--- Fatal User Input Error ---" << std::endl;
	if( err==1 ){ std::cout << " Given 0 as an input value. Impossible to move on";}
	else if( err==2 ){ std::cout << " Max_Number_Of_Threads < Number_Of_Threads";}
	else if( err==3 ){ std::cout << " Max_Number_Of_Posts < Number_Of_Posts";}
	else if( err==4 ){ std::cout << " Number_Of_Posts_To_Print < Number_Of_Posts";}
	else{ std::cout << " Unknown error...";}
	std::cout << std::endl;
}

bool Values::CheckInput(){
	int err=Values::CheckInputForErrors();
	if(err!=0){ Values::PrintErrors(err); return 1;}
	return 0;
}