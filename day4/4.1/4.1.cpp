#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
	fstream file;
	string line, as1, as2, as3, as4;
	int counter = 0, ai1, ai2, ai3, ai4, result = 0;
	file.open("input.txt", ios::in);
	while (getline(file, line)){
		for (int i = 0; i < line.length(); i++) {
			if (line[i] == '-' || line[i] == ',') {
				counter++;
				continue;
			}
			if (counter == 0) as1 += line[i];
			if (counter == 1) as2 += line[i];
			if (counter == 2) as3 += line[i];
			if (counter == 3) as4 += line[i];
		}
		ai1 = stoi(as1);
		ai2 = stoi(as2);
		ai3 = stoi(as3);
		ai4 = stoi(as4);
		as1 = "";
		as2 = "";
		as3 = "";
		as4 = ""; 
		counter = 0;
		if ((ai3 >= ai1 && ai4 <= ai2) || (ai1 >= ai3 && ai2 <= ai4)) result++;
	}
	cout << result;
}