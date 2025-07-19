def solve(a: list[int], b: list[int], c: list[int], d: list[int], n: int) -> int:
    ans = 0
    for ai, bi, ci, di in zip(a, b, c, d):
        if di < bi:
            ans += bi - di
            ans += ai
        elif ci < ai:
            ans += ai - ci
    return ans


def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        a, b, c, d = [0] * n, [0] * n, [0] * n, [0] * n
        for i in range(n):
            a[i], b[i], c[i], d[i] = map(int, input().split())
        print(solve(a, b, c, d, n))


if __name__ == "__main__":
    main()
