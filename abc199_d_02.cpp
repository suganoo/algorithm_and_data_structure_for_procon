#include <bits/stdc++.h>
using namespace std;
using P=pair<int,int>;
using ll=long long;

int n,m;
vector<vector<int>> G(25,vector<int>());

vector<int> used(25);
vector<int> path(0);
vector<int> col(25,-1);

void dfs(int u){
    if(used[u]) return;
    used[u]=1;
    path.push_back(u);
    for(int v:G[u]) dfs(v); 
}

ll cnt;
void dfs2(int i){
    if(i==path.size()){
        cnt++;
        return;
    }

    int u=path[i];
    for(int c=0;c<3;c++){
        col[u]=c;

        bool flag=1;
        for(int v:G[u]){
            if(col[v]==c) flag=0;
        }
        if(flag) dfs2(i+1);
    }

    col[u]=-1;    
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        a--,b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    ll ans=1;
    for(int i=0;i<n;i++){
        path=vector<int>();
        dfs(i);
        if(path.size()==0) continue;

        ans*=3;
        cnt=0;
        col[path[0]]=0;
        dfs2(1);
        ans*=cnt;        
    }

    cout<<ans<<endl;
}   