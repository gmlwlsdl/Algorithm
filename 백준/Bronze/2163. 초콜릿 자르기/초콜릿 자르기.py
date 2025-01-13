n, m=input().split()
n=int(n)
m=int(m)

if(n==1|m==1):
    print(0)
else:
    print((n-1) + n*(m-1))