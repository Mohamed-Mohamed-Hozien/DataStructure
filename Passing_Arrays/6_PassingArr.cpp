// Lab 1: Pointers, Arrays and Functions
// Example6: Passing Arrays

//**  THIS File Contains 3 Questions (Q1, Q2, Q3) **//

// Focus here on the way the array is passed in the call and how it's written in prototype
// but inside the function, it's treated the same way as shown before in Example3 – Array of Objects and Array of Pointers

#include <iostream>
using namespace std;

struct Point
{
	double x,y;
};


// passing an array of integers
// Automatically or dynamically allocated array can be written in the same way in fn. prototype
// either written as (int A[]) or (int* A) inside function declaration/prototype
void FillArray(int A [], int n)
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
void PrintArray(int* A, int n)
{
	cout<<"Function PrintArray\n";
	for (int i = 0; i < n; i++)
	{
		cout<<A[i]<<" ";
	}
	cout<<endl;
}

//Passing an array of objects
//A function that takes an array of OBJECTS (Points) and fills them
void FillArrOfObjects(Point* Pts, int n)  //Pts is an array of objects
{
	cout<<"\nEnter info of " << n << " points:"<<endl;
	for (int i = 0; i < n; i++)
	{
		cout<<"Point#"<<i+1<<":\n";
		cout<<"x=";
		cin>>Pts[i].x;
		cout<<"y=";
		cin>>Pts[i].y;
	}	
}


//Passing an array of objects
//A function that takes an array of OBJECTS (Points) and prints them
void PrintArrOfObjects(Point* R, int n)
{
	cout<<"\nPrinting points info:";
	for (int i = 0; i < n; i++)
	{
		cout<<"\nPoint#"<<i+1<<":\n";
		cout<<"x="<<R[i].x;
		cout<<", y="<<R[i].y;
	}		
}

//Passing an array of POINTERS
//A function that takes an array of POINTERS
//The function returns the number of points in array A
int CountPoints(Point** A, int n)
{
	int count=0;
	for(int i=0; i<n; i++)
		//if current point is pointing to a Point object, then count it
		if(A[i])   //equivalent to if(A[i] != NULL)
			count++;

	return count;
}
// Passing Array Pointer by Reference
// Note: we also passed n by reference. why??
// After the 1st run make the following:
// 1- pass n by value and make array elements contains odd and even numbers + RUN
/// [Q1] what happened? and why??

// 2- pass A and n by value not reference + RUN
/// [Q2] what happened? and why?? -- Remember the runtime error I've told you to remember in Example1 – Pointers?
void KeepOdds(int*& A, int& n)
{
	int * odds = new int[n];
	int k = 0; // k is an index for odds array
	for (int i = 0; i < n; i++)
	{
		if(A[i] % 2 != 0) //odd
		{
			odds[k] = A[i];
			k++; // k is only incremented if an element is inserted in odds array
		}
	}
	delete [] A; 
	/// [Q3] why we delete A not delete odds??
				 // Note: don't forget to deallocate any dynamically allocated elements
				 // 
	A = odds; // A is passed by reference for THAT LINE (A = something;)
	n = k; // that's why n is passed by reference (n = something;)
		   // because the odds array initially allocates n elements
	       // but it actually conatsin values for only k element
		   // if we changes A to be odds without changing the n to k
		   // further using of array A like printing will deal with n elements 
		   // which contains the last (n-k) elements as garbage
}

void main()
{
	// Recommended to run each part of the following alone
	// so you can comment FillArray and PrintArray of any part that you already tried

	// 1- Passing an automatic array to a function
	cout<<"\n====== Passing an array of integers (automatic) ======\n";
	int A[5];
	FillArray(A, 5); // see how the array is passed
	PrintArray(A, 5);

	// 2- Passing a dynamic array to a function
	cout<<"\n====== Passing an array of integers (dynamic) ======\n";
	int n;
	cout<<"Enter value of n:";
	cin>>n;
	int* P = new int[n];
	FillArray(P, n);
	PrintArray(P, n);
	delete [] P;
	P = NULL;

	// 3- Passing an array of Objects as a function parameter
	cout<<"\n====== Passing an array of Objects ======\n";
	Point* R = new Point[n];  //dynamic array of objects
	FillArrOfObjects(R, n);
	PrintArrOfObjects(R, n);
	
	delete []R;
	R = NULL;

	// 4- Passing an array of pointers as a function parameter
	cout<<"\n====== Passing an array of Pointers ======\n";
	Point** C = new Point*[n]; //see how array of pointes is dynamically allocated 
	/// [Q4] How many bytes are allocated after the above line is executed? 

	for(int i=0; i<n; i++)
		C[i] = NULL;	//initialize all pointers to NULL
	
	//Let's allocate some points in this array
	if(n>0)
	{
		C[0] = new Point;
		C[0]->x = 10;
		C[0]->y = 20;
	}

	if(n>3)
	{
		C[3] = new Point;
		C[3]->x = 30;
		C[3]->y = 40;
	}
	cout<<"\nNumber of allocated points="<<CountPoints(C, n);
	//deallocating array of pointers
	for (int i = 0; i < n; i++)
	{
		if(C[i]) delete C[i];
	}
	delete[] C;
	C = NULL;

	// 5- Passing Array Pointer by Reference
	// Note: passing arrays is passing its elements by pointer (the array name is pointer to the 1st elem.)
	// so any changes in element values inside the fn. remains after returning from the fn.
	// what if we want the array pointer itself to be changed inside the function and remains after return

	// but what are the cases that we want to change the array pointer itself?
	// if the array pointer, Q, is wanted to points to another array or to NULL before returning from the fn.
	// in other words, if you want to write Q = something; inside the function
	// and makes the Q points to this thing after return


	cout<<"\n====== Passing Array Pointer by Reference ======\n";
	int *Q = new int[n];
	FillArray(Q, n);
	KeepOdds(Q, n);
	PrintArray(Q, n);
	delete [] Q; // Don't forget to de-allocate any dynamicly allocated memory!!
				 // and in the correct location!!
				 // This is the "odds" array taht we allocated it inside 'KeepOdds' fn
				 // and didn't delete it inside the same function
	Q = NULL;
}