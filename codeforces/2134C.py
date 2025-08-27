def solve(a: list[int], n: int) -> int:
    cnt = 0
    for i in range(0, n, 2):
        if i+1 >= n:
            break
        evens = a[i+1]
        odds = a[i]
        if i+2 < n:
            odds += a[i+2]
        if evens >= odds:
            continue
        d = odds - evens
        cnt += d
        if i+2 < n:
            k = min(d, a[i+2])
            a[i+2] -= k
            d -= k
        a[i] -= d
    return cnt


def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        a = list(map(int, input().split()))
        print(solve(a, n))


if __name__ == "__main__":
    main()
