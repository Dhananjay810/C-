n=int(input())
m=int(input())
for i in range(n+1,10000):
    b=0
    for j in range(2,i):
        if(i%j!=0):
            b+=1
        else:
            break
    if(b==i-2):
       # print(i)
        if(i==m):
            print("YES")
            break
        else:
            print("NO")
            break
        
    else:
        continue        