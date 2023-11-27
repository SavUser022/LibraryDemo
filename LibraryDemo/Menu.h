#pragma once
class Menu
{
private:
	std::string appName;
	std::vector<std::string> choices;
public:
	Menu();
	Menu(std::string appName, std::vector<std::string> choices);
	//Menu(const Menu& item);
	~Menu();
	int getChoice();
	bool allowContinue();
	void displayMenu();

};

