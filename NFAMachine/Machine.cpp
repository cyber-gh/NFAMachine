#include "Machine.h"


Machine::Machine(std::string inputFile){
	
	readMachine(inputFile);
}

void Machine::readMachine(std::string inputFile) {
	std::ifstream fin(inputFile);
	int nr;
	fin >> nr; 
	
	nrStates = 0;
	for (int index; nr--;nrStates++) {
		fin >> index;
		states.push_back(index);
	}
	fin >> nr;
	nrAlphabet = 0;
	for (char c; nr--;nrAlphabet++) {
		fin >> c;
		alphabet.insert(c);
	}
	fin >> nr;
	beginState = nr;
	fin >> nr;
	for (int index; nr--;) {
		fin >> index;
		finalStates.push_back(index);
	}
	fin >> nr;
	nrTransitions = 0;
	char c;
	for (int from, to; nr--;nrTransitions++) {
		fin >> from >> to >> c;
		transitions[from].push_back(std::make_pair(to, c));
	}

	
	
}

set<int> Machine::lambdaClosure(int state) {
	set<int> rs;
	rs.insert(state);
	queue<int> Q;
	Q.push(state);
	while (!Q.empty()) {

		int curr = Q.front();
		Q.pop();
		for (auto it : transitions[curr]) {
			if (it.second == LAMBDA) {
				rs.insert(it.first);
				Q.push(it.first);
			}
		}
	}
	return rs;
}

set<int> Machine::lambdaClosure(set<int> states, char letter) {
	set<int> rs;
	for (auto it : states) {
		rs = getUnion(rs, lambdaClosure(it, letter));
	}
	return rs;
}

set<int> Machine::lambdaClosure(int state, char letter) {
	set<int> start = lambdaClosure(state);
	set<int> rs;
	for (auto it : start) {
		for (auto it2 : transitions[it]) {
			if (it2.second == letter) rs.insert(it2.first);
		}
	}

	set<int> closure;
	for (auto it : rs) {
		closure = getUnion(closure, lambdaClosure(it));
	}
	return closure;
}

void Machine::convert(){

	queue<set<int> > Q;
	set<int> tmp;
	tmp.insert(0);
	Q.push(tmp);
	while (!Q.empty()) {
		set<int> curr = Q.front();
		Q.pop();
		wasBefore[curr] = true;
		for (auto letter : alphabet) {
			set<int> nextSet = lambdaClosure(curr, letter);
			printSet(curr);
			cout << "  -->  ";
			printSet(nextSet);
			cout << " -- " << letter;
			cout << endl;
			
			if (!wasBefore[nextSet]) {
				Q.push(nextSet);
				wasBefore[nextSet] = true;
			}
		}
	}




}

void Machine::printSet(set<int> s) {
	for (auto it : s) std::cout << it << ",";

}

bool Machine::checkWord(std::string word)
{
	reverse(word.begin(), word.end());
	return dfs(beginState, word);
}

bool Machine::isFinal(int state)
{
	for (auto it : finalStates) if (state == it) return true;
	return false;
}

bool Machine::dfs(int a, string s) {
	struct local {
		int state;
		string str;
	};

	stack<local> st;
	st.push({ a, s });

	while (!st.empty()) {
		local curr = st.top();
		//cout << curr.state << " " << curr.str << endl;
		st.pop();
		if (isFinal(curr.state) && curr.str == "") return true;
		if (curr.str == "") continue;

		for (auto it : transitions[curr.state]) {
			if (it.second == curr.str.back()) {
				string copy = curr.str;
				copy.pop_back();
				st.push({ it.first, copy });
			}
		}
	}
	return false;
}

Machine::~Machine()
{
}
