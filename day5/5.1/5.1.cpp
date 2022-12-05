#include <iostream>
#include <algorithm> 
#include <fstream>
#include <string>
using namespace std;
int main() {
	fstream file;
	string line, rows[9], moves, to, from, result;
	int linecounter = 0, allmovescounter = 0;
	file.open("input.txt", ios::in);
	while (getline(file, line)) {
		if (linecounter < 9) {
			int counter = 0;
			for (int i = 1; i < line.length(); i += 4) {
				if (line[i] == ' ') {
					counter++;
					continue;
				}
				else {
					rows[counter] += line[i];
					counter++;
				}
			}
			linecounter++;
		}
		if (linecounter == 10) {
			for (int i = 0; i < 9; i++) {
				reverse(rows[i].begin(), rows[i].end());
				cout << rows[i] << endl;
			}
		}
		if (linecounter == 9 || linecounter == 10) {
			linecounter++;
			continue;
		}
		if (linecounter > 10) {
			cout << endl;
			moves = line[5];
			if (line[6] != ' ') {
				moves += line[6];
				from = line[13];
			}
			else {
				from = line[12];
			}
			to = line[line.length() - 1];
			cout << moves << ":" << from << ":" << to << endl;
			for (int i = stoi(moves); i > 0; i--) {
				int rowlength = rows[stoi(from) - 1].length();
				rows[stoi(to) - 1] += rows[stoi(from) - 1][rowlength-1];
				rows[stoi(from) - 1].replace(rowlength-1, rowlength-1, "");
			}
			cout << endl;
			for (int i = 0; i < 9; i++) {
				cout << rows[i] << endl;
			}
		}
	}
	for (int i = 0; i < 9; i++) {
		int rowlength = rows[i].length() - 1;
		result += rows[i][rowlength];
	}
	cout << result;
}
