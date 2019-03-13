#pragma once
#include "State.h"
class Transition
{
public:
	State from, to;
	char letter;

	Transition(State, State, char);
	~Transition();
};

