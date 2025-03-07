// CPP code to demonstrate std::string::replace() 
#include <iostream> 
using namespace std; 

// Function for demonstration 
void replaceDemo(string s1, string s2, string s3, string s4) 
{ 
	// Using positions 
	cout << "Using positions:"
		<< "\n"; 
	// Replaces 7 characters from 0th index by s2 
	s1.replace(0, 7, s2); 
	cout << s1 << endl; 

	// Replaces 3 characters from 0th index with "Hello" 
	s4.replace(0, 3, "Hello "); 
	cout << s4 << endl; 

	// Replaces 5 characters from 6th index of s4 with 
	// 5 characters from 0th of s3 
	s4.replace(6, 5, s3, 0, 5); 
	cout << s4 << endl; 

	// Replaces 5 characters from 6th index of s4 with 
	// 6 characters from string "to all" 
	s4.replace(6, 5, "to all", 6); 
	cout << s4 << endl; 

	// Replaces 1 character from 12th index of s4 with 
	// 3 copies of '!' 
	s4.replace(12, 1, 3, '!'); 
	cout << s4 << endl; 

	// Using iterators 
	cout << "\nUsing iterators:"
		<< "\n"; 
	// Replaces whole s2 string with s3 
	s2.replace(s2.begin(), s2.end(), s3); 
	cout << s2 << "\n"; 

	// Replaces 13 characters from begin of s1 with string 
	// "Example" 
	s1.replace(s1.begin(), s1.begin() + 13, "Example"); 
	cout << s1 << "\n"; 

	// Replace last 7 characters of s4 with first 12 
	// characters of the string "geeks from- here" 
	s4.replace(s4.end() - 7, s4.end(), "geeks from- here", 
			12); 
	cout << s4 << "\n"; 

	// Replaces last character with complete s2 string from 
	// s2.begin() till s2.end() 
	s4.replace(s4.end() - 1, s4.end(), s2.begin(), 
			s2.end()); 
	cout << s4 << "\n"; 

	// Replaces portion of string s4 starting from 5 
	// characters from s4.begin() to 15 characters from 
	// s4.begin() with 2 occurrences of ',' 
	s4.replace(s4.begin() + 5, s4.begin() + 15, 2, ','); 
	cout << s4 << "\n"; 
} 

// Driver code 
int main() 
{ 
	string s1 = "Example of replace"; 
	string s2 = "Demonstration"; 
	string s3 = "GeeksforGeeks"; 
	string s4 = "HeyWorld !"; 

	replaceDemo(s1, s2, s3, s4); 
	return 0; 
}
