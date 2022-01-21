def calc_next(S):
    N = len(S)

    res = [ [N] * 26 for _ in range(N+1) ]

    for i in range(N-1, -1, -1):
        for j in range(26):
            res[i][j] = res[i+1][j]
        
        res[i][ord(S[i]) - ord('a')] = i

    return res

N, K = map(int, input().split())
S = input()

res = ""
nex = calc_next(S)
for i in range(N):
    print(nex[i])

j = -1
for i in range(K):
    for ordc in range(26):
        k = nex[j+1][ordc]
        print(k)
        if N - k >= K - i:
            print("--- true")
            res += chr(ord('a') + ordc)
            j = k
            break

print(res)
