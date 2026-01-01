#include <iostream>
#include <map>
using namespace std;


int main() {
  map<string, int> M;
  char c;
  while (cin >> c) {
    if (c == 'N') {
      cout << "number: " << M.size() << endl;
    }
    else if (c == 'D') {
      string nif;
      int money;
      cin >> nif >> money;
      auto it = M.find(nif);
      if (it != M.end()) {
        (*it).second += money;
      }
      else M[nif] = money;
    }
    else if (c == 'Q') {
      string nif;
      cin >> nif;
      auto it = M.find(nif);
      if (it != M.end()) { //Existeix
        cout << (*it).second;
      }
      else cout << "-1";
      cout << endl;
    }
    else if (c == 'P') {
      auto it = M.begin();
      bool first = true;
      while (it != M.end()) {
        char digit_final = it->first[7];
        if ((digit_final - '0') % 2 == 0) {
            if (!first) cout << ' ';
            first = false;
            cout << (*it).first;
        }
        ++it;
      }
      cout << endl;
    }
    else { // c == 'L'
      if (M.size() < 1) cout << "NO LAST NIF";
      else {
        auto it = M.end();
        --it;
        cout << (*it).first << ' ' << (*it).second;
      }
      cout << endl;

    }
  }
}
