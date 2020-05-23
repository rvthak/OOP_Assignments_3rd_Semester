#ifndef DATE
#define DATE

struct Date{
	public:
		Date(int d=1, int m=1, int y=1970):day(d), month(m), year(y){};

		void print()const;	// Print the Date
		void random();		// Set the targeted Date to a real random date between 1970 and 2018

		// These functions were made for testing and they are not used anywhere
		void set(int d, int m, int y);
		void set(Date& date);
		void get(int& d, int& m, int& y)const;
	
	private: // Date's data
		int day;
		int month;
		int year;
};

#endif