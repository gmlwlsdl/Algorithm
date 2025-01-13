t = int(input())
list = []

for i in range(t):
    a, b = input().split()
    a = int(a)
    b = int(b)
    case = []
    case.extend([i, a,b,a+b])
    list.append(case)

for x, y, z, r in list:
    print('Case #%d: %d + %d = %d' %(x+1, y, z, r))
