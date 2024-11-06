def is_alternating(s):
    count = {}
    for char in s:
        if char in count:
            count[char] += 1
        else:
            count[char] = 1

    heavy = set()
    for char, freq in count.items():
        if freq > 1:
            heavy.add(char)

    is_heavy_first = s[0] in heavy
    for i in range(len(s)):
        if is_heavy_first and (i % 2 == 0 and s[i] not in heavy or i % 2 == 1 and s[i] in heavy):
            return "F"
        elif not is_heavy_first and (i % 2 == 0 and s[i] in heavy or i % 2 == 1 and s[i] not in heavy):
            return "F"

    return "T"

T, N = map(int, input().split())
for _ in range(T):
    s = input()
    print(is_alternating(s))