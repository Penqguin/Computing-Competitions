from collections import Counter

correct = str(input())
incorrect = str(input())

pressed = Counter(correct)
displayed = Counter(incorrect)

silly_key = ''
quiet_key = '-'
wrong_letter = ''

# Find wrong
for key in displayed:
    if key not in pressed:
        wrong_letter = key
        break

# Find silly and quiet
for key in pressed:
    if key not in displayed:
        silly_key = key
        break

if len(correct) == len(incorrect):
    quiet_key = '-'
else:
    for key in pressed:
        if key != silly_key and key not in displayed:
            quiet_key = key
            break

# For the other subtasks, we need to work a bit harder to determine whether
# x corresponds to silly and y corresponds to quiet, or the other way around.
if len(correct) != len(incorrect):
    temp_pressed = correct.replace(silly_key, wrong_letter)
    temp_pressed = temp_pressed.replace(quiet_key, '')
    if temp_pressed == incorrect:
        # silly_key corresponds to silly and quiet_key corresponds to quiet
        pass
    else:
        # swap silly_key and quiet_key
        silly_key, quiet_key = quiet_key, silly_key

print(silly_key, wrong_letter)
print(quiet_key)