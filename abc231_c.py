n,x = map(int, input().split())
a = list(map(int,input().split())) + [10**19]

dp = [[0,0] for _ in range(n + 1)]
print(dp)
for i in range(n):
    print("a[" + str(i+1) + "] = " + str(a[i+1]))
    print("a[" + str(i) + "] = " + str(a[i]))
    just = x % a[i+1] // a[i]
    print("just = " + str(just))

    change = a[i+1] // a[i] - just
    print("change = " + str(change))

    dp[i+1][0] = min(dp[i][0],dp[i][1]+1) + just
    dp[i+1][1] = min(dp[i][0],max(dp[i][1]-1,0))+change
    print(dp)

print(dp[-1][0])