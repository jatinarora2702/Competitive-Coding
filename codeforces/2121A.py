def solve(s, x, n):
    minm, maxm = 101, 0
    for entry in x:
        if entry < minm:
            minm = entry
        if entry > maxm:
            maxm = entry
    if minm <= s <= maxm:
        return maxm - minm + min(s - minm, maxm - s)
    if s < minm:
        return maxm - s
    return s - minm


def main():
    t = int(input())
    for _ in range(t):
        n, s = map(int, input().split())
        x = list(map(int, input().split()))
        print(solve(s, x, n))


if __name__ == "__main__":
    main()
