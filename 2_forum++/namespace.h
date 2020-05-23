
// A Namespace just to organize my constants since the program is not dynamic
// My recommended default values for easy testing are 5, 5, 2, 2, 3
namespace Values{
	const int Max_Number_Of_Threads=5;
	const int Max_Number_Of_Posts=5;

	const int Number_Of_Threads=2;
	const int Number_Of_Posts=2;

	const int Number_Of_Posts_To_Print=3;

	// For basic input checking
	int CheckInputForErrors();			// Checks if the const values make sense and returns an error id in case they are not
	void PrintErrors(const int err);	// Takes the arror id from above and prints the correct error message
	bool CheckInput(); 					// Combines the two above functions for simplicity
}
