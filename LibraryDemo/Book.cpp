#include "Header.h"
#include "Book.h"
#include "Assistant.h"

Book::Book() : id(0), size("-"), author("NO AUTHOR"), year("-"), boringLevel("-"), name("NO NAME")
{
}

Book::Book(int id, std::string name, std::string size, std::string author, std::string year, std::string boringLevel)
	: id(id), name(name), size(size), author(author), year(year), boringLevel(boringLevel)
{
}
/*
Book::Book(const Book& item)
{
	this->id = item.id;
	this->author = item.author;
	this->size = item.size;
	this->year = item.year;
	this->boringLevel = item.boringLevel;
}
*/
int Book::getId()
{
	return id;
}

std::string Book::getSize()
{
	return size;
}

std::string Book::getAuthor()
{
	return author;
}

std::string Book::getYear()
{
	return year;
}

std::string Book::getBoringLevel()
{
	return boringLevel;
}

std::string Book::getName()
{
	return name;
}

void Book::display() const
{
	std::cout << id << std::endl;
	std::cout << name << std::endl;
	std::cout << author << std::endl;
	std::cout << size << std::endl;
	std::cout << year << std::endl;
	std::cout << boringLevel << std::endl;
	std::cout << std::endl;
}
