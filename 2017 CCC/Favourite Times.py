d = int(input())
favTime = 0

def is_time_arithmetic_sequence(hours, minutes):
    hours_str = str(hours)
    minutes_str = str(minutes).zfill(2)
    digits = [int(d) for d in hours_str + minutes_str]
    if len(digits) < 3:
        return False
    diff = digits[1] - digits[0]
    for i in range(2, len(digits)):
        if digits[i] - digits[i-1] != diff:
            return False
    return True

if d <= 720:
    hours = 12
    minutes = 0
    for i in range(d):
        #check if is consecutive
        minutes += 1
        
        if minutes >= 60:
            minutes = 0
            hours += 1
        if hours > 12:
            hours = 1

        if is_time_arithmetic_sequence(hours, minutes):
            favTime +=1
            
            
        

elif d > 720:
    temp = d % 720
    hours = 12
    minutes = 0
    for i in range(temp):
        #check if is consecutive
        minutes += 1

        if minutes >= 60:
            minutes = 0
            hours += 1
        if hours > 12:
            hours = 1

        if is_time_arithmetic_sequence(hours, minutes):
            favTime +=1
            
    favTime += 31 * (d // 720)

print(favTime)