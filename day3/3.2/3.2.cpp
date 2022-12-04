#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int prioriticounting(int letter) {
	if (letter >= 97 && letter <= 122) {
		letter -= 96;
	}
	else {
		letter -= 38;
	}
	return letter;
}
int main()
{
	fstream file;
	file.open("input.txt", ios::in);
	string line, fline, sline, tline;
	char sameletter{};
	int priorities = 0, prioritiescount = 0, asciletter = 0, counter = 1;
	bool letterfound = 0;
	while (getline(file, line)) {
		letterfound = 0;
		if (counter == 1) fline = line;
		if (counter == 2) sline = line; 
		if (counter == 3) {
			tline = line;
			for (int i = 0; i < fline.length(); i++) {
				for (int j = 0; j < sline.length(); j++) {
					for (int k = 0; k < tline.length(); k++) { 
						if ((fline[i] == sline[j]) && (sline[j] == tline[k])) {
							sameletter = fline[i];
							letterfound = 1;
							counter = 0;
							prioritiescount += prioriticounting(int(sameletter));
							break;
						}
					}
					if (letterfound) break;
				}
				if (letterfound) break;
			}
		}
		counter++;
	}
	cout << prioritiescount;
	file.close();
}
