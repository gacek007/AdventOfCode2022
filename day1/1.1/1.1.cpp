#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    fstream file;
    string line;
    int tempcount = 0, tempvalue = 0, max = 0;
    file.open("input.txt", ios::in);
    while (getline(file, line)) {
        if (line != "") {
            tempvalue = stoi(line);
            tempcount += tempvalue;
        }
        else {
            if (tempcount > max) {
                max = tempcount;
            }
            tempcount = 0;
        }

    }
    cout << max;



    file.close();
}