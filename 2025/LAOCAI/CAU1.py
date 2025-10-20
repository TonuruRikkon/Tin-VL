a, b=map(int,input().split())
ans =(pow(a,b,100)+pow(b,a,100))%100
if ans<10:
    print(f"0{ans}")
else:
    print(ans)