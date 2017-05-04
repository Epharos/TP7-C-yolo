#ifndef List_h
#define List_h

#include "Element.h"
#include "Personne.h"

class List
{
	public :
		Element * start;

		List();
		~List();
		bool add(Element *);
		bool add(Personne *);
		void print();

	private :
		bool add(Element *, Element *);
		void print(Element *);
};

#endif