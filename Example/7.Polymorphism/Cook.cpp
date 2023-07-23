#include "Cook.h"

Cook::Cook() : Person()
{
	setTypeProfession("Кухар-технолог");
}

Cook::Cook(const string name, const double salary, const int category, const string typeProfession)
	: Person(name, salary, category)
{
	setTypeProfession(typeProfession);
}

void Cook::setTypeProfession(string typeProfession) 
{
	this->typeProfession = typeProfession;
}
string Cook::getTypeProfession() 
{
	return this->typeProfession;
}
