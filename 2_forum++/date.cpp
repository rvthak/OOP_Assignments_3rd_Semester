#include <iostream>
#include <cstdlib>
#include <ctime>
#include "date.h"

using namespace std;

// Set the starting seed with time so its different each time the program runs
static int seed=time(NULL);

void Date::print()const{
	cout << day << "/" << month << "/" << year << endl;
	return;
}

void Date::random(){ // Random date
	srand(seed++); // Increment the seed to get a different result each time the function runs

	month=rand()%12+1; // month in [1,12]
	year=1970 + rand()%(2018-1970+1); // year in [1970,2018]

	if( month==2 ){
		// check if we are on a leap year
		if ((( year%4==0) && (year%100!=0)) || (year%400==0)){
			day=rand()%29+1;
		}
		else{
			day=rand()%28+1;
		}
	}
	else if( month==4 || month==6 || month==9 || month==11){
		day=rand()%30+1;
	}
	else{
		day=rand()%31+1;
	}
	return;
}

void Date::set(int d, int m, int y){
	day=d;
	month=m;
	year=y;
	return;
}

void Date::set(Date& date){
	day=date.day;
	month=date.month;
	year=date.year;
}

void Date::get(int& d, int& m, int& y)const{
	d=day;
	m=month;
	y=year;
	return;
}