def solve(a, n):
    ans = n
    for i in range(n-1):
        minm, maxm = a[i], a[i]
        for j in range(i+1, n):
            if i > 0 and a[i-1] >= minm - 1 and a[i-1] <= maxm + 1:
                ans = min(ans, j - i - 1)
                break
            if a[j] >= minm - 1 and a[j] <= maxm + 1:
                ans = min(ans, j - i - 1)
                break
            minm = min(minm, a[j])
            maxm = max(maxm, a[j])
        if i > 0 and a[i-1] >= minm - 1 and a[i-1] <= maxm + 1:
            ans = min(ans, n - i - 1)
    
    return -1 if ans == n else ans


def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        a = list(map(int, input().split()))
        print(solve(a, n))


if __name__ == "__main__":
    main()
