/*
	Woo, Sungok

	CS A250
	Project (Part B)
*/

#include "CookieList.h"

#include <iostream>
using namespace std;

void CookieList::addCookie(const Cookie& newCookie)
{
	if (first == nullptr)
	{
		first = new Node(newCookie, nullptr);
		last = first;
	}

	else
	{ 
		last->setNext(new Node(newCookie, nullptr));
		last = last->getNext();
	}
	++count;
}

void CookieList::addCookie(const string& newName, size_t newCalories,
	size_t newServings, const set<string>& newIngredients)
{
	Cookie newCookie = Cookie(newName, newCalories, newServings,
		newIngredients);

	if (first == nullptr)
	{
		first = new Node(newCookie, nullptr);
		last = first;
	}

	else
	{
		last->setNext(new Node(newCookie, nullptr));
		last = last->getNext();
	}
	++count;
}

size_t CookieList::getCount() const
{
	return count;
}

bool CookieList::isEmpty() const
{
	return (count == 0);
}

bool CookieList::searchCookie(const string& cookieName) const
{
	Node* current = first;
	while (current != nullptr)
	{
		if (current->getCookie().getName() == cookieName)
			return true;
		current = current->getNext();
	}
	return false;
}

void CookieList::printAllCookies() const
{
	Node* current = first;
	while (current != nullptr)
	{
		cout << "    " << current->getCookie().getName() << endl;
		current = current->getNext();
	}
}

void CookieList::clearList()
{
	while (first != nullptr)
	{
		Node* current = first;
		first = first->getNext();

		delete current;
		--count;
	}
	last = nullptr;
}

void CookieList::printCookiesSelection() const
{
	Node* current = first;
	int index = 1; 

	while (current != nullptr)
	{
		cout << "    " << index << ": "
			 << current->getCookie().getName() << endl;

		current = current->getNext();
		++index;
	}
}

void CookieList::printRecipe(size_t location) const
{
	Node* locationPtr = getCookieLocation(location);
	Cookie locationCookie = locationPtr->getCookie();

	locationCookie.printRecipe();
}

Node* CookieList::getCookieLocation(size_t location) const
{
	Node* current = first;

	while (location != 1)
	{
		current = current->getNext();
		--location;
	}
	
	return current;
}

void CookieList::printCalories(size_t location) const
{
	Node* locationPtr = getCookieLocation(location);
	Cookie locationCookie = locationPtr->getCookie();

	locationCookie.printCalories();
}

void CookieList::printLimitedCalories(size_t maxCalories) const
{
	Node* current = first;

	while (current != nullptr)
	{
		Cookie currentCookie = current->getCookie();
		if (currentCookie.getCalories() <= maxCalories)
			currentCookie.printCalories();
		
		current = current->getNext();
	}
}

void CookieList::printTotalCalories(size_t location,
	size_t myServings) const
{
	Node* locationPtr = getCookieLocation(location);
	Cookie locationCookie = locationPtr->getCookie();

	if (myServings > locationCookie.getServings())
		cout << "OVER PREPARED SERVINGS" << endl;

	else
	{
		cout << "    " << locationCookie.getName() 
			<< " (total calories: " 
			<< locationCookie.getCalories() << " (calories) * " 
			<< myServings << " (servings) = " 
			<< locationCookie.getCalories() * myServings << ")" 
			<< endl;
	}
}

// for menu choice e !!!
void CookieList::printCookiesSelectionE() const
{
	Node* current = first;
	int index = 1;

	while (current != nullptr)
	{
		cout << "    " << index << ": "
			<< current->getCookie().getName()
			<< " (Maximum Servings: "
			<< current->getCookie().getServings()
			<< ")" << endl;

		current = current->getNext();
		++index;
	}
}

// Destructor
CookieList::~CookieList()
{
	if (first == nullptr)
		clearList();
}

// Copy Constructor
CookieList::CookieList(const CookieList& aCookieList)
{
	count = 0;
	first = nullptr;
	last = nullptr;

	Node* current = aCookieList.first;
	while (current != nullptr)
	{
		addCookie(current->getCookie());
		current = current->getNext();
	}
}

// Overloaded Assignment Operator
CookieList& CookieList::operator=(const CookieList& aCookieList)
{
	if (&aCookieList != this)
	{
		clearList();

		Node* current = aCookieList.first;
		while (current != nullptr)
		{
			addCookie(current->getCookie());
			current = current->getNext();
		}
	}

	else
		cerr << "Attempted assignment to itself.";

	return *this;
}