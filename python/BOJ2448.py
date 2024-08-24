import sys


def make_triangle(stars, n):
    for i in range(n):
        for j in range(n-i-1, n+i):
            stars[i][j] = '*'


def remove_triangle(stars, x_start_pos, x_end_pos, y_start_pos, y_end_pos, n, pos='up'):
    if(n == 3):
        if(pos == 'up'):
            stars[y_start_pos][x_start_pos+1]= ' '
        elif(pos == 'down'):
            stars[y_start_pos][x_start_pos]= ' '

    else:
        for cnt, i in enumerate(range(y_start_pos, y_end_pos)):
            for j in range(x_start_pos+cnt, x_end_pos-cnt):
                stars[i][j] = ' '

        remove_triangle(stars, x_start_pos + n//4, x_end_pos - n//4, y_start_pos - n//2 + n//4, y_end_pos-1, n//2, 'up')
        remove_triangle(stars, x_start_pos - n//4, x_start_pos + n//4-1, y_start_pos + n//4, y_end_pos, n//2, 'down')
        remove_triangle(stars, x_end_pos - n//4+1, x_end_pos + n//4, y_start_pos + n//4, y_end_pos, n//2, 'down')


if __name__ == '__main__':
    n = int(sys.stdin.readline().rstrip())
    stars = [[' ' for _ in range(n*2-1)] for _ in range(n)]
    make_triangle(stars, n)
    remove_triangle(stars, n//2, n+n//2-1, n//2, n, n)
    for star_row in stars:
        for star in star_row:
            sys.stdout.write(star)
        sys.stdout.write('\n')