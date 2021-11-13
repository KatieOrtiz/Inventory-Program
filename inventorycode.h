//Lab 1 ORTIZ, KATIE TH

#include<iostream>
#include<string>
#include<fstream>

using namespace std;

//Structure that contains the inventory's ID, name, quantity and price
typedef struct item{
	string _ID;
	string _name;
	string _quantity;
	string _price;

};

//Swap function to swap two structures (for bubble sort)
void Swap(item *xp, item *yp)
{
	item temp = *xp;
	*xp = *yp;
	*yp = temp;
}

//Search by Item ID
void SearchByID(item inventory[100], int size) 
{
	string ID;
	cout << "Please enter an ID: ";//User inputs the ID they're looking for
	cin >> ID;
	for (int i = 0; i < size; i++) {//The inventory is looped through
		if (inventory[i]._ID == ID)//The ID that was entered is checked
			cout << inventory[i]._ID << "\t" << inventory[i]._name << "\t" << inventory[i]._quantity << "\t" << inventory[i]._price << "\n\n";
		return;
	}
	cout << "The item ID was not found.\n\n";
}

//Search by Item Name
void SearchByName(item inventory[100], int size) 
{
	string name;
	cout << "Please enter the item's name: "; //User inputs the item's name they're looking for
	cin >> name;

	for (int i = 0; i < size; i++)
	{
		if (inventory[i]._name.compare(name)== 0) 
		{
			cout << inventory[i]._ID << "\t" << inventory[i]._name << "\t" << inventory[i]._quantity << "\t" << inventory[i]._price << endl << endl;
			return;
		}
			
	}
	cout << "The item name was not found in the list.\n\n"; 
}


//Bubble sort is used to sort
void Sort(item inventory[100], int size, int sortBy)
{
	int i, j;
	bool condition;
	for (i = 0; i < size - 1; i++) 
	{
		for (j = 0; j < size - i - 1; j++) 
		{
			//The condition is checked based on the user's selection
			if (sortBy == 0) {
				condition = inventory[j]._ID > inventory[j + 1]._ID;
			}
			else if (sortBy == 1) {
				condition = inventory[j]._name > inventory[j + 1]._name;
			}
			else if (sortBy == 2) {
				condition = inventory[j]._quantity > inventory[j + 1]._quantity;
			}
			else if (sortBy == 3) {
				condition = inventory[j]._price > inventory[j + 1]._price;
			}
			if (condition) 
			{ //If condition is true, then swap
				Swap(&inventory[j], &inventory[j + 1]);
			}
		}
	}
}

//Input file is read
void ReadFile(item inventory[100], int* size)
{
	ifstream file("Inventory.txt");
	if (file.is_open())
	{
		string line;
	
		while (getline(file, line)) 
		{
			size_t pos = 0;
			string token;
			item temp;
			pos = line.find(" ");//Finding the position of the space
			token = line.substr(0, pos);//Getting the substring from start to the location of the space
			temp._ID = token;//ID is retrieved first
			
			line.erase(0, pos + 1);//The ID part is removed from line
			//The process is repeated for name,price and quantity
			pos = line.find(" ");
			token = line.substr(0, pos);
			temp._name = token;
			line.erase(0, pos + 1);

			pos = line.find(" ");
			token = line.substr(0, pos);
			temp._quantity = token;
			line.erase(0, pos + 1);
			temp._price = line;
			inventory[*size] = temp;
			*size = *size + 1;
		}
		file.close();
	}
	else 
	{
		cout << "ERROR: The file was unabled to be opened.\n";
		EXIT_SUCCESS;
	}
}

//The inventory list is printed
void PrintList(item inventory[100], int size) 
{
	cout << "\n=============================================\n";
	cout << "=================Inventory===================\n";
	cout << "=============================================\n";
	for (int i = 0; i < size; i++) 
	{
		cout << inventory[i]._ID << "\t" << inventory[i]._name << "\t" << inventory[i]._quantity << "\t" << inventory[i]._price << "\n";
	}
	cout << "=============================================\n\n";
}

//Printing report of unique items in the inventory, total worth of the inventory, and the total count of all items
void PrintReport(item inventory[100], int size) 
{
	cout << "\n=============================================\n";
	cout << "=================Inventory Report ===================\n";
	cout << "=============================================\n";

	float val, val2, val3, val4, val5, val6, item, item2, item3, item4, totalworth, totalitems;
	int itemcounter = 1;
	string currentid;
	string lastID;
	for (int i = 0; i < size; i++) 
	{
		
		if (lastID != currentid) 
		{
			itemcounter++;
		}
		
			if (i == 0) 
			{
				val = stof(inventory[i]._price);
				val2 = stof(inventory[i]._quantity);
				currentid = inventory[i]._ID;
				lastID = currentid;

				itemcounter++;
				i++;
				currentid = inventory[i]._ID;
				
			}

			if (i == 1) 
			{
				val3 = stof(inventory[i]._price);
				val4 = stof(inventory[i]._quantity);
				currentid = inventory[i]._ID;
				lastID = currentid;

				itemcounter++;
				i++;
				currentid = inventory[i]._ID;
			}

			
			val5 = stof(inventory[i]._price);
			val6 = stof(inventory[i]._quantity);

			item = val * val2;
			item2 = val3 * val4;
			item3 = val5 * val5;
			item4 = val2 + val4 + val6;
			
			currentid = inventory[i]._ID;
					
	}
	
	totalworth = item + item2 + item3;
	totalitems = item4;
	cout << "The total worth of the inventory is: " << totalworth << "\n" << "The total count of the items: " << totalitems << "\n" << "The total amount of unique items = " << itemcounter << "\n";
	cout << "=============================================\n\n";
}

//Function to display the menu to the user 
int ShowMenu() 
{
	int choice = 8;
	//Menu is displayed
	cout << "Please choose :\n";
	cout << "1) Print Inventory.\n";
	cout << "2) Search By ID.\n";
	cout << "3) Search By Name.\n";
	cout << "4) Sort By ID.\n";
	cout << "5) Sort By Name.\n";
	cout << "6) Sort By Quantity.\n";
	cout << "7) Sort By Price.\n";
	cout << "8) Print Inventory Report.\n";
	cout << "9) Exit.\n";
	//User input of choice
	cin >> choice;
	//If choice is not within range, user is asked to input choice again 
	while (choice < 1 || choice > 9)
	{
		cout << "Please choose valid input: ";
		cin >> choice;
	}
	//clearing cin
	cin.clear();
	cin.ignore();
	return choice;
}
