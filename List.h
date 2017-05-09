#ifndef List_h
#define List_h

#include "Element.h"
#include "Personne.h"
#include <iostream>
#include <string>

class List
{
	public :
		Element * start;

		List();
		~List();
		bool add(Element *);
		bool add(Personne *);
		void print();
		Personne * get(int);
		Personne * search(std::string);

	private :
		bool add(Element *, Element *);
		void print(Element *);
		Personne * get(int, Element *, int);
		Personne * search(std::string, Element *);
};

#endif