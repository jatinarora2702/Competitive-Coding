def solve(a: list[int], n: int) -> int:
    ans = 0
    for i in range(n-1, 1, -1):
        x = max(a[i], a[-1] - a[i])
        lo, hi = 0, i-1
        while lo < hi:
            while lo < hi and a[lo] + a[hi] <= x:
                lo += 1
            ans += hi - lo
            hi -= 1
    return ans


def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        a = list(map(int, input().split()))
        print(solve(a, n))


if __name__ == "__main__":
    main()
