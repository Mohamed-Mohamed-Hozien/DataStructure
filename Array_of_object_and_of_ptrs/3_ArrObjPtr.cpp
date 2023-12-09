// Lab 1: Pointers, Arrays and Functions
// Example3: Array of Objects and Array of Pointers

//**  THIS File Contains 7 Questions (Q1 to Q7) **//

#include <iostream>
using namespace std;

struct Point //to represent 2D point (x,y)
{
	double x;
	double y;
};

struct Car	//simple struct to represent a Car in a park
{
	int CarNo;
	int LicenseNo;
	long OwnerSSN;
};

int main()
{
	// 1- Array of objects (Automatic & Dynamic)-------------------

	Point A[10];  //Array of 10 points (automatic allocation)

	/// [Q1] What is the type of the variable A? What is the type of item A[0]?
	/// [Q2] What is the size of the variable A? 
	/// [Q3] How many bytes are allocated after the above line is executed? 

	//Filling array with dummy values
	for(int i=0; i<10; i++)
	{
		A[i].x = i;	//remember the dot operator
		A[i].y = 2*i;
	}

	//Printing array items
	for(int i=0; i<10; i++)
	{
		cout<<"Point #"<<i+1<<":";
		cout<<" x = "<< A[i].x <<" y = "<< A[i].y <<endl;
	}


	//Dynamic allocation of array of objects
	Point *B;
	/// [Q4] How many bytes are allocated after the above line is executed? 

	int n;
	cout<<"Please enter dynamic array size:";
	cin>>n;	//get array size from the user
	
	cout<<"Allocating array of "<<n<<" points DYNAMICALLY"<<endl;
	B = new Point[n]; //Array of n points (dynamic allocation)
	/// [Q5] How many bytes are allocated after the above line is executed? 

	//Array items can be accessed the same way as shown in array A above
	//For example to set x,y to 4,5 at point at index 1 (2nd point), you write
	B[1].x = 3;   B[1].y = 4;


	cout<<"\nPrinting dynamic array items:\n";
	//Printing array items
	for(int i=0; i<n; i++)
	{
		cout<<"Point #"<<i+1<<":";
		cout<<" x = "<< B[i].x <<" y = "<< B[i].y <<endl;
	}
	//To delete Array B
	cout<<"Deleting the dynamic array";
	delete []B;
	B = NULL; //why?

	// 2- Array of pointers to objects -------------------
	// Assume we have a car park and we want to store info of each car in the parking slots
	// Assume the park has 30 slots. Each slot may be free or has a car occupying it
	// empty slots will be represented as NULL
	Car* ParkSlots[30];  //Array of 30 pointers to cars.
	/// [Q6] How many bytes are allocated after the above line is executed? 

	//initialize all slots to "empty"
	for(int i=0; i<30; i++)
		ParkSlots[i] = NULL;
	
	//Adding cars to the parking slots
	cout<<"\n\n======== Array of pointers (to Car) Demo =============\n";
	cout<<"Adding cars to the parking slots\n";
	int m;
	do
	{
		cout<<"Enter slot index (-1 to end):";
		cin>>m;
		if(m != -1)  //you should also check that 0<= m <= 29
		{
			if(ParkSlots[m] == NULL)
			{	//Add a car to slot m
				ParkSlots[m] = new Car;  //allocating a new car for pointer at index m
				cout<<"Enter Car info:\n";
				cout<<"Car No.:";
				cin>>ParkSlots[m]->CarNo;  //see how info of object pointed to by pointer m is read
				cout<<"License No.:";
				cin>>ParkSlots[m]->LicenseNo;
				cout<<"Owner SSN:";
				cin>>ParkSlots[m]->OwnerSSN;
			}
			else
				cout<<"Slot is not empty";
		}
	}while( m != -1);

	//De-allocating dynamic memory used by array ParkSlots
	cout<<"\nDeallocating memory used by array of pointers";
	for(int i=0; i<30; i++)
		if(ParkSlots[i])  //if not NULL (what if we forgot to write this condition?)
		{
			cout<<"\nDeleting Car no. "<<ParkSlots[i]->CarNo<<" at slot #"<<i;
			delete ParkSlots[i]; //free memory at this slot
		}

	/// [Q7] In example above, the no. of slots is assumed to be 30
	// what if we want to read the no. of slots from the user and allocate it dynamically too
	// Try to make it and ask if there is problem

	cout<<endl;
	return 0;

}
