t = int(input())
list = []

for i in range(t):
    a, b = input().split()
    a = int(a)
    b = int(b)
    list.append(a+b)

for i in range(len(list)):
    print('Case #%d: %d' %(i+1,list[i]))