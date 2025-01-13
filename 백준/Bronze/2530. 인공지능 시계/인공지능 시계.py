import math

hour, minute, sec = input().split()
cooking = input()
hour = int(hour)
minute = int(minute)
sec = int(sec)
cooking = int(cooking)

while 1:
    sec += cooking % 60
    if (math.floor(cooking / 60)) >= 60:
        hour += math.floor((cooking/60)/60)
        minute += math.floor((cooking/60)%60)
    elif (math.floor(cooking / 60)) < 60:
        minute += math.floor(cooking / 60)
    break

while sec >= 60:
    minute += 1
    sec -=60

while minute >= 60:
    hour += 1
    minute -=60

while hour >= 24:
    hour -=24

print(hour, minute, sec)
