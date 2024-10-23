size = int(input())
medals = sorted([int(input()) for _ in range(size)])
def find_3rd_largest(arr):
    max1 = max2 = max3 = float('-inf')
    for num in arr:
        if num > max1:
            max3 = max2
            max2 = max1
            max1 = num
        elif num > max2 and num < max1:
            max3 = max2
            max2 = num
        elif num > max3 and num < max2:
            max3 = num
    return max3
third = find_3rd_largest(medals)
bronze = []

for i in range(size):
    if medals[i] == third: 
        bronze.append(medals[i])
print(third, len(bronze))