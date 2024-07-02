/*
	Woo, Sungok

	CS A250
	Project (Part A)
*/

#include "Cookie.h"
#include "CookieDB.h"
#include "CookieList.h"
#include "Testing.h"
#include "Interface.h"

#include <iostream>
using namespace std;

int main()
{
	CookieList list1;
	createCookieList(list1);

	processChoice(list1);

	cout << endl;
	system("Pause");
	return 0;
}