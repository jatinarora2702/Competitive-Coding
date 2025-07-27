def solve(a: list[int], n: int, c: int) -> int:
    ans = 0
    a = sorted(a, reverse=True)
    p = 1
    for x in a:
        if x * p > c:
            ans += 1
            continue
        p *= 2
    return ans


def main():
    t = int(input())
    for _ in range(t):
        n, c = map(int, input().split())
        a = list(map(int, input().split()))
        print(solve(a, n, c))


if __name__ == "__main__":
    main()
