#pragma once
class Book
{
private:
	int id;
	std::string name;
	std::string size;
	std::string author;
	std::string year;
	std::string boringLevel;
public:
	Book();
	Book(int id, std::string name,  std::string size, std::string author, std::string year, std::string boringLevel);
	//Book(const Book& item);
	int getId();
	std::string getSize();
	std::string getAuthor();
	std::string getYear();
	std::string getBoringLevel();
	std::string getName();
	void display() const;
};

