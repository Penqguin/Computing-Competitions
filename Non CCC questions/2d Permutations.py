n, m, q = map(int, input().split())
NM = 5000 * 5000 + 5
arr = [0] * NM
queries = [int(input()) for _ in range(q)]

for i in range(1, n + 1):
  for j in range(1, m + 1):
    mn = i * j
    mx = n*m - (n - i + 1)*(m - j + 1) + 1
    arr[mn] += 1
    arr[mx + 1] -= 1

for i in range(1, NM):
  arr[i] += arr[i - 1]

for query in queries:
  print(arr[query])
