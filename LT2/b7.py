a = 2
b = 1
c = int(input())
for i in range(2,c+1):
    c = a + b 
    a = b 
    b = c 
print(c)