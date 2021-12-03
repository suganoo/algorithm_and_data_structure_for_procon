N = int(input())

G = []
visited = [False * N]
for i in range(N):
    G.append([])

for i in range(N-1):
    a, b = list(map(int, input().split()))
    G[a-1].append(b-1)

def dfs(current):
    visited[current] = True
    max_d = 0
    for i in G[current]:
        if not visited[i]:
            d = dfs(i) + 1
            max_d = max(max_d, d)
    return max_d

print(dfs(0))