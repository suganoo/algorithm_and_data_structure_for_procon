#bisect_sample.py
import bisect

A = [4, 8, 2, 2, 9, 1, 3, 3, 3]

print(sorted(A))
print(bisect.bisect_left(sorted(A),3))
print(bisect.bisect_right(sorted(A),3))