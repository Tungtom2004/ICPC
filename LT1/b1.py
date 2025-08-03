def count_valid_triangles(points):
    n = len(points)
    total = n * (n - 1) * (n - 2) // 6 
    colinear = 0

    for i in range(n):
        xi, yi = points[i]
        for j in range(i + 1, n):
            xj, yj = points[j]
            for k in range(j + 1, n):
                xk, yk = points[k]
                area = xi * (yj - yk) + xj * (yk - yi) + xk * (yi - yj)
                if area == 0:
                    colinear += 1

    return total - colinear

import sys
input = sys.stdin.readline

N = int(input())
points = [tuple(map(int, input().split())) for _ in range(N)]

print(count_valid_triangles(points))
