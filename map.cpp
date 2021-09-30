#include <iostream> 
#include <iterator> 
#include <map> 

using namespace std; 

int main() 
{ 

	// empty map container 
	map<int, int> gquiz1; 

	// insert elements in random order 
	gquiz1.insert(pair<int, int>(1, 40)); 
	gquiz1.insert(pair<int, int>(2, 30)); 
	gquiz1.insert(pair<int, int>(3, 60)); 
	gquiz1.insert(pair<int, int>(4, 20)); 
	gquiz1.insert(pair<int, int>(5, 50)); 
	gquiz1.insert(pair<int, int>(6, 50)); 
	gquiz1.insert(pair<int, int>(7, 10)); 

	// printing map gquiz1 
	map<int, int>::iterator itr; 
	cout << "\nThe map gquiz1 is : \n"; 
	cout << "\tKEY\tELEMENT\n"; 
	for (itr = gquiz1.begin(); itr != gquiz1.end(); ++itr) { 
		cout << '\t' << itr->first 
			<< '\t' << itr->second << '\n'; 
	} 
	cout << endl; 

	return 0; 
} 

