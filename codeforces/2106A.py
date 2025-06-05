def solve(n, s):
    k = sum(int(ch) for ch in s)
    return n + (n-2) * k


def main():
    t = int(input())
    for _ in range(t):
        n, s = int(input()), input()
        print(solve(n, s))


if __name__ == "__main__":
    main()
