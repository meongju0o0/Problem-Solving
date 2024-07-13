import numpy as np


def is_prime(num):
    if num < 2:
        return False
    nums = np.ones(num + 1, dtype=bool)
    nums[:2] = False

    for idx in range(2, int(np.sqrt(num)) + 1):
        if nums[idx]:
            nums[idx*2:num+1:idx] = False

    return nums[num]


if __name__ == '__main__':
    input_num = int(input('Enter number: '))
    if is_prime(input_num):
        print(f'{input_num} is prime number')
    else:
        print(f'{input_num} is composite number')
