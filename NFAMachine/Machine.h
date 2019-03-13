#pragma once
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <iostream>
#include <fstream>

#include "Transition.h"

using namespace std;

const char LAMBDA = '~';

class Machine{
	//TODO refractor, bad oop design
	std::vector<int> states;
	std::vector<int> finalStates;
	int beginState;
	std::set<char> alphabet;

	std::map<int , vector <pair<int, char> > > transitions;
	int nrTransitions;
	int nrStates;
	int nrAlphabet;
	std::map<set<int>, set<int> > AFDTransitions;

	std::vector<int> newStatesKey;
	std::map<int, set<int> > newStatesValue;
	std::map<set<int>, set<int> > transTable;
	std::map<set<int>, bool> wasBefore;

	

	void readMachine(std::string inputFile);
public:
	set<int> lambdaClosure(int state);
	set<int> lambdaClosure(int state, char letter);
	set<int> lambdaClosure(set<int> states, char letter);
	void convert();
	void printSet(set<int> s);
	bool checkWord(std::string word);
	bool isFinal(int state);
	bool dfs(int a, string s);

	Machine(std::string inputFile);
	~Machine();
};

template <typename T>
std::set<T> getUnion(const std::set<T>& a, const std::set<T>& b)
{
	std::set<T> result = a;
	result.insert(b.begin(), b.end());
	return result;
}

