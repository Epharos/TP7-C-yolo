#include "Repository.h"
#include "Personne.h"
#include <iostream>

using namespace std;

Repository::Repository()
{
	this->list = new List();
	name = "";
}

Repository::Repository(string k)
{
	this->list = new List();
	name = k;
}

Repository::~Repository()
{
	delete this->list;
}

bool Repository::add(Personne * p)
{
	return this->list->add(p);
}

void Repository::print()
{
	return this->list->print();
}

void Repository::save(ofstream & stream)
{
	Element * current = this->list->start;

	while(current->hasNext())
	{
		stream << current->getContent->nom << endl;
		stream << current->getContent->prenom << endl;
		stream << current->getContent->adresse << endl;
		stream << current->getContent->zipCode << endl;
		stream << current->getContent->phone << endl;
	}
}