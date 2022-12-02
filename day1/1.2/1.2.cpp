#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    fstream file;
    string line;
    int tempcount = 0, tempvalue = 0, first = 0, second = 0, third = 0, all = 0;
    file.open("input.txt", ios::in);
    while (getline(file, line)) {
        if (line != "") {
            tempvalue = stoi(line);
            tempcount += tempvalue;
        }
        else {
            if (tempcount > third) {
                first = second;
                second = third;
                third = tempcount;
            }
            all = first + second + third;
            tempcount = 0;
        }

    }
    cout << all;



    file.close();
}