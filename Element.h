#ifndef Element_h
#define Element_h

#include "Personne.h"

class Element
{
	Element * next;
	Personne * content;

	public :
		Element();
		~Element();
		bool hasNext();
		Element * getNext();
		void setNext(Element *);
		Personne * getContent();
		void setContent(Personne *);
		void print();
};

#endif