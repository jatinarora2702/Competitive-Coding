def solve(n, x):
    p = [str(i) for i in range(x)] + [str(n-i-1) for i in range(n-x)]
    print(" ".join(p))


def main():
    t = int(input())
    for _ in range(t):
        n, x = map(int, input().split())
        solve(n, x)


if __name__ == "__main__":
    main()
