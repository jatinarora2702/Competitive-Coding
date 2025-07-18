def solve(h: list[int], n: int, k: int) -> bool:
    d = h[k - 1]
    h.sort()
    for i in range(n):
        if h[i] <= d:
            continue
        if h[i] - h[i-1] > d:
            return False
    return True


def main():
    t = int(input())
    for _ in range(t):
        n, k = map(int, input().split())
        h = list(map(int, input().split()))
        print("YES" if solve(h, n, k) else "NO")


if __name__ == "__main__":
    main()
