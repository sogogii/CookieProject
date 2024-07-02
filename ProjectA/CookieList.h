/*
	Woo, Sungok

	CS A250
	Project (Part B)
*/

#ifndef COOKIELIST_H
#define COOKIELIST_H

#include "Cookie.h"

class Node
{
public:
	Node() : cookie(), next(nullptr) {}
	Node(const Cookie& newCookie, Node* newNext)
		: cookie(newCookie), next(newNext) {}
	Cookie& getCookie() { return cookie; }
	Node* getNext() const { return next; }
	void setCookie(const Cookie& newCookie) { cookie = newCookie; }
	void setNext(Node* newNext) { next = newNext; }
	~Node() {}
private:
	Cookie cookie;
	Node* next;
};

class CookieList
{
public:
	// Default constructor
	CookieList() : first(nullptr), last(nullptr), count(0) {}
	
	// Functions addCookie
	void addCookie(const Cookie& newCookie);
	void addCookie(const std::string& newName, 
		size_t newCalories, size_t newServings, 
		const std::set<std::string>& newIngredients);
	
	// Accessor function
	size_t getCount() const;

	// Boolean functions
	bool isEmpty() const;
	bool searchCookie(const std::string& cookieName) const;

	// Function printAllCookies
	void printAllCookies() const;

	// Function clearList
	void clearList();

	// Print Cookie Recipes (selection b)
	void printCookiesSelection() const;
	void printRecipe(size_t location) const;

	// Print Calories (selection c)
	void printCalories(size_t location) const;

	// Print Limited Calories (selection d)
	void printLimitedCalories(size_t maxCalories) const;

	// Print Total Calories (selection e)
	void printTotalCalories(size_t location, size_t myServings) const;
	void printCookiesSelectionE() const;

	// The Big Three
	~CookieList();
	CookieList(const CookieList& anotherCookieList);
	CookieList& operator=(const CookieList&);

private:

	Node* first;
	Node* last;
	size_t count;

	// Print Cookies Recipes (selection b)
	Node* getCookieLocation(size_t location) const;
};

#endif

