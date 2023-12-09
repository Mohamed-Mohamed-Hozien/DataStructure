// Lab 1: Pointers, Arrays and Functions
// Example1: Pointers

//**  THIS File Contains 6 Questions (Q1 to Q6) **//

#include <iostream>
using namespace std;

int main()
{
	int X=7;	 //X is an integer
	int* P;  //Pointer Declaration (P's type is a pointer to an integer)
	         //Note: the above statement allocates the pointer only (not the integer itself)

	//Pointer Initialization - Method 1 -------
	P = &X;	 //Pointer = address (&) of another variable (int variable here because P is int*)
			 //After the 1st run, comment this line and see the effect (Bad pointer)
   
	cout<< "\nThe & operator: &X=" << &X << "\nThe value of P=" <<P;
	cout<< "\n\nThe value of X:  X="<< X << "\nThe * operator: *P=" << *P; //The (*) operator

	int *P2;	 //Declaring another pointer.
	
	//Pointer Initialization - Method 2 -------
	P2= P;	 //Pointer = another pointer 
			 //Now both pointers point to the same address (same memory location - X here)

	cout<< "\n\nP=P2 ==> Both pointers P and P2 are \"pointing\" at the same address";
	cout<< "\nP=" << P << " and P2=" << P2;

	*P2= 30;
	
	cout<< "\n\nAfter statement: *P2= 30;";
	cout<< "\nNow X = " << X <<", why?"<<endl;	
	/// [Q1] How is the value of "X" changed?

	int* P3;
	
	//Pointer Initialization - Method 3 -------
	P3 = new int; //Pointer = new int (dynamic allocation - "new" operator) 
	              //Note: this statement: 1- dynamically-allocates a new integer 2- makes P3 points to it	            

	cout<< "\n\n*P3 = " << *P3 << ", why?"; 
	/// [Q2] What is the values of *P3? and why?

	*P3=7777;

	cout<< "\n\n*P3 = " << *P3;

	//Free the memory when no longer needed
	delete P3;  //Note: 
				//this statement deallocates the dynamically-allocated integer that is pointed to by P3
				//but P3 itself is not deallocated
				//because P3 is a local (automatic) variable that is deallocated automatically 
				//when going out of the scope it's declared in
				
	//So you can reuse P3 again after deletion
	P3 = new int;
	*P3 = 100;
	//And so on
	
	delete P3; //memory pointed to by P3 is no longer needed.
	
	cout<< "\n\n*P3 (after delete)= " << *P3 << ", why?"; 
	/// [Q3] What is the value of *P3? and why?

	cout<< "\nP3 (after delete)= " << P3 << ", why not equal to NULL?"; 
	/// [Q4] What is the value of P3? and why not NULL?

	P3 = NULL;	//it's good practise to set P3 = NULL after deleting the integer it points to
			    //Reason: to indicate that P3 now is not pointing to a valid value
				//Note: Don't ever make a pointer refer to NULL before deleting the int, 
				//because you cannot delete it after that (if this pointer is the only pointer to that int)

	cout<< "\nP3= " << P3;

	//** Important **//

	int s = 5;
	int * S1 = &s;
	//After the 1st run, Uncomment the next line and re-run
	//delete S1; 
	/// [Q5] What happens when you uncomment & run? and why is that??

	int * S2 = new int;
	int * S3 = S2; // making S3 pointing at the same int pointed to by S2
	delete S3;     // the int is de-allocated

	//After the 1st run, Uncomment the next line and re-run
	delete S2; 
	/// [Q6] What happens when you uncomment & run? and why is that??

	// The 2 cases above (after uncommenting each one in different run)
	// generate the same error
	// Here is the error "_Block_Type_Is_Valid (pHead->nBlockUse)"
	// This error appears when you:
	// 1- delete something that already deleted
	// 2- delete something that is not dynamically allocated in the first place

	cout<<endl;
	return 0;

} // end main

