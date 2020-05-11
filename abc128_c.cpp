#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,M;
  vector<vector<int>> s;
  vector<int> p;

  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int K;
    cin >> K;
    vector<int> s1;
    for (int j = 0; j < K; j++) {
      int a;
      cin >> a;
      s1.push_back(a);
    }
    s.push_back(s1);
  }

  for (int i = 0; i < M; i++) {
    int b;
    cin >> b;
    p.push_back(b);
  }

  int num = 11;
  bitset<10> bs(num);
  cout << bs << endl;
  cout << bs[0] << endl;
  cout << bs[1] << endl;
  cout << bs[2] << endl;
  cout << bs[N-1] << endl;
  cout << bs[N-2] << endl;
  for (int bit = 0; bit < ( 1 << N ); bit++) {
    cout << "--- " << bit << endl;
    bitset<10> bs(bit);
    for (int n = 0; n < ( 1 << N ); n++) {
      cout << bs[n] ;
      if (bs[n]){
        cout << " on";
      }
      cout << endl;
    }
  }
}
