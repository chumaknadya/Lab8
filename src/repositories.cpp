#include <iostream>
#include "../include/repositories.h"
using namespace std;

Repository::Repository(int id,std::string name,std::string language,std::string description)
{
    this->_id = id;
    this->_name = name;
    this->_language = language;
	this->_description = description;

}
Repository::~Repository()
{
    std::cout << "Repository is destoyed!" << std::endl;
}
void Repository::set_id(int id) { this->_id = id; }
void Repository::set_name(std::string  name) { this->_name = name; }
void Repository::set_language(std::string  language) { this->_language = language; }
void Repository::set_description(std::string description) { this->_description = description; }


int Repository::id() { return this->_id;}
std::string  Repository::name() { return this->_name;}
std::string  Repository::language() { return this->_language;}
std::string  Repository::description() { return this->_description;}

void Repository::print()
{
    std::cout << id() << " | " << name() << " | " << language() <<
    " | " << description() << std::endl;
}