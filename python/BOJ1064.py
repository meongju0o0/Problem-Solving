import sys
import math

if __name__ == '__main__':
    x1, y1, x2, y2, x3, y3 = map(int, sys.stdin.readline().split())


    distances = [.0 for _ in range(3)]
    distances[0] = math.sqrt((x1 - x2) ** 2 + (y1 - y2) ** 2)
    distances[1] = math.sqrt((x1 - x3) ** 2 + (y1 - y3) ** 2)
    distances[2] = math.sqrt((x2 - x3) ** 2 + (y2 - y3) ** 2)


    slopes = [.0 for _ in range(3)]
    if abs(x1 - x2) != 0:
        slopes[0] = abs(y1 - y2) / abs(x1 - x2)
    else:
        slopes[0] = float("inf")

    if abs(x1 - x3) != 0:
        slopes[1] = abs(y1 - y3) / abs(x1 - x3)
    else:
        slopes[1] = float("inf")

    if abs(x2 - x3) != 0:
        slopes[2] = abs(y2 - y3) / abs(x2 - x3)
    else:
        slopes[2] = float("inf")
    
    
    if slopes[0] == slopes[1] == slopes[2]:
        print(-1.0)
    else:
        distances.sort()
        print(2*(distances[2] - distances[0]))