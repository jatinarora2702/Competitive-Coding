from collections import defaultdict
from collections import deque


def solve(a: list[int], n: int) -> int:
    dp = [0 for _ in range(n + 1)]
    mp = defaultdict(deque)
    for i, x in enumerate(a):
        dp[i+1] = dp[i]
        mp[x].append(i)
        if len(mp[x]) < x:
            continue
        if len(mp[x]) > x:
            mp[x].popleft()
        dp[i+1] = max(dp[i+1], dp[mp[x][0]] + x)
    return dp[-1]


def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        a = list(map(int, input().split()))
        print(solve(a, n))


if __name__ == "__main__":
    main()
