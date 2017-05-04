#include "Personne.h"
#include <iostream>
#include <string>

using namespace std;

Personne::Personne()
{
	this->nom = "Noname";
	this->prenom = "Nosurname";
	this->adresse = "Noadresse";
	this->zipCode = 0;
	this->phone = "Nophone";
}

Personne::Personne(string n, string s, string a, int z, string p)
{
	this->nom = n;
	this->prenom = s;
	this->adresse = a;
	this->zipCode = z;
	this->phone = p;
}

Personne::~Personne()
{

}

void Personne::print()
{
	cout << "| " << this->nom << " " << this->prenom << endl;
	cout << "| " << this->adresse << " : " << this->zipCode << endl;
	cout << "| " << this->phone << endl;
	cout << "-------------" << endl;;
}

void Personne::setNom(string s)
{
	this->nom = s;
}

void Personne::setPrenom(string s)
{
	this->prenom = s;
}

void Personne::setAdresse(string s)
{
	this->adresse = s;
}

void Personne::setZip(int i)
{
	this->zipCode = i;
}

void Personne::setPhone(string s)
{
	this->phone = s;
}