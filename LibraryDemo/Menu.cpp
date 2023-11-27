#include "Header.h"
#include "Menu.h"

Menu::Menu() : appName("NO NAME"), choices(0)
{
}

Menu::Menu(std::string appName, std::vector<std::string> choices) : appName(appName), choices(choices)
{
}
/*
Menu::Menu(const Menu& item)
{
	this->appName = item.appName;
	this->choices = std::vector<std::string> ()
}
*/
Menu::~Menu()
{
}

int Menu::getChoice()
{
	int number;
	std::cout << " Make your choice please." << std::endl;
	std::cin >> number;
	return number;
}

bool Menu::allowContinue()
{
	std::cout << "Do you want to continue?" << std::endl;
	char yes;
	std::cin >> yes;
	return (yes == 'y');
}

void Menu::displayMenu()
{
	int N = choices.size();
	for (int i = 0; i < N; i++)
	{
		std::cout << choices.at(i) << std::endl;
	}
}
