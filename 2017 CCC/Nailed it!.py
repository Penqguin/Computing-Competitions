arrlength = input("")
arrstring = input("")
arr = arrstring.split(" ")
lengths = [0] * 2001
fence = [0] * 4002

for i in arr:
  lengths[int(i)] += 1


for i in range(1,2001):
  for j in range(1,i+1):
    if i == j:
      if lengths[i] > 1:
        fence[int(i*2)] += int(lengths[int(i)]/2)

    else:
      fence[i+j] += min(lengths[i],lengths[j])

longest = 0
ways = 0
for i in range(1,4001):
  if fence[i] > longest:
    longest = fence[i]
    ways = 1
  elif fence[i] == longest:
    ways += 1
print(longest, ways)
