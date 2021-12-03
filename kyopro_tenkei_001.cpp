#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, L, K;
    cin >> N >> L;
    cin >> K;
    vector<int> A(0,N);
    for (int i = 0; i < N; i++){
        int a;
        cin >> a;
        A.push_back(a);
    }

    int score = -1;
    for (int bit_num = 0; bit_num < (1<<N);bit_num++){
        int length_min = 1<<20;
        bool flag = false;
        bitset<16> bitset_num(bit_num);
        string bitset_str = bitset_num.to_string();
        if (K == count(bitset_str.cbegin(),bitset_str.cend(), '1')){
            //cout << bitset_str << endl;
            int pre_length = 0;
            int cnt = 0;
            for (int i = 0; i < N; i++){
                //cout << bitset_str[i] << endl;
                if (bitset_num[i]==1){
                    //cout << "A[" << i << "]=" << A[i] << endl;
                    //cout << "length min 0 =" << length_min << endl;
                    //cout << "pre_length =" << pre_length << endl;
                    if (A[i]-pre_length < length_min) length_min = A[i]-pre_length;flag = true;

                    pre_length=A[i];
                    cnt++;
                    
                    //cout << "length min 1 =" << length_min << endl;
                    if (cnt == K) {
                        if (L-A[i] < length_min) length_min = L-A[i];flag = true;
                    }
                    //cout << "length min 2 =" << length_min << endl;
                }
            }
            //cout << "length min " << length_min << endl;
        }
        if (score < length_min && flag) score = length_min;
        //cout << "score = "<< score << endl;
    }
    cout << score << endl;
    return 0;
}