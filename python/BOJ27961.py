import math


if __name__ == '__main__':
    n = int(input())
    
    if n == 0:
        print(0)
    else:
        print(math.ceil(math.log2(n)) + 1)