from collections import deque

N = int(input())

G = []

for i in range(N):
    G.append([])

for i in range(N-1):
    a, b = list(map(int, input().split()))
    G[a-1].append(b-1)
    G[b-1].append(a-1)

def bfs(current):
    dist = []
    for i in range(N):
        dist.append(-1)

    Q = deque()
    Q.append(current)
    dist[current] = 0

    while len(Q) > 0:
        x = Q.popleft()
        for next in G[x]:
            if dist[next] < 0:
                dist[next] = (dist[x] + 1)
                Q.append(next)
    
    max_d = 0
    max_id = 0
    for i in range(N):
        if max_d < dist[i]:
            max_d = dist[i]
            max_id = i
    
    return max_id, max_d

x_id, max_dist = bfs(0)
y_id, max_dist = bfs(x_id)

print(max_dist+1)