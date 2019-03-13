#include "State.h"



State::State(int index, STATE_TYPE type){
	this->index = index;
	this->type = type;
}

State::State(int index) {
	this->index = index;
	this->type = STATE_TYPE::NORMAL;
}

State::State() {
	this->index = -1;
	this->type = STATE_TYPE::NORMAL;
}


State::~State()
{
}
