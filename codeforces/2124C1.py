def getx(a: int, b: int) -> int:
    d = b
    while d > 0:
        a, d = d, a % d
    return b // a


def solve(b: list[int], n: int):
    x = 1
    for i in range(n - 1):
        if b[i+1] % b[i] == 0:
            continue
        b[i] //= x
        if b[i+1] % b[i] == 0:
            continue
        x = x * getx(b[i+1], b[i])
    return x


def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        b = list(map(int, input().split()))
        print(solve(b, n))


if __name__ == "__main__":
    main()
