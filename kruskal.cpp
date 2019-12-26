#include<bits/stdc++.h>
using namespace std;

struct edge {int u, v, cost;};

bool comp(const edge& e1, const edge& e2){
  return e1.cost < e2.cost;
}

edge es[10500];
int V, E;

int kruskal(){
  sort(es, es + E, comp);

}

int main(){

  cout << kruskal() << endl;
  return 0;
}
