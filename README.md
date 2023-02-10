# CS-303-Assignment-1
Arrays

This program initializes an array with integers from an input file and then allows the user to search that array, modify a value, or add and an element to the end, replace or remove an element, or quit the program.

The program first outputs the following menu

		What operation do you want to perform on your array?
		s - search for an integer
		m - modify the value of an integer
		a - add an integer to the end of the array
		r - replace value of integer or remove it
		q - quit program" 
   
the user then inputs their choice and the program executes accordingly using a switch statement

When the search function is called, the user is prompted to input the integer they want to search for. If it is found, the index of that integer is outputted to the user, and if it is not found "Integer not found in array" is outputted.

When the modify function is called, the user is prompted to input the index of the element they want to change and then the new value they want to change it to. The updated array is outputted.

When the Add function is called, the user is prompted for the value they want to append to the end of the array. The updated array is outputted.

When the replace/remove function is called, the user is prompted to choose to replace (1) or remove (2) an the index of element from the array. For replace, the value at the index is replaced with a 0, and for remove (2) the element is still changed to zero and then the array shifts elements over.

If the user inputs 'q' the program ends 

exceptions are placed throughout the program for incorrect inputs. 

Screenshots:

![cs303 A1 ss1](https://user-images.githubusercontent.com/98354701/217996428-dbe7ceb7-51ea-4e69-b1cc-177f417e2bdc.png)
![cs303 A1 ss3](https://user-images.githubusercontent.com/98354701/217997953-9e7561fb-1d55-495f-8761-f0e8d2102128.png)
![cs303 A1 ss2](https://user-images.githubusercontent.com/98354701/217997991-5ff27b09-b4ee-4059-978e-f767e27ab3bf.png)


