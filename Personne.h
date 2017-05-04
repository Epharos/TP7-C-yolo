#ifndef Personne_h
#define Personne_h

#include <iostream>
#include <string>

class Personne
{
	public :
		std::string nom;
		std::string prenom;
		std::string adresse;
		int zipCode;
		std::string phone;

		Personne();
		Personne(std::string, std::string, std::string, int, std::string);
		~Personne();
		void print();
		void setNom(std::string);
		void setPrenom(std::string);
		void setAdresse(std::string);
		void setZip(int);
		void setPhone(std::string);
};

#endif