#include <iostream>

using namespace std;

namespace First {
	int value = 1;
	float fvalue = 3.f;
}

namespace Second {
	int value = 2;
}

int main() {
	cout << First::value << endl;
	cout << First::fvalue << endl;
	cout << Second::value << endl;
}