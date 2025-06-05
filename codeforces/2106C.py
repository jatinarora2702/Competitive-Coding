def solve(a, b, k):
    x = -1
    ans = -1
    min_a, max_a = k+1, -1
    for ai, bi in zip(a, b):
        min_a = min(min_a, ai)
        max_a = max(max_a, ai)
        if bi == -1:
            continue
        if x < 0:
            x = ai + bi
            continue
        if ai + bi != x:
            ans = 0
            break
    if ans == -1:
        if x == -1:
            ans = k - max_a + min_a + 1
        elif x - min_a > k or x - max_a < 0:
            ans = 0
        else:
            ans = 1
    print(ans)


def main():
    t = int(input())
    for _ in range(t):
        _, k = map(int, input().split())
        a = map(int, input().split())
        b = map(int, input().split())
        solve(a, b, k)


if __name__ == "__main__":
    main()
