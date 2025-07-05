def solve(n: int, l: int, r: int, k: int):
    if n % 2 == 1:
        return l
    if n == 2:
        return -1
    x = 2
    while x <= l:
        x *= 2
    if x > r:
        return -1
    if k < n - 1:
        return l
    return x


def main():
    t = int(input())
    for _ in range(t):
        n, l, r, k = map(int, input().split())
        print(solve(n, l, r, k))


if __name__ == "__main__":
    main()
