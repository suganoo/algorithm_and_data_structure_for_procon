#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, Q;
    string sample_str;
    bool flip_flag = false;

    cin >> N;
    cin >> sample_str;
    cin >> Q;
    for (int i = 0; i < Q; i++){
        int t, a, b;
        cin >> t >> a >> b;
        a--; b--;
        if (t==2) {
            flip_flag=!flip_flag;
        } else {
            if (!flip_flag) {
                char c = sample_str[a];
                sample_str[a] = sample_str[b];
                sample_str[b] = c;
            } else {
                int a_changed = (a + N) < 2 * N ? a+N : a-N;
                int b_changed = (b + N) < 2 * N ? b+N : b-N;
                char c = sample_str[a_changed];
                sample_str[a_changed] = sample_str[b_changed];
                sample_str[b_changed] = c;
            }
        }
    }
    if (!flip_flag) {
        cout << sample_str << endl;
    } else {
        for (int i = N; i < 2 * N; i++){
            cout << sample_str[i];
        }
        for (int i = 0; i < N; i++){
            cout << sample_str[i];
        }
        cout << endl;
    }
    return 0;
}