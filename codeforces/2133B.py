def solve(g: list[int], n: int) -> int:
    g.sort()
    ans = 0
    for i in range(n-1, -1, -2):
        ans += g[i]
    return ans


def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        g = list(map(int, input().split()))
        print(solve(g, n))


if __name__ == "__main__":
    main()
