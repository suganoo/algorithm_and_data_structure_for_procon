# abc235_c
N, Q = map(int, input().split())
A = list(map(int, input().split()))
X = []
K = []
for i in range(Q):
    x, k = map(int, input().split())
    X.append(x)
    K.append(k)

num_dict = {}

for i in range(N):
    if A[i] in num_dict:
        num_dict[A[i]].append(i+1)
    else:
        num_dict[A[i]] = []
        num_dict[A[i]].append(i+1)

for i in range(Q):
    if X[i] in num_dict:
        if K[i] <= len(num_dict[X[i]]):
            print(num_dict[X[i]][K[i]-1])
        else:
            print("-1")
    else:
        print("-1")