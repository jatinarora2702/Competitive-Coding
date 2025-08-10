def solve(g: list[list[int]], n: int) -> int:
    leaf = [0 for _ in range(n)]
    leaves = 0

    for i in range(n):
        if len(g[i]) == 1:
            leaves += 1
            leaf[i] = 1
        
        for j in g[i]:
            if len(g[j]) == 1:
                leaf[i] += 1

    minm = n
    for i in range(n):
        minm = min(minm, leaves - leaf[i])
    return minm


def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        g = [[] for _ in range(n)]
        for _ in range(n-1):
            u, v = map(int, input().split())
            g[u - 1].append(v - 1)
            g[v - 1].append(u - 1)
        print(solve(g, n))


if __name__ == "__main__":
    main()
