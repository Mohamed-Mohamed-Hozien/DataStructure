// Lab 1: Pointers, Arrays and Functions
// Example4: Function and Passing

//**  THIS File Contains 2 Questions (Q1, Q2) **//

// Instructions:
// 1- Read the program carefully and make sure you understand every line.
// 2- Read the body of function Increment.
// 3- See the call to Increment in main function.
// 4- On a piece of paper, write down the values of a, b, and c after
//    the execution of Increment ends.
// 5- Run the program, check the values of a, b, and c in the output
//    and compare it what you wrote on the paper. Is it the same?
//    yes, booooya!!! you understand everything -:) 

#include <iostream>
using namespace std;

void Increment(int x,int* P, int& y);

void main()
{
	//declare variables
	int a=10;     
	int b=20;
	int c=30;

	//Declaring an alias variable
	int &d = c; // d is an alias (another name) of c
				// & here doesn't mean address
				// it's used here to declare d as an alias to c

	/// [Q1] what will happen if you don't initialize d in the same line of declarating??
	// comment the above line and uncomment the next 2 lines and tell what you find
	// int &d; //declaration
	// d = c; //initialization
	// alias variables must be initialized (= something) in the same line of declarating or "syntax" error (not even run-time)

	d = 50; // this will change c as will because now the same location is called c and d
   
	//Print values of a, b, c, d
	cout<<"\nOriginal Values:\n a ="<<a<<"\t b="<<b<<"\t c="<<c<<"\t d="<<d;

	//Print addresses of a, b, c, d
	cout<<"\n\nAddresses of a, b, c, d:";
	cout<<"\n=====================";	
	cout<<"\nAddress of a = "<<&a;
	cout<<"\nAddress of b = "<<&b;
	cout<<"\nAddress of c = "<<&c;
	cout<<"\nAddress of d = "<<&d; // Note: tha adress of c and d are the same because they're the same memory location

	//Call function Increment
	//Notice how every parameter is passed to the function
	// - a is passed by value
	// - b is passed by pointer, notice the ampersand (&) to pass the address of b
	// - c is passed by reference
	//Notice the types corresponding to each input
	// - 1st parameter is of type "int" --> so we send an integer variable a
	// - 2nd parameter is of type "int *" --> so we send a pointer (address of an int variable b: &b)
	// - 3rd parameter is of type "int &" --> it's like the alias variable (d) defined above
	// so we send an integer c
	
	//Remember: No types (int, float, ...etc) ever exists inside the () of function call!!
	// we didn't recieve the output of the function in a variable, because the return type is void
	Increment(a, &b, c);

	//Print values of a, b, c after calling the function.
	//Notice the effect of incrementing all the variables with different passing types (by value, ref, pointer)
	cout<<"\n\nValues after function call:\n a ="<<a<<"\t b="<<b<<"\t c="<<c<<"\t d="<<d;
	
	cout<<endl;

} // end main

//Defintion of function Increment
//Increments all inputs by 1
void Increment(int x,int* R, int& y) // Note: passing int* R passes 2 things:
									 // 1- the int pointed to by R --> passed by pointer (R)
									 // 2- the pointer itself passed in the function call --> passed by value
									 // so if we make R = something; inside the function
									 // will NOT affect the pointer passed in the fuction call (by val)
									 // but if we make *R = something; inside the function
									 // will affect the integer pointed to by the pointer passed in the fn call (by pointer)
									 // Note: passing int& y 
									 // just gives the variable passed in the function call,
									 // another name y inside the function (no extra memory location is reserved)
									 // Draw the memory and the pointers to imagine what happens inside
{	
	//Print addresses of function parameters
	cout<<"\n\nAddresses of function parameters:";
	cout<<"\n===================================";
	cout<<"\nAddress of x = "<<&x;
	cout<<"\nAddress at R = "<<R;
	cout<<"\nAddress of y = "<<&y;
	
	//Increment all function inputs by 1
	x = x+1;
	// Notice the difference here:
	// we need to dereference R (* operator) to get the value pointed to by R and then increment it.
	// Q2: what will happen if we do: R = R + 1?? 
	*R = *R+1;  
	y = y+1; 
	
	// The way we operate on the passed by ref variables is the same way we operate on the pass by value variables
	// The difference syntax is in dealing with passed by pointer variables

	// Note: the diffreence between dealing with variable passed by pointer and by refernce inside the function

}// end function Increment  
