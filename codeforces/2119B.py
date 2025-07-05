def solve(px: int, py: int, qx: int, qy: int, a: list[int], n: int) -> bool:
    maxm = tot = sum(a)
    minm = max(max(0, 2*x - tot) for x in a)
    d = (qy - py) ** 2 + (qx - px) ** 2
    return (minm * minm) <= d <= (maxm * maxm) 


def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        px, py, qx, qy = map(int, input().split())
        a = list(map(int, input().split()))
        print("Yes" if solve(px, py, qx, qy, a, n) else "No")


if __name__ == "__main__":
    main()
