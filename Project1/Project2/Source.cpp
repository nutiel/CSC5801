#include <iostream>
#include <string.h>

using namespace std;

int main() {

	string path;
	char c;
	int k = 0;

	cout << "Enter the path to the location of the files:\n";
	cout << "./\t  -> defines the source folder\n./\"path\"/ -> defines a path within that folder\n> ";
	while (cin.peek() != '\n') {
		cin >> c;
		path += c;
		k++;
	}

	for (int i = 0; i < k; i ++) {
		cout << path[i];
	}

	int fnsh;
	cin >> fnsh;

	return 0;
}