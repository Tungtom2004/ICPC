x,y = map(int, input().split())

if abs(x - y) <= 1:
    print('Bob')
else:
    print('Alice')