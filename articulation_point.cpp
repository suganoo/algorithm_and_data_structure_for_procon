#include<bits/stdc++.h>
using namespace std;

#define MAX 100000

vector<int> G[MAX];
int N;
bool visited[MAX];
int prenum[MAX], parent[MAX], lowest[MAX], timer;

void dfs(int current, int prev){
  cout << "current = " << current << " prev = " << prev << endl;
  prenum[current] = lowest[current] = timer;
  timer++;

  visited[current] = true;

  int next;

  for (int i = 0; i < G[current].size(); i++) {
    next = G[current][i];
    cout << "next = " << next << endl;
    if (!visited[next]){
      cout << "not visited" << endl;
      parent[next] = current;
      dfs(next, current);
      cout << "lowest[" << current << "] = " << lowest[current] << " lowest[" << next << "] = " << lowest[next] << endl;
      lowest[current] = min(lowest[current], lowest[next]);
      cout << " ---> lowest[" << current << "] = " << lowest[current] << endl;
    } else if (next != prev) {
      cout << "visited" << endl;
      cout << "lowest[" << current << "] = " << lowest[current] << " prenum[" << next << "] = " << prenum[next] << endl;
      lowest[current] = min(lowest[current], prenum[next]);
      cout << " ---> lowest[" << current << "] = " << lowest[current] << endl;
    }
  }
}

void art_points(){
  for (int i = 0; i < N; i++) visited[i] = false;
  timer = 1 ;
  dfs(0,-1);

  set<int> ap;
  int np = 0;
  for (int i = 1; i < N; i++) {
    int p = parent[i];
    if (p == 0) np++;
    else if (prenum[p] <= lowest[i]) ap.insert(p);
  }
  if (np > 1) ap.insert(0);
  for (set<int>::iterator it = ap.begin(); it != ap.end(); it++) {
    cout << *it << endl;
  }
}

int main() {
  int m;
  cin >> N >> m;

  for (int i = 0; i < m; i++) {
    int s, t;
    cin >> s >> t;
    G[s].push_back(t);
    G[t].push_back(s);
  }
  art_points();
  return 0;
}
