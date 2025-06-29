mod = int(1e9 + 7)


def expo(x: int, p: int, dp: dict[int, int]) -> int:
    if x in dp:
        return dp[x]
    x_curr = x
    ans = 1
    while p > 0:
        if p % 2 == 1:
            ans = (ans * x_curr) % mod
        x_curr = (x_curr * x_curr) % mod
        p //= 2
    dp[x] = ans
    return dp[x]


def solve(a: int, b: int, k: int, dp: dict[int, int]) -> tuple[int, int]:
    n = (k * (a-1) + 1) % mod
    m = (k * (b-1)) % mod
    for i in range(a):
        m = (m * (n - i + mod)) % mod
        m = (m * expo(i+1, mod-2, dp)) % mod
    m = (m + 1) % mod
    return n, m


def main():
    t = int(input())
    dp = {}
    for _ in range(t):
        a, b, k = map(int, input().split())
        n, m = solve(a, b, k, dp)
        print(f"{n} {m}")


if __name__ == "__main__":
    main()
