#include <iostream>
#include <map>
using namespace std;


struct Info {
  string code;
  int price;
};

int main() {
  map<int, Info> M;
  char c;
  while (cin >> c) {
    if (c == 'n') {
      int mida = M.size();
      cout << "num: " << mida << endl;
    }
    else if (c == 'u') {
      string code;
      int length, price;
      cin >> code >> length >> price;
      Info aux {code, price}; 
      M[length] = aux;
    }
    else if (c == 'q') {
      int length;
      cin >> length;
      auto it = M.find(length);
      if (it != M.end()) { //Existeix el creuer
        cout << (*it).second.price;
      }
      else cout << "-1";
      cout << endl;
    }
    else if (c == 'p') {
      cout << string(10, '-') << endl;
      auto it = M.begin();
      while (it != M.end()) {
        cout  << (*it).second.code << ' ' << (*it).first << ' ' << (*it).second.price << endl;
        ++it;
      }
      cout << string(10, '*') << endl;
    }
    else { // c == 's'
      auto it = M.begin();
      if (M.size() < 2) {
        cout << "no" << endl;
      }
      else {
        auto it = M.begin();
        ++it;
        if (it != M.end()) {
            cout  << (*it).second.code << ' ' << (*it).first << ' ' << (*it).second.price << endl;
        }
      }
    }
  }
}
