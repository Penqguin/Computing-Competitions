n = int(input())

c = int(input())
d = {}

for i in range(c):
    distance = int(input())
    d[i+1] = int(distance)

min_hits = [float('inf')] * (n+1)
min_hits[0] = 0

for i in range(1, n+1):
     for club, distance in d.items():
        if i >= distance:
            min_hits[i] = min(min_hits[i], min_hits[i - distance] + 1)

if min_hits[n] == float('inf'):
    print('Roberta acknowledges defeat.')
else:
    print(f'Roberta wins in {min_hits[n]} strokes.')