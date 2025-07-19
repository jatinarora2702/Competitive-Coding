def solve(n: int, m: int) -> bool:
    if n == 1 or m == 1:
        return False
    if n == 2 and m == 2:
        return False
    return True


def main():
    t = int(input())
    for _ in range(t):
        n, m = map(int, input().split())
        print("YES" if solve(n, m) else "NO")


if __name__ == "__main__":
    main()
