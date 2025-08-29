import sys


def get_pts(a: list[list[int]], s1: int, s2: int) -> list[list[int]]:
    pts = []
    n = len(a)
    for i in range(n):
        x1, y1 = a[i]
        y1 += 1
        c1 = y1 - x1 + s1
        for j in range(n):
            x2, y2 = a[j]
            c2 = y2 - x2 + s2
            y = (c1 + c2) / 2

            x = (c1 - c2) / 2
            d1 = abs(x - x1) + abs(y - y1)
            d2 = abs(x - x2) + abs(y - y2)
            if d1 == s1 and d2 == s2:
                pts.append([x, y])

            x = (c2 - c1) / 2
            d1 = abs(x - x1) + abs(y - y1)
            d2 = abs(x - x2) + abs(y - y2)
            if d1 == s1 and d2 == s2:
                pts.append([x, y])
            
    return pts


def update_pts(pts: list[list[int]], a: list[list[int]], s: int) -> list[list[int]]:
    new_pts = []
    for x, y in pts:
        if min(abs(x - xa) + abs(y - ya) for xa, ya in a) == s
            new_pts.append([x, y])
    return new_pts


def solve(a: list[list[int]]) -> None:
    print("? U 0", flush=True)
    s1 = int(input())
    if s1 == -1:
        sys.exit(0)
    
    print("? U 1", flush=True)
    s2 = int(input())
    if s2 == -1:
        sys.exit(0)
    
    pts = get_pts(a, s1, s2)
    
    dirs = ["L", "D", "R", "U"]
    d, k = 0, 2
    q = 2
    while len(pts) != 1 and q < 10:
        print(f"? {dirs[d]} {k}", flush=True)
        s = int(input())
        if s == -1:
            sys.exit(0)

        # TODO: handle translation of pts as per d and k
        pts = update_pts(pts, a, s)

        d = (d + 1) % 4
        k += 1
        q += 1
    
    if q == 10:
        sys.exit(0)
    
    x, y = pts[0][0], pts[0][1]
    print(f"! {x} {y}")


def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        a = [list(map(int, input().split())) for _ in range(n)]
        solve(a)


if __name__ == "__main__":
    main()
