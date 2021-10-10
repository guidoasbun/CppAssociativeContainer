#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;

// Declaration function printSet.
// The function passes a list and prints all
// the elements on one line, separated by a space.
// Use a range-based FOR loop. If you do not know
// what this means, search the Web.
void printSet(const set<int>& l);

int main()
{
	/**************************************************************
				SETS
	***************************************************************/
	cout << "  ***  STL SET CLASS  ***  \n\n";

	// Create a set of ints named set1 using the initializer list
	// to insert the following integers in this order:
	// 2, 7, 5, 6, 9, 1 and 3.

    set<int> set1{2, 7, 5, 6, 9, 1, 3};

	// Print the set using the printSet function you implemented.

    cout << "Printout of set1: \n";
    printSet(set1);

	// What do you notice in the printout?
    /*I noticed that the set was automatically ordered from least to greatest*/

	// size_type  erase (const value_type& val);
	// Use the function erase integer 9 from set1.
	// Print out set1.

    set1.erase(9);
    cout << "set1.erase(20)\n";
    printSet(set1);

	// size_type  erase (const value_type& val);
	// Use the function erase integer 2 from set1, but
	// this time use cout to print the return value.
	// What is the return value?

    cout << "cout to print the value of set1.erase(2)\n";
    cout << set1.erase(2);

	// If you do not know what the return value is, then
	// check set::erase in cplusplus.com
	cout << endl;

	// Print set1.

    cout << "Printout of set1: \n";
    printSet(set1);

	// iterator  erase (const_iterator position);
	// This function is different from the previous one,
	// because instead of passing a value, it passes a
	// position indicated by an iterator.
	// Delete the second element in the set without creating
	// an iterator variable and using the prefix increment
	// operator.

    set1.erase(*set1.begin()+2);

	// Print set1.

    cout << "set1.erase(*set1.begin()+2)\n";
    printSet(set1);

	// pair<iterator,bool> insert (const value_type& val);
	// Use the function insert to insert 4 and 8 in set1.

    set1.insert(4);
    set1.insert(8);

	// Print set1.

    cout << "set1.insert(4)\n";
    cout << "set1.insert(8)\n";
    printSet(set1);

	set<int>::iterator first = set1.begin();
	set<int>::iterator second = ++set1.begin();
	// iterator erase(const_iterator first, const_iterator last);
	// Use function erase to delete the first and second element
	// in set1. Use the given iterators created above.
	// Note that you should write one statement only.

    set1.erase(first, ++second);

	// Print set1.

    cout << "set1.erase(second)\n";
	printSet(set1);

	// Your output should be: 5 6 7 8
	// If it is not, you need to carefully read about function erase
	// to understand how it works.

	cout << "\n\n--------------------------------------------------";
	cout << "\n\nThe output for the next sections depends "
		<< "on your implementation.";

	/**************************************************************
				MAPS
	***************************************************************/
	cout << "\n\n--------------------------------------------------";
	cout << "\n  ***  STL MAP CLASS  ***  \n\n";

	// Create a few maps using the different constructors shown in
	// the slides.

    /*Using insert make_pair*/

    map<int, int> intMap;
    for (int i = 1; i < 10; ++i)
        intMap.insert( make_pair(i, (100 / i)));

    map<int, string> intStringMap = {
            {1, "one"},
            {2, "two"},
            {3, "three"},
            {4, "four"},
    };

    map<char, int> charIntMap;
    charIntMap['A'] = 90;
    charIntMap['b'] = 80;
    charIntMap['C'] = 70;
    charIntMap['D'] = 60;

	// Use the following functions to manipulate the maps:
	// pair<iterator,bool> insert (const value_type& val);
	// void insert (InputIterator first, InputIterator last);
	// iterator  erase(const_iterator position);
	// size_type erase(const key_type& k);
	// iterator  erase(const_iterator first, const_iterator last);
	// Print each map without creating a print function, but
	// by using a range-based loop.

    cout << "intMap: \n";
    for (const auto& elem : intMap)
        cout << "(" << elem.first << ", " << elem.second << ")";
    cout << endl;

    cout << "intStringMap: \n";
    for (const auto& elem : intStringMap)
        cout << "(" << elem.first << ", " << elem.second << ")";
    cout << endl;

    cout << "charIntMap: \n";
    auto it = charIntMap.cbegin();
    auto itEnd = charIntMap.cend();
    for (it; it != itEnd; ++ it)
        cout << "(" << it->first << " " << it->second << ")";


	cout << "\n\n----------------------------------------------------";

	cout  <<  endl;
//	system("Pause");
	return 0;
}

// Definition function printSet
void printSet(const set<int>& aSet)
{
	for (const int& elem : aSet)
		cout << elem << " ";
	cout << endl;
}