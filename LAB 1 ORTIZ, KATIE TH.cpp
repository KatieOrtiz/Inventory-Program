//Lab 1 ORTIZ, KATIE TH

#include "inventorycode.h"


int main() 
{
	//Array of structure
	item inventory[100];
	int size = 0;
	int choice = 1;
	//The file is read and stored into the array
	ReadFile(inventory, &size);
	//Continue until user chooses to exit 
	while (choice != 9) 
	{
		choice = ShowMenu();
		switch (choice)
		{
		case 1://Print inventory case
			PrintList(inventory, size);
			break;
		case 2:
			//Search by ID case
			SearchByID(inventory, size);
			break;

		case 3:

			//Search by name case
			SearchByName(inventory, size);
				break;

		case 4:
			//Sort inventory by ID case
			Sort(inventory, size, 0);
			PrintList(inventory, size);
			break;

		case 5:
			//Sort inventory by name case
			Sort(inventory, size, 1);
			PrintList(inventory, size);
			break;

		case 6:
			//Sort inventory by quantity case
			Sort(inventory, size, 2);
			PrintList(inventory, size);
			break;

		case 7:
			//Sort inventory by price case
			Sort(inventory, size, 3);
			PrintList(inventory, size);
			break;

		case 8:
			//Print inventory report 
			PrintReport(inventory, size);
			break;

		case 9:
			//Exit the program
			break;

		default:
			//Invalid input message is printed.
			cout << "The input is invalid. Please try again.\n";
			break;
		}
	}
}