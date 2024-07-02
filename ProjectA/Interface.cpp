/*
	Woo, Sungok

	CS A250
	Project (Part D)

	1. SELECTION NAME: Print Total Calories
	2. PURPOSE: This selection will ask the user to choose 
	one cookie and servings they want, and based on the 
	user's choice, it will print total calories
	Assumption: User chooses one of the cookies.
	Exception: If user chooses servings over prepared servings,
	it will show error message.
	3. EXPECTED OUTPUT:

--------------------------------------------------------------
	TOTAL CALORIES
--------------------------------------------------------------

Choose a cookie to view the recipe.
	1: Lemon Square Bars
	2: Biscotti
	3: Nutella Brownies
	4: Butter Snow Flakes
	5: Chocolate Chip Cookies
	6: Oatmeal Cookies
	7: Walnut Tassies
	8: Jam Thumbprints
	9: Gingersnaps
	10: Meringues
	11: Pizzelles
	12: Snickerdoodles

Your choice: 1
How many cookies?: 7

	Lemon Square Bars (total calories: 136 (calories) * 7 (servings) = 952)

	4. TEST CASES:
		Choice 1, Servings 7 (first, decent value)
		Choice 6, Servings 5 (middle, decent value)
		Choice 12, Servings 6 (last, decent value)
		Choice 1, Servings 100 (first, extreme value)
		Choice 6, Servings 100 (middle, extreme value)
		Choice 12, Servings 100 (last, extreme value)
*/

#include "Interface.h"

#include <iostream>
#include <string>
using namespace std;

// Definition function displayMenu
void displayMenu()
{
	// Print upper stars
	for (int i = 0; i < 62; ++i)
	{
		cout << "*";
	}
	cout << endl;
	
	// Print COOKIE RECIPES
	for (int i = 0; i < 24; ++i)
	{
		cout << " ";
	}
	cout << "COOKIE RECIPES";
	cout << endl;

	// Print lower stars
	for (int i = 0; i < 62; ++i)
	{
		cout << "*";
	}
	cout << endl << endl;

	// Print main part
	cout << "Select one of the following: "
		 << endl << endl;

	cout << "    a. Print all recipes" << endl
		 << "    b. Print cookie recipe" << endl
		 << "    c. Print cookie calories" << endl
		 << "    d. Print limited calories" << endl
		 << "    e. Calories calculator" << endl
		 << "    f. To exit" << endl;
}

// Definition function processChoice
void processChoice(CookieList& cookieList)
{
	char tryAgain = 'y';
	char userChoice = '0';

	while (tryAgain == 'y')
	{
		displayMenu(); // displaying menu
		cout << endl;

		cout <<	"Enter your choice: ";
		cin >> userChoice;
		cout << endl;

		switch (userChoice)
		{
			case 'a': case 'A':
			{
				for (int i = 0; i < 62; ++i)
					cout << "-";
				cout << endl;

				cout << "    COOKIE RECIPES" << endl;

				for (int i = 0; i < 62; ++i)
					cout << "-";
				cout << endl << endl;

				cookieList.printAllCookies();
				break;
			}

			case 'b': case 'B':
			{
				for (int i = 0; i < 62; ++i)
					cout << "-";
				cout << endl;

				cout << "    COOKIE RECIPE" << endl;

				for (int i = 0; i < 62; ++i)
					cout << "-";
				cout << endl << endl;

				cout << "Choose a cookie to view the recipe." << endl
					 << endl;

				cookieList.printCookiesSelection();
				cout << endl;
				size_t location = 0;
				cout << "Your choice: ";
				cin >> location;
				cout << endl;

				cookieList.printRecipe(location);
				break;
			}

			case 'c': case 'C':
			{
				for (int i = 0; i < 62; ++i)
					cout << "-";
				cout << endl;

				cout << "    COOKIE CALORIES" << endl;

				for (int i = 0; i < 62; ++i)
					cout << "-";
				cout << endl << endl;

				cout << "Choose a cookie #"
					 << "to view number of calories."
					 << endl << endl;

				cookieList.printCookiesSelection();
				cout << endl;
				size_t location = 0;
				cout << "Your choice: ";
				cin >> location;
				cout << endl;

				cookieList.printCalories(location);
				break;
			}

			case 'd': case 'D':
			{
				for (int i = 0; i < 62; ++i)
					cout << "-";
				cout << endl;

				cout << "    MAXIMUM CALORIES" << endl;

				for (int i = 0; i < 62; ++i)
					cout << "-";
				cout << endl << endl;

				size_t maxCalories = 0;
				cout << "What is the maximum # of calories" 
					 << "(100-200)? ";
				cin >> maxCalories;
				cout << endl;

				cookieList.printLimitedCalories(maxCalories);
				break;
			}

			case 'e': case 'E':
			{
				for (int i = 0; i < 62; ++i)
					cout << "-";
				cout << endl;

				cout << "    TOTAL CALORIES" << endl;

				for (int i = 0; i < 62; ++i)
					cout << "-";
				cout << endl << endl;

				cout << "Choose any cookie you want to take!"
					 << endl << endl;

				cookieList.printCookiesSelectionE();
				cout << endl;
				size_t location = 0;
				cout << "Your choice: ";
				cin >> location;
				
				size_t myServings = 0;
				cout << "How many cookies you want?: ";
				cin >> myServings;
				cout << endl;

				cookieList.printTotalCalories(location, myServings);
				break;
			}

			case 'f': case 'F':
			{
				cout << "Thank you for using our software. Good bye!"
					 << endl;
				tryAgain = 'n';
				break;
			}
				
			default:
				cout << " => Sorry. This is not a selection." 
					 << endl;
		}

		if (tryAgain == 'y')
		{ 
			cout << endl;
			for (int i = 0; i < 62; ++i)
				cout << "=";

			cout << endl << endl;

			cout << "Would you like to try again (y/n)? ";
			cin >> tryAgain;
			cout << endl;

			if (tryAgain == 'n')
				cout << "Thank you for using our software."
					 << "Good bye!";
		}
	}
}