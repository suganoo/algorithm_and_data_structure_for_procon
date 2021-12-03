#include <bits/stdc++.h>
using namespace std;

vector<int> A;
vector<int> B;

bool isOK(int index, int key) {
    if (key <= A[index]) return true;
    else return false;
}

int main(){
    int N,Q;

    cin >> N;
    
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        A.push_back(a);
    }
    sort(A.begin(), A.end());
    cout << A.size() << endl;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        cin >> B[i];
    }

    for (int i = 0; i < Q; i++) {
        int num = B[i];
        int left = 0;
        int right = (int)A.size();

        int mid = 0;
        while (right - left > 1) {
            mid = left + (right - left) / 2;
            if (isOK(mid, num)) right = mid;
            else left = mid;
            cout << "right = " << right << endl;
        }
        cout << min(abs(A[right] - num), abs(A[right-1] - mid)) << endl;
    }
    
    return 0;
}