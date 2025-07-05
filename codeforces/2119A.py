def solve(a: int, b: int, x: int, y: int):
    if b == a:
        return 0
    if b < a:
        if b == (a - 1) and a % 2 == 1:
            return y
        return -1
    if y < x:
        k = (b - a + 1) // 2
        if a % 2 == 0:
            return k * y + (b - a - k) * x
        return k * x + (b - a - k) * y
    return (b - a) * x


def main():
    t = int(input())
    for _ in range(t):
        a, b, x, y = map(int, input().split())
        print(solve(a, b, x, y))


if __name__ == "__main__":
    main()
