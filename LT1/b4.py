import bisect
import sys

def min_colors_needed(a):
    res = []
    for i in a:
        pos = bisect.bisect_right(res, -i)
        if pos == len(res):
            res.append(-i)
        else:
            res[pos] = -i
    return len(res)

input = sys.stdin.read
data = input().split()
n = int(data[0])
A = list(map(int, data[1:]))

print(min_colors_needed(A))
