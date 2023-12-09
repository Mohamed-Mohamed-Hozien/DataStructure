// Lab 1: Pointers, Arrays and Functions
// Example5: Passing Array and Pointers as Function Parameters

//**  THIS File Contains 2 Questions (Q1, Q2) **//

#include <iostream>
using namespace std;

// passing an array of integers
// Automatically or dynamically allocated array can be written in the same way in fn. prototype
// either written as (int A[]) or (int* A) inside function declaration/prototype
//array pointer is passed by value
void FillArray(int *A, int n)
{
	cout<<"\nFunction FillArray, Enter " << n << " integers:"<<endl;
	for (int i = 0; i < n; i++)
	{
		cin>>A[i];
	}
}

// passing an array of integers
// Automatically or dynamically allocated array can be written in the same way in fn. prototype
// either written as (int A[]) or (int* A) inside function declaration/prototype
void PrintArray(int A[], int n)
{
	cout<<"Function PrintArray\n";
	for (int i = 0; i < n; i++)
	{
		cout<<A[i]<<" ";
	}
	cout<<endl;
}




void main()
{
	// 1- Passing an array to a function
	cout<<"\n====== Passing an array of integers (automatic) ======\n";
	int A[7];
	FillArray(A, 7); // see how the array is passed
	PrintArray(A, 7); 

}