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