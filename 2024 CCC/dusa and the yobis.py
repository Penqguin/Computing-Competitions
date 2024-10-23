d = int(input())
y = int(input())
while d > y:
    d += y
    y = int(input())
    if y > d:
        break
print(d)