#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> G(25, vector<int>());
vector<bool> used(25, false);
vector<int> color(25, -1);
vector<int> path(0,0);

int N, M;
long long cnt = 0;

void dfs(int n){
    if (used[n]) return;

    used[n] = true;
    path.push_back(n);
    for(auto x: G[n]){
        dfs(x);
    }
}

void dfs2(int u){
    if (u==path.size()) {
        cnt++;
        return;
    }
    int x = path[u];
    for (int i = 0; i < 3; i++){
        color[x] = i;
        bool ok = true;
        for (auto w: G[x]){
            if (i==color[w]) ok = false;
        }
        if (ok) dfs2(u+1);
    }
    color[x]=-1;
}

int main(){
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a,b;
        cin >> a >> b;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    long long ans = 1;
    for (int i = 0; i < N; i++){
        if (used[i])continue;
        path = vector<int>();
        dfs(i);

        ans*=3;
        cnt=0;
        color[path[0]] = 0;
        dfs2(1);
        ans*=cnt;
    }
    cout << ans << endl;
}