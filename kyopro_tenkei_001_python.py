N,L = list(map(int, input().split()))
K = int(input())

A = []
A = list(map(int, input().split()))

left = 0
right = L

def solve(M):
    cnt = 0
    pre = 0
    for i in range(N):
        if (A[i] - pre) >= M and (L - A[i]) >= M:
            cnt += 1
            pre = A[i]
    if (cnt >= K):
        return True
    else:
        return False

while ( (right - left) > 1 ):
    mid = int(left + (right - left) / 2)
    if (solve(mid)):
        left = mid
    else:
        right = mid
        

print(left)
