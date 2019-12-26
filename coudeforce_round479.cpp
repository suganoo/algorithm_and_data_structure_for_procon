#include<bits/stdc++.h>
using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) {a = b; return 1;} else return 0; }

int N;
vector<long long> a;

void solve(){
  vector<long long> vs;
  map<long long, vector<int>> pl;
  for (int i = 0; i < a.size(); i++){
    vs.push_back(a[i]);
    pl[a[i]].push_back(i);
  }
  sort(vs.begin(), vs.end());
  cout << "vs[i]: " ;
  for (int i = 0; i < vs.size(); i++) {
    cout << vs[i] << " ";
  }
  cout << endl;
  cout << "pl: " << endl;
  for (auto x = pl.begin(); x != pl.end(); x++){
    cout << x->first << endl;
    cout << "second: " ;
    for (int i = 0; i < x->second.size(); i++){
      cout<< x->second[i] << " ";
    }
    cout << endl;
  }
  unique(vs.begin(), vs.end());
  cout << "vs[i]: " ;
  for (int i = 0; i < vs.size(); i++) {
    cout << vs[i] << " ";
  }
  cout << endl;
  vs.erase(unique(vs.begin(), vs.end()), vs.end());
  cout << "vs[i]: " ;
  for (int i = 0; i < vs.size(); i++) {
    cout << vs[i] << " ";
  }
  cout << endl;

  // DP
  int s = vs.size();
  vector<long long> dp(s+1, 0);
  for (int i = 0; i < N; i++) {
    cout << "---- i :" << i << endl;
    int it = lower_bound(vs.begin(), vs.end(), a[i]) - vs.begin();
    cout << "it: " << it << endl;
    cout << "a[i]: " << a[i] << endl;
    cout << "vs[it-1]: " << vs[it-1] << endl;
    cout << "dp[it] : " << dp[it] << " --> " ;
    if (it == 0 || a[i] != vs[it - 1] + 1) dp[it] = 1;
    else chmax(dp[it], dp[it-1] + 1 );
    cout << dp[it] << endl;
  }
  for (int i = 0; i < s; i++) {
    cout << dp[i] << " ";
  }
  cout << endl;
}

int main(){
  cin >> N;
  a.resize(N);
  for (int i = 0; i < N; i++){
    cin >> a[i];
  }
  solve();
}
