N = int(input())
a = []
b = []
p = []
for i in range(N):
  arr = input().split()
  a.append(int(arr[0]))
  b.append(int(arr[1]))
  p.append(int(arr[2]))

for i in range(N):
  if a[i] * b[i] != p[i]:
    print('16 BIT S/W ONLY')
  else:
    print('POSSIBLE DOUBLE SIGMA')
