# abc235_b
N = int(input())
H = list(map(int,input().split()))

MAX = H[0]
for i in range(N-1):
    if H[i] < H[i+1]:
        MAX = H[i+1]
    else:
        break
print(MAX)