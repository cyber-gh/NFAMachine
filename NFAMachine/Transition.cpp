#include "Transition.h"



Transition::Transition(State from, State to, char letter){
	this->from = from;
	this->to = to;
	this->letter = letter;
}


Transition::~Transition()
{
}
