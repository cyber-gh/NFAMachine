#include <iostream>
#include "Machine.h"


void lab2() {
	Machine mac = Machine("lab2.in");

	mac.convert();
}

void lab1() {
	Machine mac = Machine("lab1afn.in");

	cout << mac.checkWord("ababbaab");
	//cout << mac.isFinal(3);
}

int main(){
	lab1();
}

