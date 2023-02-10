#include<iostream>
#include<string>
#include<fstream>
#include"Header.h"

using namespace std;


int main() {

	char userChoice = 'y'; // variable that determines if while loop will run
	int currentSize = 9; //size of array with numbers from input file 
	int numArray[20]; // entire array will 11 empty spaces the nums from input file did not fill

	//fill array with input file integers and 0s
	initializeArray(numArray, 20, currentSize);

	//output array to user
	outputArray(numArray, 20, currentSize);





	while (userChoice != 'q') { // program executes until user decides to quit

		//display input choices to user
		cout << "What operation do you want to perform on your array?" << endl;
		cout << "s - search for an integer" << endl;
		cout << "m - modify the value of an integer" << endl;
		cout << "a - add an integer to the end of the array" << endl;
		cout << "r - replace value of integer or remove it" << endl;
		cout << "q - quit program" << endl;

		cout << endl;

		cin >> userChoice; // user input

		switch (userChoice) {

		case 's': {

			//call function to search for integer
			int returnValue = numCheck(numArray, 20); 

			if (returnValue == -1) { // if integer not found
				cout << "Integer not found in array.\n";
			}

			else { // if integer found display index
				cout << "Integer found at index " << returnValue << endl << endl;

			}

			break;

		}

		case 'm': {

			//output array to user
			cout << "The current array is : ";
			outputArray(numArray, 20, currentSize);

			//call function to change value
			int returnValue = modifyValue(numArray, 20, currentSize);
			
			//output updated array
			if (returnValue == 0){
				cout << "The updated array is  :  ";
					outputArray(numArray, 20, currentSize);

			}


			break;

		}

		case 'a': {

			//output current array
			cout << "The current array is : ";
			outputArray(numArray, 20, currentSize);

			//call function to add element to array
			currentSize = addValue(numArray, 20, currentSize);

			//output updated array
			cout << "The updated array is  :  ";
			outputArray(numArray, 20, currentSize);

			
			break;
		
		}

		case 'r': {

			//output current array
			cout << "The current array is : ";
			outputArray(numArray, 20, currentSize);

			//call function to replace or remove element from array
			currentSize = replaceRemove(numArray, 20, currentSize);

			//output updated array
			cout << "The updated array is  :  ";
			outputArray(numArray, 20, currentSize);

			break;

		}
		}



	}





}








