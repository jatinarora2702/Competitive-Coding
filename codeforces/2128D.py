import bisect


def solve(p: list[int], n: int) -> int:
    dp = [0] * n
    dp[n-1] = 1
    lds = [(p[n-1], n-1)]
    for i in range(n-2, -1, -1):
        if p[i] > lds[-1][0]:
            lds.append((p[i], i))
            dp[i] = dp[i+1] + (n - i)
        else:
            k = bisect.bisect_right(lds, (p[i], -float("inf")))
            lds[k] = (p[i], i)
            dp[i] = dp[i+1] + 1
    return sum(dp)


def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        p = list(map(int, input().split()))
        print(solve(p, n))


if __name__ == "__main__":
    main()
