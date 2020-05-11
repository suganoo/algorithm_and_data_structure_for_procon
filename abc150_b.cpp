#include <bits/stdc++.h>
using namespace std;

int main(){
  string str_abc = "ABC";

  int N = 0;
  string str = "";

  cin >> N;
  cin >> str;

  int cnt = 0;
  int pos_abc = 0;
  for (int i = 0; i < N; i++) {
    if ( str[i] == str_abc[0] ) {
      pos_abc = 1;
    } else if ( str[i] == str_abc[pos_abc] ) {
      pos_abc++;

      if ( 2 < pos_abc ){
        cnt++;
        pos_abc = 0;
      }
    } else {
      pos_abc = 0;
    }
  }

  cout << cnt << endl;
}
