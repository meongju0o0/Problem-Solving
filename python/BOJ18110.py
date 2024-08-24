import sys


def my_round(val):
    if val - int(val) >= 0.5:
        return int(val) + 1
    else:
        return int(val)


if __name__ == '__main__':
    n = int(sys.stdin.readline().strip())
    if n != 0:
        ranks = [0 for _ in range(n)]
        for i in range(n):
            ranks[i] = int(sys.stdin.readline().strip())

        ranks.sort()
        trunc_number = my_round(n * 0.15)
        print(my_round(sum(ranks[trunc_number:n - trunc_number]) / len(ranks[trunc_number:n - trunc_number])))
    else:
        print(0)
