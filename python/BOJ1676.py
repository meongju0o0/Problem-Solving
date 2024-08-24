if __name__ == '__main__':
    n = int(input())

    factorial = 1
    for i in range(2, n+1):
        factorial *= i

    str_factorial = str(factorial)
    cnt = 0
    for idx in range(len(str_factorial)-1, 0, -1):
        if str_factorial[idx] == '0':
            cnt += 1
        elif cnt > 0:
            break

    print(cnt)
