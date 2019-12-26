#include<bits/stdc++.h>
using namespace std;

int main(){
  int a[6] = {4, 7, 3, 9, 5, 1};
  priority_queue<int> que;
  for (int i = 0; i < sizeof(a); i++){
    //cout << a[i] << endl;
  }
  que.push(4);
  que.push(7);
  que.push(3);
  que.push(9);
  que.push(5);
  que.push(1);
  priority_queue<int, vector<int>, greater<int>> que2;
  que2.push(4);
  que2.push(7);
  que2.push(3);
  que2.push(9);
  que2.push(5);
  que2.push(1);
  while (!que.empty()){
    cout << que.top() << endl;
    que.pop();
  }
  while (!que2.empty()){
    cout << que2.top() << endl;
    que2.pop();
  }
  return 0;
}
