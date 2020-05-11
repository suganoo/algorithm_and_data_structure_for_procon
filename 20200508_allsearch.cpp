#include <bits/stdc++.h>
using namespace std;

int main(){
  int n = 10;

  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++) {
      if ( (i + j) == 13 ) {
        cout << i << " " << j << endl;
	return 0;
      }
    }
  }
  cout << -1 << " " << -1 << endl;
  return 1;
}
