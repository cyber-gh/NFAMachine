#pragma once
#include <string>

enum class STATE_TYPE
{
	START, NORMAL, FINAL
};

class State{
	
public:
	int index;
	std::string unique_identifier;
	STATE_TYPE type;
	
	State(int, STATE_TYPE);
	State(int);
	State();
	~State();
	bool operator<(State other) {
		return index < other.index;
	}
};

