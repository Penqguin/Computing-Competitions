def count(s):
    if not s:
        return ''

    l = []
    c = 1
    for i in range(1, len(s)):
        if s[i] == s[i - 1]:
            c += 1
        else:
            l.append(str(c) + ' ' + s[i - 1])
            c = 1
    l.append(str(c) + ' ' + s[-1])
    return ' '.join(l)

n = int(input())
for _ in range(n):
    s = input()
    print(count(s))