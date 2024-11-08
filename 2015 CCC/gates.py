import bisect

G = int(input())
P = int(input())
gates = [int(input()) for _ in range(P)]

free_gates = list(range(1, G+1))
planes = 0

for g in gates:
    idx = bisect.bisect_right(free_gates, g)
    if idx > 0:
        gate = free_gates.pop(idx-1)
        planes += 1
    else:
        break

print(planes)