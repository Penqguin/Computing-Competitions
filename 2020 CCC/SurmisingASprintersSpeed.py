import math

N = int(input())
data = []
ans = 0

for i in range(N):
  T, X = map(int, input().split())

  data.append([T, X])
  
data.sort(key=lambda x: x[0])
  
for i in range(len(data)):
  
  a = math.fabs(data[i][1] - data[i-1][1]) /  (data[i][0] - data[i-1][0])

  if a > 0 and a > ans:
    ans = a

print(ans)