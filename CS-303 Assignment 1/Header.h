#pragma once
#include<ostream>

void initializeArray(int array[], int size, int currentSize); //initializes the array with integers from input file

void outputArray(int array[], int size, int currentSize); //displays array to user

int numCheck(int array[], int size); //checks for certain element in array

int addValue(int array[], int size, int currentSize); //adds value to the end of the array

int modifyValue(int array[], int size, int currentSize); //changes a value in the array

int replaceRemove(int array[], int size, int currentSize); //replaces element with 0, or removes element altogether
