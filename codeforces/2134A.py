def solve(n: int, a: int, b: int) -> bool:
    if n % 2 == 0:
        if b % 2 == 1:
            return False
        if a % 2 == 0:
            return True
        return b > a
    else:
        if b % 2 == 0:
            return False
        if a % 2 == 1:
            return True
        return b > a


def main():
    t = int(input())
    for _ in range(t):
        n, a, b = map(int, input().split())
        print("YES" if solve(n, a, b) else "NO")


if __name__ == "__main__":
    main()
