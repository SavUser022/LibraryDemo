#include "Header.h"
#include "Menu.h"
#include "Assistant.h"
#include "Book.h"


int main()
{
	int k;
	bool stop = false;
	// Start
	std::string name = "Digital Library";
	std::vector<std::string> numbers =
	{
			"Show the library",
			"Show the most boring books",
			"Delete book",
			"Add new book",
	};
	std::unique_ptr<Menu> hello (new Menu(name, numbers));
	std::unique_ptr<Assistant> manager (new Assistant);
	manager->loadData();
	do
	{
		std::cout << std::endl;
		hello->displayMenu();
		switch (k = hello->getChoice())
		{
		case 1:
			manager->displayBooks();
		case 2:
			manager->ShowTheMostBoringBooks();
			break;
		case 3:
			manager->delBook();
			break;
		case 4:
			manager->addB00k();
			break;
		default:
			std::cout << "Impossible choice!" << std::endl;
			break;
		}if(stop) { break;}
	} while (hello->allowContinue() == false);

	// Finish
}

