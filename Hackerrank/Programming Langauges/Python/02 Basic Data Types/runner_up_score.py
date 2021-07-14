import sys


def runner_up_score(arr):

    i = 0
    best = -9999999
    best2 = -9999999

    for i in range(len(arr)):
        if best < arr[i]:
            best = arr[i]

    for i in range(len(arr)):
        if best2 < arr[i] and arr[i] < best:
            best2 = arr[i]

    return best2


if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))

    print(runner_up_score(arr))
