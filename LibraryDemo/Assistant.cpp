#include "Header.h"
#include "Assistant.h"
#include "Book.h"

Assistant::Assistant() : tasks()
{
}

Assistant::Assistant(std::vector<Book> tasks) : tasks(tasks)
{

}



Assistant::~Assistant()
{
}

void Assistant::loadData()
{
	
	std::ifstream fin;
	fin.open("BookStorage.txt");
	tasks.clear();
	while (!fin.eof())
	{
		int id;
		std::string Name;
		std::string Size;
		std::string BoringLevel;
		std::string Author;
		std::string Year;

		fin >> id;
		fin.ignore();
		std::getline(fin, Size);
		std::getline(fin, Name);
		std::getline(fin, BoringLevel);
		std::getline(fin, Author);
		std::getline(fin, Year);

		Book book(id, Name, Size, BoringLevel, Author, Year);
		tasks.push_back(book);
		std::cout << "The data has been loaded" << std::endl;
	}
	tasks.pop_back();
	fin.close();
}

void Assistant::saveData()
{
	
	std::ofstream fout;
	fout.open("BookStorage.txt");

	for (int i = 0; i < tasks.size(); i++)
	{
		Book item = tasks.at(i);
		fout << tasks.at(i).getId() << std::endl;
		fout << tasks.at(i).getName() << std::endl;
		fout << tasks.at(i).getBoringLevel() << std::endl;
		fout << tasks.at(i).getAuthor() << std::endl;
		fout << tasks.at(i).getYear() << std::endl;
		fout << tasks.at(i).getName() << std::endl;
	}
	fout.close();
	std::cout << "The data has been saved" << std::endl;
}

void Assistant::delBook()
{
	int id;
	std::cout << "Input id of book" << std::endl;
	std::cin >> id;
	
	auto iter = std::find_if(tasks.begin(), tasks.end(), [id](Book& item)
		{return (item.getId() == id); });

	if (iter == tasks.end())
	{
		std::cout << "The book with ID " << id << " isn't exist" << std::endl;
	}
	else
	{
		tasks.erase(iter);
		saveData();
		std::cout << "The book with id " << id << " has been added to library" << std::endl;
	}
}

void Assistant::ShowTheMostBoringBooks() 
{
	std::for_each(tasks.begin(), tasks.end(), [](  Book& item)
		{
			if (item.getBoringLevel() == "9/10")
			{
				item.display();
			}
		});
}

void Assistant::displayBooks() const
{
	if (tasks.empty())
	{
		std::cout << "It's empty" << std::endl;
	}
	else
	{
		const int N = tasks.size();
		std::cout << "There are " << N  << " books in the library." << std::endl;
		for (int i = 0; i < N; i++)
		{
			tasks[i].display();
		}
	}
}

void Assistant::addB00k()
{
	int id;
	std::string Name;
	std::string Size;
	std::string BoringLevel;
	std::string Author;
	std::string Year;

	id = tasks.back().getId() + 1;
	std::cin.ignore();

	std::cout << "Input name of new book" << std::endl;
	std::getline(std::cin, Name);

	std::cout << "Input size of new book" << std::endl;
	std::getline(std::cin, Size);

	std::cout << "Input Boring level of new book" << std::endl;
	std::getline(std::cin, BoringLevel);

	std::cout << "Input author of new book" << std::endl;
	std::getline(std::cin, Author);
	
	std::cout << "Input year of new book" << std::endl;
	std::getline(std::cin, Year);

	Book book(id, Name, Size, BoringLevel, Author, Year);
	tasks.push_back(book);
	saveData();
}