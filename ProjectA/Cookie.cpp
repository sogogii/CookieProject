/*
	Woo, Sungok

	CS A250
	Project (Part A)
*/

#include "Cookie.h"

#include <iostream>
using namespace std;

string Cookie::getName() const
{
	return name;
}

size_t Cookie::getCalories() const
{
	return calories;
}

size_t Cookie::getServings() const
{
	return servings;
}

set<string> Cookie::getIngredients() const
{
	return ingredients;
}

Cookie Cookie::getCookie() const
{
	return Cookie(name, calories, servings, ingredients);
}

void Cookie::setName(const string& newName)
{
	name = newName;
}

void Cookie::setCalories(size_t newCalories)
{
	calories = newCalories;
}

void Cookie::setServings(size_t newServings)
{
	servings = newServings;
}

void Cookie::setIngredients(const vector<string>& newIngredients)
{
	for (auto elem : newIngredients)
	{
		ingredients.insert(elem);
	}
}

void Cookie::printRecipe() const
{
	cout << "    Recipe for " << name;
	cout << endl;

	cout << "        Servings: " << servings;
	cout << endl;
	
	printIngredients();
}

void Cookie::printIngredients() const
{
	cout << "        Ingredients: ";

	cout << *(ingredients.begin());
	for (auto iter = ++ingredients.begin();
		iter != ingredients.end(); ++iter)
	{
		cout << ", " << *iter;
	}
	cout << endl;
}

void Cookie::printCalories() const
{
	cout << "    " << name << " (calories: " << calories
		<< ")" << endl;
}