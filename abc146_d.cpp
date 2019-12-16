#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<vector<int> > G(N);
  vector<pair<int,int> > vp;
  for (int i = 1; i < N; i++) {
    int a,b;
    cin >> a >> b;
    a--;b--;
    //G[a].emplace_back(b);
    G[a].push_back(b);
    //G[b].emplace_back(a);
    G[b].push_back(a);
    //vp.emplace_back(a,b);
    vp.push_back(make_pair(a,b));
  }

  int K = 0;
  map<pair<int,int>,int> I;
  vector<int> cs(N, 0);

  vector<int> used(N, 0);
  queue<int> que;
  used[0] = 1;
  que.push(0);

  while(!que.empty()){
    int v = que.front();que.pop();
    if ( K < (int)G[v].size() ) K = G[v].size();
    int cur = 1;
    for (int i = 0; i < G[v].size(); i++) {
      int u = G[v][i];
      if (used[u]) continue;
      if (cur == cs[v]) cur++;
      cs[u] = I[make_pair(u,v)] = I[make_pair(v, u)] = cur++;
      used[u] = 1;
      que.push(u);
    }
  }
  cout << K << endl;
  for (int i = 0; i < vp.size(); i++ ) cout << I[vp[i]] << endl;
  return 0;
}
