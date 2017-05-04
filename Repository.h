#ifndef Repository_h
#define Repository_h

#include "List.h"
#include "Personne.h"
#include <string>
#include <iostream>

class Repository
{
	public :
		List * list;
		std::string name;

		Repository();
		Repository(std::string);
		~Repository();

		bool add(Personne *);
		void print();
		void save(ofstream &);
};

#endif