// Lab 1: Pointers, Arrays and Functions
// Example2: Arrays and Pointers
 
//**  THIS File Contains 2 Questions (Q1, Q2) **//

#include <iostream>
using namespace std;

int main()
{	
	int i,n;

	//1 - Automatic array allocation (The size of array is known before run - constant) ------------
	int A[10];
	cout<< "\nValue of variable A=" << A << " (Array name is a constant pointer)";
	for(i=0; i<10; i++)
		A[i]=2*i;

	//Printing Array elements using array name A.
	cout<<"\nValues of the array A:  ";
	for(i=0; i<10; i++)	
		cout<<A[i]<<" ";

	//Using pointers to access array elements
	int* P=A;
	P[0]=99;
	P[9]=888;
	cout<<"\n\nValues of the array A: ";
	for(i=0; i<10; i++)
		cout<<A[i]<<" ";


	//2- Dynamic array allocation (The size of array is NOT known before run) ------------
	cout<<"\n\nEnter the number of array elements:";
	cin>>n;

	/// [Q1] Can you do this? Try to uncomment the next line after 1st run and re-run.
	//int T[n];
	
	//The new opertor. (dynamic allocation)
	P=new int[n];
	for(i=0; i<n; i++)
		P[i]=5*i;

	cout<<"\n\nValues of the array pointed to by pointer P:\n";
	for(i=0; i<n; i++)	
		cout<<P[i]<<" ";


	//To free the array memory. notice the square brackets
	delete [] P;
	//P=NULL; //Note: good to set P = NULL after deletion

	cout<<"\n\nValues of the array pointed by pointer P (after delete):\n";
	for(i=0; i<n; i++)	
		cout<<P[i]<<" "; //Note: if you set P = NULL; after delete,
						 //you can check if P != NULL before using it --> so setting P = NULL after delete is good
						 //which means that a check if(P!=NULL) is needed before the for loop that uses P

	
	cout<<"\n\nDeleting pointer P does not mean you can not use it again";
	P = A+4;  //P = &A[4] ---> pointer to the 5th element A[4]
	cout<<"\nP[0]="<<P[0]<<", A[4]="<<A[4]; //Note: when you use index operator P[i], 
						   //it counts i elements starting from the element pointed by P (the 5th element here)

	cout<<"\nP[5]="<<P[5]<<", A[9]="<<A[9];

	A[3] = 6;

	/// [Q2] What will happen if next statement is uncommented, why? run and see
	//delete []P; //Remember?
	

	cout<<endl;
	return 0;

} // end main

