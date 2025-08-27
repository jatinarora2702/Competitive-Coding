def solve(a: list[int], n: int, k: int) -> None:
    if k % 2 == 1:
        for i in range(n):
            if a[i] % 2 == 1:
                a[i] += k
    else:
        for i in range(n):
            r = a[i] % (k+1)
            a[i] += r * k
    print(" ".join(str(x) for x in a), flush=True)


def main():
    t = int(input())
    for _ in range(t):
        n, k = map(int, input().split())
        a = list(map(int, input().split()))
        solve(a, n, k)


if __name__ == "__main__":
    main()
