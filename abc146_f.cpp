#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

template<class T>
inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

const ll INF = 1e9;
int N, M;
string S;

void solve() {
  cin >> N >> M >> S;
  vector<int> dist(N + 1, INF);
  vector<int> MostLeft(N + 1, INF);
  dist[N] = 0;
  MostLeft[0] = N;
  int Next = N - 1;
  int Left = N;
  int timer = 0;
  cout << "Next: " << Next << endl;
  cout << "Left: " << Left << endl;
  while(true) {
    timer++;
    int newLeft = Left;
    while(Next >= Left - M && Next >= 0) {
      cout << "Next: " << Next << endl;
      cout << "Left: " << Left << endl;
      if (S[Next] == '0') {
        cout << "S[Next]: " << S[Next] << endl;
        dist[Next] = timer;
        cout << "dist[Next]: " << dist[Next] << endl;
        newLeft = Next;
        cout << "newLeft: " << newLeft << endl;
      }
      Next--;
    }
    if (newLeft == Left) {
      cout << -1 << endl;
      return;
    }
    cout << "end" << endl;
    Left = newLeft;
    cout << "Left: " << Left << endl;
    MostLeft[timer] = Left;
    cout << "timer: " << timer << endl;
    cout << "MostLeft[timer]: " << MostLeft[timer] << endl;
    if (Next < 0) break;
  }
  timer = dist[0];
  for (int i = 0; i <= N; i++) {
    cerr << dist[i] << endl;
  }
  vector<int> ans;
  int now = 0;
  while (timer >= 1) {
    timer--;
    ans.push_back(MostLeft[timer] - now);
    now = MostLeft[timer];
  }
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i];
    if (i + 1 != ans.size()) cout << " ";
  }
  cout << endl;
  return;
}

int main(){
  solve();
  return 0;
}
