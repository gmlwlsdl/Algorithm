hour, minute = input().split()
cooking = input()
hour = int(hour)
minute = int(minute)
cooking = int(cooking)

minute += cooking

while minute >= 60:
    hour += 1
    if hour >= 24:
        if hour == 24:
            hour = 0
        else:
            hour -= 24
    minute -= 60

print(hour, minute)
