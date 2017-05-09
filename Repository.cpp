#include "Repository.h"
#include "Personne.h"
#include <iostream>
#include <fstream>

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

void Repository::save()
{
	Element * current = this->list->start;

	string s = "repos/" + this->name + ".txt";
	ofstream saving;
	saving.open(s.c_str());

	while(current != NULL)
	{
		saving << current->getContent()->nom << endl;
		saving << current->getContent()->prenom << endl;
		saving << current->getContent()->adresse << endl;
		saving << current->getContent()->zipCode << endl;
		saving << current->getContent()->phone << endl;
		current = current->getNext();
	}
}