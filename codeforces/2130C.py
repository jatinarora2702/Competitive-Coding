def solve(p: list[tuple[int, int]], n: int) -> None:
    a = [(x, y, i) for i, (x, y) in enumerate(p, 1)]
    a = sorted(a, key=lambda tup: (tup[0], -tup[1], tup[2]))
    lo, hi, index = a[0]
    ans = [str(index)]
    for i in range(1, n):
        x, y, index = a[i]
        if y > hi:
            ans.append(str(index))
            hi = y
    print(len(ans))
    print(" ".join(ans)) 


def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        p = []
        for _ in range(n):
            a, b = map(int, input().split())
            p.append((a, b))
        solve(p, n)


if __name__ == "__main__":
    main()
