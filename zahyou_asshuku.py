#zahyou_asshuku.py

A = [8, 100, 33, 33, 33, 12, 6, 1211]

B = sorted(set(A))

D = { v:i for i,v in enumerate(B)}

print(list(map(lambda v: D[v], A)))