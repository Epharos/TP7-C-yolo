#include "List.h"
#include "Element.h"
#include "Personne.h"
#include <iostream>

List::List()
{
	this->start = NULL;
}

List::~List()
{
	delete this->start;
}

bool List::add(Element * e)
{
	if(start == NULL)
	{
		this->start = e;
		return true;
	}

	return this->add(e, this->start);
}

bool List::add(Personne * p)
{
	Element * e = new Element();
	e->setContent(p);

	if(start == NULL)
	{
		this->start = e;
		return true;
	}

	return this->add(e);
}

bool List::add(Element * e, Element * c)
{
	if(c->hasNext())
	{
		return this->add(e, c->getNext());
	}

	c->setNext(e);
	return true;
}

void List::print()
{
	this->print(this->start);
}

void List::print(Element * e)
{
	e->print();

	if(e->hasNext())
	{
		this->print(e->getNext());
	}
}

Personne * List::get(int index)
{
	return this->get(index, this->start, 0);
}

Personne * List::get(int index, Element * e, int count)
{
	if(e == NULL)
	{
		cerr << "Array out of bounds !" << endl;
		return NULL;
	}

	if(count == index)
	{
		return e->getContent();
	}

	return this->get(index, e->getNext(), count + 1);
}

Personne * List::search(string name)
{
	return this->search(name, this->start);
}

Personne * List::search(string name, Element * e)
{
	if(e == NULL)
	{
		cout << "Aucun résultat" << endl;
		return NULL;
	}

	if(e->getContent()->name == name)
	{
		return e->getContent();
	}

	return this->search(name, e->getNext());
}

// --------------

Element::Element()
{
	this->next = NULL;
	this->content = NULL;
}

Element::~Element()
{
	delete this->next;
	delete this->content;
}

bool Element::hasNext()
{
	return this->next != NULL;
}

Element * Element::getNext()
{
	return this->next;
}

void Element::setNext(Element * e)
{
	this->next = e;
}

Personne * Element::getContent()
{
	return this->content;
}

void Element::setContent(Personne * p)
{
	this->content = p;
}

void Element::print()
{
	this->content->print();
}