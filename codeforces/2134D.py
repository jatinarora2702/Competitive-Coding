from collections import deque


def solve(n: int, edges: list[list[int]]) -> None:
    if n < 3:
        print(-1)
        return

    g = [[] for _ in range(n)]
    for u, v in edges:
        g[u-1].append(v-1)
        g[v-1].append(u-1)
    
    def bfs(s: int) -> tuple[int, list[int]]:
        max_dist = -1
        end_pt = -1
        par = [-1 for _ in range(n)]
        q = deque([(s, -1, 0)])

        while q:
            si, pi, dist = q.popleft()
            par[si] = pi
            if dist > max_dist:
                max_dist = dist
                end_pt = si
            
            for sj in g[si]:
                if sj == pi:
                    continue
                q.append((sj, si, dist + 1))

        return end_pt, par

    end_pt, _ = bfs(s=0)

    end_pt, par = bfs(s=end_pt)

    dia = [end_pt]
    while par[end_pt] != -1:
        end_pt = par[end_pt]
        dia.append(end_pt)

    for i in range(1, len(dia)):
        a, b = dia[i-1], dia[i]
        if len(g[b]) <= 2:
            continue
        for c in g[b]:
            if c == a:
                continue
            if i+1 < len(dia) and c == dia[i+1]:
                continue
            print(f"{a+1} {b+1} {c+1}")
            return
    
    print(-1)


def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        edges = [list(map(int, input().split())) for _ in range(n-1)]
        solve(n, edges)


if __name__ == "__main__":
    main()
