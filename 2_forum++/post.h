#ifndef POST
#define POST

#include <string>
#include "date.h"

class Post{
	public:
		Post():creation_date(0,0,0), id(-1), title(""), creator(""), text(""){}
		Post(const Date& dt, const int i, const std::string t, const std::string c, const std::string txt);
		~Post();

		// Two overloaded simple setters
		void set(Post& post);
		void set(Date& dt, const int i, const std::string t, const std::string c, const std::string txt);

		void print()const;			// Print the post
		int getID()const;			// Returns the id of the target post
		std::string getName()const; // Returns the Post creator name

		static int getCurID();		// Returns the first available id for a new post == The total amount of all posts
		static int getCurIDInc();	// Returns the first available id for a new post and then increments it => used when creating new post

	private: // All the post's data
		int id;
		std::string title;		
		std::string creator;
		Date creation_date;
		std::string text;

		static int idcount; // A counter that must increment every time a post gets created to fuel us with unique post ids
};

#endif