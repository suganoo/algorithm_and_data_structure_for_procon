import heapq

Q = []


#heapq.heappush(Q,(1,6))
heapq.heappush(Q,(1,2))
heapq.heappush(Q,(4,5))
heapq.heappush(Q,(2,6))
heapq.heappush(Q,(7,3))
heapq.heappush(Q,(3,2))
print(Q)

for i in range(5):
    x, y = heapq.heappop(Q)
    print(str(x) + " " + str(y))