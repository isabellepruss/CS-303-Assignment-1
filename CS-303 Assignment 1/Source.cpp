#include"Header.h"
#include<iostream>
#include<fstream>
#include<stdexcept>
#include<limits>

using namespace std;


//initializes array with values from input file and 0's for the rest of the array.
//pre: array is empty, size and currentSize are positive values
//post: array is filled to currentSize with values from input file and from there to size with 0's
void initializeArray(int array[], int size, int currentSize) {
	
	ifstream fin; //create object for input stream
	int inputNum;

	fin.open("A1Input.txt"); //open input file

	while (!fin.eof())
	{
		//input numbers into array
		for (int i = 0; i < currentSize; i++) {
			fin >> inputNum;
			array[i] = inputNum;

		}

	}

	fin.close(); //close file

	//fill rest of array with 0s
	for (int i = currentSize; i < size; i++) {
		array[i] = 0;
	}

}

//prints array from index 0 to currentSize to user
//pre: array and its size is passed to function
//post: array is outputted to user
void outputArray(int array[], int size, int currentSize) {

	for (int i = 0; i < currentSize; i++) {
		cout << array[i] << ' ';
	}

	cout << endl << endl;

}

//searches array for particular integer
//pre: array and its size is passed to function
//post: returns -1 if integer not found, and the index of the integer if it is found.
int numCheck(int array[], int size) {

	int userNum; // number user wants to search for
	cout << "What integer would you like to search for?  :  ";
	cin >> userNum;

	//iterate through array to find number
	for (int i = 0; i < size; i++) {
		
		if (userNum == array[i]) {
			return i; // return index if found
		}

	}

	return -1; //return -1 if not found

}

//changes the value of an integer in the array
//pre: array and its size is passed to function
//post: changes an element in the array to the value the user wants and returns 0 (a value the main will deal with).
int modifyValue(int array[], int size, int currentSize) {

	int userIndex;
	int userNum;
	string message;

	cout << "What is the index of the integer you want to change?  :  "; //ask user for index 

	try {
		
		cin >> userIndex; //user input

		if (userIndex < 0 || userIndex > currentSize) { //check if index is out of bounds

			//if yes, through message, and return -1
			throw message; 

			return -1;
		}

		//if not ask user what they want to change it to
		cout << "What value would you like to change it to?  :  ";
		cin >> userNum;

		array[userIndex] = userNum; //make change

		return 0; // return 0
	}
	
	catch (...) { //catch thrown message and output to user

		cout << "Index input invalid, please try again." << endl; 
		cin.clear();
		cin.ignore(numeric_limits<int>::max(), '\n');
	}
	
	
	cout << endl;


}

//adds an element to the end of the array
//pre: array and its size are passed to function
//post: integer of user's choice is appended to the end of the array.
int addValue(int array[], int size, int currentSize) {

	int userNum;
	cin.exceptions(ios::failbit);

	while (true) { //while loop for the user to be able to keep trying if input is invalid the first time.

		try {
			//ask user for value they want to add to array
			cout << "What value do you want to add to the array?  :  "; 
			cin >> userNum;

			if (cin) { //if user enters decimal, alert but change to integer

				cout << "You entered a decimal." << endl;
				cin.ignore(numeric_limits<int>::max(), '\n');
			}

			array[currentSize] = userNum; //append to array
			return currentSize + 1; // return updated size
		}

		//if user inputs neither a decimal or integer, catch exception and alert them.
		catch (ios_base::failure& ex) { 

			cout << "Invalid input, please try again." << endl;
			cin.clear();
			cin.ignore(numeric_limits<int>::max(), '\n');
		}

	}


	}

		

//replaces element with 0 or removes it altogether depending on what the user wants
//pre: array and its size are passed
//post: replaces desired element with 0 or removes it from array
int replaceRemove(int array[], int size, int currentSize) {

	//ask user if they want to replace with 0 or remove element
	int userChoice;
	cout << "Would you like to replace a value with 0 or remove it? (1 - replace, 2 - remove)  :  ";
	cin >> userChoice;

	//if they want to replace, ask them what value by its index
	if (userChoice == 1) {
		int userIndex;
		cout << "What is the index of the value you would like to replace?  :  ";
		cin >> userIndex;

		//ensure index is in range and make change
		if (userIndex >= 0 && userIndex < size) {
			array[userIndex] = 0;

		}

		//if index not in range, prompt user to try again
		else{
		
			cout << "Index not in range, please try again." << endl;
		}

		return currentSize; //return same size


	}

	//if they want to remove value, ask them what value by its index
	if (userChoice == 2) {
		int userIndex;

		cout << "What is the index of the value you would like to remove?  :  ";
		cin >> userIndex;

		//if index is the last element in array, change it to zero
		if (userIndex == currentSize) {
			array[userIndex] = 0;

			return currentSize - 1; //update size and return

		}

		//if index is somewhere else in the array
		if (userIndex >= 0 && userIndex < size) {

			int temp; //create temporary variable

			array[userIndex] = 0; //change its value to 0
			
			//shift that new 0 to to the end of the array
			for (int i = userIndex; i < currentSize; i++) {
				temp = array[i];
				array[i] = array[i + 1];
				temp = array[i + 1];

			}

			return currentSize - 1; //return updated size
		}

		//if index is not in range alert user so they can try again.
		else {

			cout << "Index not in range, please try again." << endl;

			return currentSize; //return same size
		}

	}

}

