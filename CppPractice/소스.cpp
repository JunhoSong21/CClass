#include <iostream>

using namespace std;

namespace First {
	int value = 1;
}

namespace Second {
	int value = 2;
}

int main() {
	cout << First::value << endl;
	cout << Second::value << endl;
}