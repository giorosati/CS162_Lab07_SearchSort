/*********************************************************************
** Program Filename : main.cpp
** Author : Giovanni Rosati
** email : rosatig@oregonstate.edu
** Date: 2016-02-19
** Description : cpp file with main for for CS162_400 Lab 7
*********************************************************************/

//#includes
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

//usings
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using std::vector;

//function prototypes
void displayMenu();
void intSearch(int searchValue);
void sortValues(string outputFileName);
void binarySearch(int searchValue);

int main()
{
	int menuChoice = 0;
	int searchValue = NULL;
	string outputFileName = "";

	//display menu in while loop
	while (menuChoice != 4)
	{
		displayMenu();
		cin >> menuChoice;
		switch (menuChoice)
		{
		case 1:
			cout << endl;
			cout << "Enter integer to search for: ";
			cin >> searchValue;
			intSearch(searchValue);
			break;
		case 2:
			cout << "Please enter the filename for the output file: " << endl;
			cin >> outputFileName;
			sortValues(outputFileName);
			break;
		case 3:
			cout << endl;
			cout << "Enter integer to search for: ";
			cin >> searchValue;
			binarySearch(searchValue);
			break;
		case 4:
			break;
		}
	} //end menu while loop
	cout << "Goodbye...................." << endl;
	//cin.get();
	return 0;
}

void displayMenu()
{
	cout << endl;
	cout << endl;
	cout << "*************************************************" << endl;
	cout << "*              Choose 1 or 2 or 3 or 4          *" << endl;
	cout << "*             1) Search for a value             *" << endl;
	cout << "*             2) Sort values                    *" << endl;
	cout << "*             3) Binary search                  *" << endl;
	cout << "*             4) Exit                           *" << endl;
	cout << "*************************************************" << endl;
	cout << endl;
}

void intSearch(int searchValue)
{
	cout << "Program will now search for " << searchValue << " in early.txt, middle.txt, end.txt, and none.txt." << endl;
	cin.clear();

	string inputFileName = "";
	int number;
	for (int i = 1; i < 5; i++)
	{
		ifstream inputFile;
		if (i == 1)
		{
			inputFileName = "early.txt";
			inputFile.open("early.txt");
		}
		if (i == 2)
		{
			inputFileName = "middle.txt";
			inputFile.open("middle.txt");
		}
		if (i == 3)
		{
			inputFileName = "end.txt";
			inputFile.open("end.txt");
		}
		if (i == 4)
		{
			inputFileName = "none.txt";
			inputFile.open("none.txt");
		}

		cout << endl;
		cout << "Opening file: " << inputFileName << endl;

		if (!inputFile)
			cout << "Unable to open: " << inputFileName << endl;	//error message if file not opened
		else
		{
			int count = 0;
			while (!inputFile.eof())	//do while data still to be read from file
			{
				inputFile >> number;
				if (number == searchValue) count += 1;
			}
			cout << count << " occurrance(s) of \"" << searchValue << "\" in file \"" << inputFileName << "\"." << endl;
		}
		inputFile.close();
		//cin.ignore();
		cin.clear();
		//cin.get();
	}
}

void sortValues(string outputFileName)
{
	ifstream inputFile;
	ofstream outputFile;
	string inputFileName = "";
	outputFile.open(outputFileName.c_str());
	int number = NULL;
	int exit2 = 0;
	int menuTwoChoice = 0;
	while (exit2 != 1)
	{
		while (menuTwoChoice != 5)
		{
			cout << "Choose which file to sort: " << endl;
			cout << " 1 for early.txt" << endl;
			cout << " 2 for middle.txt" << endl;
			cout << " 3 for end.txt" << endl;
			cout << " 4 for none.txt" << endl;
			cout << " 5 to exit" << endl;
			cin >> menuTwoChoice;
			switch (menuTwoChoice)
			{
			case 1:
				inputFileName = "early.txt";
				inputFile.open("early.txt");
				break;
			case 2:
				inputFileName = "middle.txt";
				inputFile.open("middle.txt");
				break;
			case 3:
				inputFileName = "end.txt";
				inputFile.open("end.txt");
				break;
			case 4:
				inputFileName = "none.txt";
				inputFile.open("none.txt");
				break;
			case 5:
				exit2 = 1;
			}
			if (exit2 != 1)
			{
				vector<int> values;
				cout << endl;
				cout << "Opening file: " << inputFileName << endl;

				if (!inputFile)
					cout << "Unable to open: " << inputFileName << endl;	//error message if file not opened
				else
				{
					int count = 0;
					while (inputFile >> number)	//do while data still to be read from file
					{
						values.push_back(number);
					}
					cout << inputFileName << " before sort: " << endl;
					for (unsigned count = 0; count < values.size() - 1; count++)
					{
						cout << values[count] << " ";
						cout << endl;
					}
					cout << "Press enter to continue." << endl;
					cin.ignore();
					cin.get();

					int temp;			//bubble sort adapted from textbook page 618
					bool swap;
					do
					{
						swap = false;
						for (unsigned count = 0; count < values.size() - 1; count++)
						{
							if (values[count] > values[count + 1])
							{
								temp = values[count];
								values[count] = values[count + 1];
								values[count + 1] = temp;
								swap = true;
							}
						}
					} while (swap);
					//cout << inputFileName << " after sort: " << endl;
					////output of sorted vector
					//for (unsigned count = 0; count < values.size() - 1; count++)
					//{
					//	cout << values[count] << " ";
					//	cout << endl;
					//}
					//cout << "Press enter to continue." << endl;
					//cin.ignore();
					//cin.get();
					inputFile.close();
					cout << "Now writing the sorted values to: " << outputFileName << endl;

					for (unsigned count = 0; count < values.size() - 1; count++)
					{
						outputFile << values[count] << " ";
					}
					outputFile.close();
					ifstream tempFile;
					tempFile.open(outputFileName.c_str());
					cout << "New file named " << outputFileName << " contents: " << endl;
					while (tempFile >> number)
					{
						cout << number << endl;
					}

					cout << "Press enter to continue." << endl;
					cin.get();
				}
			}//vector is destroyed upon exiting this section
		}//while menu loop
	}//while exit loop
}

void binarySearch(int searchValue)
{
	cout << "Program will now search for " << searchValue << " in early.txt, middle.txt, end.txt, and none.txt." << endl;
	cout << "A temporary array will be populated from each file," << endl;
	cout << "this array will then be sorted in ascending order," << endl;
	cout << "and if the value is found, a message will display the" << endl;
	cout << "position of the first found instance of the search value." << endl;
	cout << "If the search value is not found a message indicating that will be displayed." << endl;
	cin.clear();
	string inputFileName = "";
	int number;
	for (int i = 1; i < 5; i++)
	{
		ifstream inputFile;
		if (i == 1)
		{
			inputFileName = "early.txt";
			inputFile.open("early.txt");
		}
		if (i == 2)
		{
			inputFileName = "middle.txt";
			inputFile.open("middle.txt");
		}
		if (i == 3)
		{
			inputFileName = "end.txt";
			inputFile.open("end.txt");
		}
		if (i == 4)
		{
			inputFileName = "none.txt";
			inputFile.open("none.txt");
		}

		cout << endl;
		cout << "Opening file: " << inputFileName << endl;

		if (!inputFile)
			cout << "Unable to open: " << inputFileName << endl;	//error message if file not opened
		else
		{
			vector<int> values;
			//put data in ascending order in a vector
			int count = 0;
			while (inputFile >> number)	//do while data still to be read from file
			{
				values.push_back(number);
			}
			//display of starting vector for testing
			//cout << inputFileName << " before sort: " << endl;
			//for (unsigned count = 0; count < values.size() - 1; count++)
			//{
			//	cout << values[count] << " ";
			//	cout << endl;
			//}
			//cout << "Press enter to continue." << endl;
			//cin.ignore();
			//cin.get();
			int temp;			//bubble sort adapted from textbook page 618
			bool swap;
			do
			{
				swap = false;
				for (unsigned count = 0; count < values.size() - 1; count++)
				{
					if (values[count] > values[count + 1])
					{
						temp = values[count];
						values[count] = values[count + 1];
						values[count + 1] = temp;
						swap = true;
					}
				}
			} while (swap);
			//output  of vector to test for proper sort
			//cout << inputFileName << " after sort: " << endl;
			//for (unsigned count = 0; count < values.size() - 1; count++)
			//{
			//	cout << values[count] << " ";
			//	cout << endl;
			//}
			//cout << "Press enter to continue." << endl;
			//cin.ignore();
			//cin.get();

			//Binary Search adapted from textbook page 601
			int first = 0;
			int last = values.size() - 1;
			int middle;
			int position = -1;
			bool found = false;
			while (!found && first <= last)
			{
				middle = (first + last) / 2;
				if (values[middle] == searchValue)
				{
					found = true;
					position = middle;
				}
				else if (values[middle] > searchValue)
					last = middle - 1;
				else
				{
					first = middle + 1;
				}
			}
			if (position != -1)
			{
				cout << searchValue << " was found at position " << position << " in file " << inputFileName << "." << endl;
			}
			else cout << searchValue << " was NOT found in " << inputFileName << "." << endl;
		}
		inputFile.close();
	}
}