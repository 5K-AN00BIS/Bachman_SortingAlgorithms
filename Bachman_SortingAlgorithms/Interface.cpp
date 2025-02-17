#include <fstream>
#include <chrono>
#include "Interface.h"

using namespace std;

// Build out the testing suite. Not quite sure how to do this, but wanted it in the code so I could at least start on it.
bool LinkedListTestingSuite()
{
	// Starts off the test_success as true so it's guaranteed to run at least once and resets whenever called.
	bool test_success = true;

	// Create a new LinkedList for testing
	LinkedList<int>* testingList = new LinkedList<int>();

	// Check to see if the list is created empty as intended.
	if (testingList->isEmpty())
	{
		cout << "The list was created and is empty as needed." << endl;
	}
	else
	{
		cout << "Something was on the ship the whole time. This list didn't create empty." << endl;
		test_success = false; // Set test_success to false so we can let the user know something failed.
	}

	return test_success;
}

// Interface with the user to let them know if tests were good or not.
bool TestingSuite()
{
	system("cls"); // Clear the screen for the user.
	bool list_test_status = LinkedListTestingSuite();

	if (list_test_status) // If the status is successful and the bool is still true
	{
		cout << "All tests were run successfully. Everything is working as intended!\n" << endl;
		return true;
	}
	else // Something failed in the testing so test_success is set to false.
	{
		cout << "At least one test has failed! Uh oh!\n" << endl;
		return false;
	}
}

// Creates the interface class, which will be the meat and potatoes of this entire program.
void Interface()
{
	// Create a new LinkedList for integers in this scenario.
	LinkedList<int>* numberList = new LinkedList<int>();

	// Create a new variable to store user menu integer.
	int menuSelection = -1;
	int menuSelection2 = -1;
	// Input value
	char input[6];
	int hold; // Holds the value of input in some scenarios.
	// File I/O
	ifstream fileInput;

	// While loop to resurface the menu as long as the user does not want to exit the program.
	while (menuSelection != 0)
	{
		// Displays the menu to the user and asks for input to traverse the settings.
		cout << "Welcome to Ryan Bachman's Linked List project for CSC382!" << endl;
		cout << "Please select what you'd like to do in the menu below using the designated numbers in parentheses." << endl;
		cout << "(1) Find information in the linked list." << endl;
		cout << "(2) Fill the nodes with a data file." << endl;
		cout << "(3) Clear the linked list." << endl;
		cout << "(4) Print the contents of the nodes." << endl;
		cout << "(5) Choose a sorting method." << endl;
		cout << "(6) Automated Testing Suite" << endl;
		cout << "(0) Exit the program." << endl;
		cout << "\nPlease enter the number corresponding to the action you want to take: ";
		cin >> menuSelection;

		// Switch for menu selection and interaction.
		switch (menuSelection)
		{
		case 1: // If menuSelection is equal to 1.
		{
			system("cls"); // Clear the screen for a clean interface.
			cout << "You've elected to find info.\n" << endl;
			// Ask user for input
			cout << "Please enter the integer you want to find in the list: " << endl;
			cin >> input;
			hold = atoi(input); // Convert string input to integer for this assignment.

			// Check to see if the linked list is empty first.
			if (numberList->isEmpty())
			{
				cout << "There is nothing to search. It's empty! Try adding nodes by using 2 in menu!\n" << endl;
			}
			else // If not empty, use the LinkedList search function to find out if information has been found in the list.
			{
				numberList->findNode(hold); // Call the search function.
			}

			break; // End the case.
		}
		case 2: // If menuSelection is equal to 2.
		{
			system("cls"); // Clear the screen for a clean interface.
			cout << "You've elected to fill the nodes.\n" << endl;
			// Ask user for input
			// Display a new menu to choose which data file to fill the nodes with.
			cout << "Please select a data file element count below." << endl;
			cout << "(1) 10 elements." << endl;
			cout << "(2) 100 elements." << endl;
			cout << "(3) 1,000 elements." << endl;
			cout << "(4) 10,000 elements." << endl;
			cout << "(5) 100,000 elements." << endl;
			cout << "(6) 1,000,000 elements." << endl;
			cout << "(0) Go back to previous menu." << endl;
			cout << "\nPlease enter the number corresponding to the action you want to take: ";
			cin >> menuSelection2;

			switch (menuSelection2)
			{
			case 1: // If menuSelection2 is equal to 1, input 10 element file.
			{
				system("cls");
				// Variable to keep track of the items listed in the file.
				int tracker;
				// Open the file the user wants.
				fileInput.open("num10.dat");
				
				// Checks if the file is open using the information above.
				if (fileInput.is_open())
				{
					// While loop that goes while fileInput has not read all of the data.
					while (fileInput >> tracker)
					{
						// Insert the number from each line in the data file to a node in the linked list.
						numberList->insertAtTail(tracker);
					}
				}
				else // The file was not opened.
				{
					std::cout << "The file cannot be opened... Please make sure the project folder has the data files included." << std::endl << std::endl;
				}

				fileInput.close();
				menuSelection2 = -1;
				break;
			}
			case 2: // If menuSelection2 is equal to 2, input 100 element file.
			{
				system("cls");
				// Variable to keep track of the items listed in the file.
				int tracker;
				// Open the file the user wants.
				fileInput.open("num100.dat");

				// Checks if the file is open using the information above.
				if (fileInput.is_open())
				{
					// While loop that goes while fileInput has not read all of the data.
					while (fileInput >> tracker)
					{
						// Insert the number from each line in the data file to a node in the linked list.
						numberList->insertAtTail(tracker);
					}
				}
				else // The file was not opened.
				{
					std::cout << "The file cannot be opened... Please make sure the project folder has the data files included." << std::endl << std::endl;
				}

				fileInput.close();

				menuSelection2 = -1;
				break;
			}
			case 3: // If menuSelection2 is equal to 3, input 1,000 element file.
			{
				system("cls");
				// Variable to keep track of the items listed in the file.
				int tracker;
				// Open the file the user wants.
				fileInput.open("num1000.dat");

				// Checks if the file is open using the information above.
				if (fileInput.is_open())
				{
					// While loop that goes while fileInput has not read all of the data.
					while (fileInput >> tracker)
					{
						// Insert the number from each line in the data file to a node in the linked list.
						numberList->insertAtTail(tracker);
					}
				}
				else // The file was not opened.
				{
					std::cout << "The file cannot be opened... Please make sure the project folder has the data files included." << std::endl << std::endl;
				}

				fileInput.close();

				menuSelection2 = -1;
				break;
			}
			case 4: // If menuSelection2 is equal to 4, input 10,000 element file.
			{
				system("cls");
				// Variable to keep track of the items listed in the file.
				int tracker;
				// Open the file the user wants.
				fileInput.open("num10000.dat");

				// Checks if the file is open using the information above.
				if (fileInput.is_open())
				{
					// While loop that goes while fileInput has not read all of the data.
					while (fileInput >> tracker)
					{
						// Insert the number from each line in the data file to a node in the linked list.
						numberList->insertAtTail(tracker);
					}
				}
				else // The file was not opened.
				{
					std::cout << "The file cannot be opened... Please make sure the project folder has the data files included." << std::endl << std::endl;
				}

				fileInput.close();

				menuSelection2 = -1;
				break;
			}
			case 5: // If menuSelection2 is equal to 5, input 100,000 element file.
			{
				system("cls");
				// Variable to keep track of the items listed in the file.
				int tracker;
				// Open the file the user wants.
				fileInput.open("num100000.dat");

				// Checks if the file is open using the information above.
				if (fileInput.is_open())
				{
					// While loop that goes while fileInput has not read all of the data.
					while (fileInput >> tracker)
					{
						// Insert the number from each line in the data file to a node in the linked list.
						numberList->insertAtTail(tracker);
					}
				}
				else // The file was not opened.
				{
					std::cout << "The file cannot be opened... Please make sure the project folder has the data files included." << std::endl << std::endl;
				}

				fileInput.close();

				menuSelection2 = -1;
				break;
			}
			case 6: // If menuSelection2 is equal to 5, input 1,000,000 element file.
			{
				system("cls");
				// Variable to keep track of the items listed in the file.
				int tracker;
				// Open the file the user wants.
				fileInput.open("num1000000.dat");

				// Checks if the file is open using the information above.
				if (fileInput.is_open())
				{
					// While loop that goes while fileInput has not read all of the data.
					while (fileInput >> tracker)
					{
						// Insert the number from each line in the data file to a node in the linked list.
						numberList->insertAtTail(tracker);
					}
				}
				else // The file was not opened.
				{
					std::cout << "The file cannot be opened... Please make sure the project folder has the data files included." << std::endl << std::endl;
				}

				fileInput.close();

				menuSelection2 = -1;
				break;
			}
			case 0: // If menuSelection2 is equal to 0.
			{
				system("cls");
				menuSelection2 = -1;
				break;
			}
			default: // If menuSelection2 is equal to anything else.
			{
				system("cls"); // Clear the screen for a clean interface.
				cout << "Incorrect selection. Please use the numbers in parentheses to interact with the menu.\n" << endl;
				menuSelection2 = -1;
				break;
			}
			}

			break;
		}
		case 3: // If menuSelection is equal to 3.
		{
			system("cls"); // Clear the screen for a clean interface.
			cout << "You've elected to clear the linked list. NOT WORKING RIGHT NOW. RESTART THE APPLICATION TO CLEAR...\n" << endl;

			/*// Initiates the iterator at the head to get it ready for work.
			Iterator<int>* i = numberList->iteratorHead();
			Node<int>* search;

			// Searches nodes for the value that is needing removal
			while ((search = i->nextNode()) != NULL)
			{
				numberList->removeNode(search);
			}

			if (search == NULL)
			{
				// Let the user know if the value was not found in the linked list.
				cout << "The value was either not found or the list was empty. Try adding it using 2 in the menu!\n" << endl;
			}
			else
			{
				// Remove if from the list if it's found.
				if (numberList->removeNode(search))
				{
					cout << "The value has been removed successfully!\n" << endl;
				}
				else // Catches for a generic error.
				{
					cout << "Unknown failure." << endl;
				}
			}

			delete i; // Delete the iterator to free up memory.*/
			break; // End the case.
		}
		case 4: // If menuSelection is equal to 4.
		{
			system("cls"); // Clear the screen for a clean interface.
			cout << "Printing the nodes...\n" << endl;

			// Check to see if the list is empty, otherwise print out all of the nodes.
			if (numberList->isEmpty())
			{
				cout << "The list is empty! Try adding to it by selecting 2 from the menu.\n" << endl;
			}
			else
			{
				cout << endl << "Integers in the list:" << endl;

				// Uses the iterator to list all the numbers.
				Iterator<int>* i = numberList->iteratorHead();
				Node<int>* list;

				// List all of the nodes.
				while ((list = i->nextNode()) != NULL)
				{
					cout << list->nodeData << "   ";
				}
				cout << endl << endl;

				// Delete the iterator once done to free up memory.
				delete i;
			}

			break; // End the case.
		}
		case 5: // If menuSelection is equal to 5.
		{
			system("cls"); // Clear the screen for a clean interface.
			cout << "You've elected to sort.\n" << endl;
			
			// Display a new menu to choose which sort the user will want to use.
			cout << "Please select what type of sort you want to do below." << endl;
			cout << "(1) Insertion Sort." << endl;
			cout << "(2) Bubble Sort." << endl;
			cout << "(3) Quick Sort." << endl;
			cout << "(0) Go back to previous menu." << endl;
			cout << "\nPlease enter the number corresponding to the action you want to take: ";
			cin >> menuSelection2;

			switch (menuSelection2)
			{
			case 1: // If menuSelection2 is equal to 1, insertion sort.
			{
				system("cls");
				// Check to see if the linked list is empty first.
				if (numberList->isEmpty())
				{
					cout << "There is nothing to search. It's empty! Try adding nodes by using 2 in menu!\n" << endl;
				}
				else // If not empty, use the LinkedList search function to find out if information has been found in the list.
				{
					// Start timer
					auto start = std::chrono::high_resolution_clock::now();
					// Run insertion sort.
					numberList->insertionSort();
					// End timer
					auto finish = std::chrono::high_resolution_clock::now();
					// Calculate the duration
					std::chrono::duration<double> elapsed = finish - start;
					// Report back to the user how long it took.
					cout << "Insertion sort completed. This process took " << elapsed.count() << " seconds." << endl << endl;
				}

				menuSelection2 = -1;
				break;
			}
			case 2: // If menuSelection2 is equal to 2, merge sort.
			{
				system("cls");
				// Check to see if the linked list is empty first.
				if (numberList->isEmpty())
				{
					cout << "There is nothing to search. It's empty! Try adding nodes by using 2 in menu!\n" << endl;
				}
				else // If not empty, use the LinkedList search function to find out if information has been found in the list.
				{
					// Start timer
					auto start = std::chrono::high_resolution_clock::now();
					// Run insertion sort.
					numberList->bubbleSort();
					// End timer
					auto finish = std::chrono::high_resolution_clock::now();
					// Calculate the duration
					std::chrono::duration<double> elapsed = finish - start;
					// Report back to the user how long it took.
					cout << "Insertion sort completed. This process took " << elapsed.count() << " seconds." << endl << endl;
				}

				menuSelection2 = -1;
				break;
			}
			case 3: // If menuSelection2 is equal to 3, quick sort.
			{
				system("cls");
				// Check to see if the linked list is empty first.
				if (numberList->isEmpty())
				{
					cout << "There is nothing to search. It's empty! Try adding nodes by using 2 in menu!\n" << endl;
				}
				else // If not empty, use the LinkedList search function to find out if information has been found in the list.
				{
					// Start timer
					auto start = std::chrono::high_resolution_clock::now();
					// Run insertion sort.
					numberList->quickSort();
					// End timer
					auto finish = std::chrono::high_resolution_clock::now();
					// Calculate the duration
					std::chrono::duration<double> elapsed = finish - start;
					// Report back to the user how long it took.
					cout << "Insertion sort completed. This process took " << elapsed.count() << " seconds." << endl << endl;
				}

				menuSelection2 = -1;
				break;
			}
			case 0: // If menuSelection2 is equal to 0.
			{
				system("cls");
				menuSelection2 = -1;
				break;
			}
			default: // If menuSelection2 is equal to anything else.
			{
				system("cls"); // Clear the screen for a clean interface.
				cout << "Incorrect selection. Please use the numbers in parentheses to interact with the menu.\n" << endl;
				menuSelection2 = -1;
				break;
			}
			}

			break;
		}
		case 6: // If menuSelection is equal to 6.
		{
			system("cls"); // Clear the screen for a clean interface.
			cout << "You've started the Automated Testing Suite.\n" << endl;
			TestingSuite();
			break;
		}
		case 0: // If menuSelection is equal to 0.
		{
			system("cls"); // Clear the screen for a clean interface.
			cout << "Closing the program.\n" << endl;
			break;
		}
		default: // If menuSelection is equal to anything else.
		{
			system("cls"); // Clear the screen for a clean interface.
			cout << "Incorrect selection. Please use the numbers in parentheses to interact with the menu.\n" << endl;
			menuSelection = -1;
			break;
		}
		}

	}
}