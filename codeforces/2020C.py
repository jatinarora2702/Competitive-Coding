def solve(n: int, m: int) -> None:
    if m < n or m > (n * (n+1)) // 2:
        print("-1")
        return

    ans = []
    nodes = []
    while m > 0 and n > 0:
        while n > 0 and n + n-1 <= m:
            nodes.append(n)
            m -= n
            n -= 1
        while n > 0 and n + n-1 > m:
            ans.append(f"1 {n}")
            m -= 1
            n -= 1
    
    root = nodes[0]
    for i in range(1, len(nodes)):
        ans.append(f"{nodes[i-1]} {nodes[i]}")
    
    print(f"{root}")
    for entry in ans:
        print(entry)


def main():
    t = int(input())
    for _ in range(t):
        n, m = map(int, input().split())
        solve(n, m)


if __name__ == "__main__":
    main()
