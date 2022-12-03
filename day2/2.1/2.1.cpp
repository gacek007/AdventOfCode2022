#include <iostream>
#include <fstream>
#include <string>
using namespace std;
// a x kamien
// b y papier
// c z nozyce
int checking_round(char o, char m) {
    cout << o << ":" << m << endl;
    int tempscore = 0, winpoint = 0, choisepoint = 0;
    if (o == 'A' && m == 'X') { winpoint = 3; choisepoint = 1; }
    if (o == 'A' && m == 'Y') { winpoint = 6; choisepoint = 2; }
    if (o == 'A' && m == 'Z') { winpoint = 0; choisepoint = 3; }

    if (o == 'B' && m == 'X') { winpoint = 0; choisepoint = 1; }
    if (o == 'B' && m == 'Y') { winpoint = 3; choisepoint = 2; }
    if (o == 'B' && m == 'Z') { winpoint = 6; choisepoint = 3; }

    if (o == 'C' && m == 'X') { winpoint = 6; choisepoint = 1; }
    if (o == 'C' && m == 'Y') { winpoint = 0; choisepoint = 2; }
    if (o == 'C' && m == 'Z') { winpoint = 3; choisepoint = 3; }
    cout << winpoint << ":" << choisepoint << ":";
    tempscore = winpoint + choisepoint;
    cout << tempscore << endl;
    return tempscore;
}
int main()
{
    fstream file;
    string line;
    int score = 0;
    char my, opponent;
    file.open("input.txt", ios::in);
    while (getline(file, line)) {
        for (int i = 0; i < 3; i++) {
            opponent = line[0];
            my = line[2];
        }
        score += checking_round(opponent, my);
    }
    cout << score;
    file.close();
}
