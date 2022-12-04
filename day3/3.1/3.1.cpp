#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
	fstream file;
	file.open("input.txt", ios::in);
	string line;
	char sameletter{};
	int linelength = 0, priorities = 0, prioritiescount = 0, asciletter = 0;
	bool letterfound = 0;
	while (getline(file, line)) {
		linelength = line.length();
		letterfound = 0;
		for (int i = 0; i < linelength / 2; i++) {
			for (int j = linelength / 2; j < linelength; j++) {
				if (line[i] == line[j]) {
					sameletter = line[i];
					letterfound = 1;
					break;
				}
				
			}
			if (letterfound) break;
		}
		asciletter = int(sameletter);
		if (asciletter >= 97 && asciletter <= 122) {
			asciletter -= 96;
		}
		else {
			asciletter -= 38;
		}
		
		prioritiescount += asciletter;
	}
	cout << prioritiescount;
	file.close();
}
