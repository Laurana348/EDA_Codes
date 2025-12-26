#include <iostream>
#include <vector>
using namespace std;

bool adequat(char a, char b) {
    return (a == 'A' && b == 'T' || a == 'T' && b == 'A' ||
            a == 'G' && b == 'C' || a == 'C' && b == 'G');
}

char complement(char a) {
    if (a == 'T') return 'A';
    else if (a == 'A') return 'T';
    else if (a == 'G') return 'C';
    else return 'G';
}

void adn(int indx, vector<char>& word1, vector<char>& word2, const vector<char> caracter) {
    int n = word1.size();

    if (indx == n) {
        for (int i = 0; i < n; ++i) {
            cout << word1[i];
        }
        cout << endl;

        for (int i = 0; i < n; ++i) {
            cout << word2[i];
        }
        cout << endl;
        cout << endl;
        return;
    }

    else {
        if (word1[indx] != '.' && word2[indx] != '.') {
            if (adequat(word1[indx], word2[indx])) {
                adn(indx+1, word1, word2, caracter);
            }

            else return;
        }

        else if (word1[indx] != '.' && word2[indx] == '.') {
            word2[indx] = complement(word1[indx]);
            adn(indx+1, word1, word2, caracter);
            word2[indx] = '.';
        }

        else if (word1[indx] == '.' && word2[indx] != '.') {
            word1[indx] = complement(word2[indx]);
            adn(indx+1, word1, word2, caracter);
            word1[indx] = '.';
        }

        else {

            for (int i = 0; i < 4; ++i) {
                word1[indx] = caracter[i];
                word2[indx] = complement(word1[indx]);
                adn(indx+1, word1, word2, caracter);
                word1[indx] = word2[indx] = '.';
            }
        }
    }
}

int main() {
    int n;
    while (cin >> n) {
        vector<char> word1(n);
        for (int i = 0; i < n; ++i) {
            char letter;
            cin >> letter;
            word1[i] = letter;
        }

        vector<char> word2(n);
        for (int i = 0; i < n; ++i) {
            char letter;
            cin >> letter;
            word2[i] = letter;
        }
        
        vector<char> caracter = {'A', 'C', 'G', 'T'};

        adn(0, word1, word2, caracter);

        cout << "----------" << endl;
    }
}
