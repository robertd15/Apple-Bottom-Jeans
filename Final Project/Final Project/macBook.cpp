//Charles Canasa

#include <iostream>
#include <string>
#include <fstream>

#include "macBook.h"

//Default Constructor
macBook::macBook()
{
	orderNum = "";
	name = "";
	releaseDate = "";
	price = 0;
	quantity = 0;
}

//Overloaded Constructor
macBook::macBook(std::string ord, std::string nam, std::string date, double pric, int quan)
{
	orderNum = ord;
	name = nam;
	releaseDate = date;
	price = pric;
	quantity = quan;

	std::cout << "Order Number: " << orderNum << "\nName: " << name << "\nRelease Date: " << releaseDate << "\nPrice: " << price << "\nQuantity: " << quantity << std::endl << std::endl;
}

macBook::~macBook()
{

}


//Setters
void macBook::setOrderNum(std::string ord)
{
	orderNum = ord;
}

void macBook::setName(std::string nam)
{
	name = nam;
}

void macBook::setReleaseDate(std::string date)
{
	releaseDate = date;
}

void macBook::setPrice(double pric)
{
	price = pric;
}

void macBook::setQuantity(int quan)
{
	quantity = quan;
}


//Getters
std::string macBook::getOrderNum() const
{
	return orderNum;
}

std::string macBook::getName() const
{
	return name;
}

std::string macBook::getReleaseDate() const
{
	return releaseDate;
}

double macBook::getPrice() const
{
	return price;
}

int macBook::getQuantity() const
{
	return quantity;
}


//Overloaded input/output operators feel free to change these
std::ostream &operator << (std::ostream &strm, const macBook &obj)
{
	strm << "Order Number: " << obj.orderNum << std::endl << "Name: " << obj.name << std::endl << "Release Date: " << obj.releaseDate << std::endl << "Price: " << obj.price << std::endl << "Quantity: " << obj.quantity << std::endl;

	return strm;
}

std::istream &operator >> (std::istream &strm, macBook &obj)
{
	std::cout << "Enter Order Number - ";
	getline(strm, obj.orderNum);

	std::cout << "Enter Name - ";
	getline(strm, obj.name);

	std::cout << "Enter Release Date - ";
	getline(strm, obj.releaseDate);

	std::cout << "Enter Price - ";
	strm >> obj.price;
	strm.ignore();

	std::cout << "Enter Quantity - ";
	strm >> obj.quantity;
	strm.ignore();

	return strm;
}