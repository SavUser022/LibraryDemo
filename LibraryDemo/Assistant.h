#pragma once
#include "Book.h"
class Assistant
{
private:
	std::vector<Book> tasks;
public:
	Assistant();
	Assistant(std::vector<Book> tasks);
	~Assistant();
	void loadData();
	void saveData();
	void delBook();
	void ShowTheMostBoringBooks() ;
	void displayBooks() const;
	void addB00k();
};

