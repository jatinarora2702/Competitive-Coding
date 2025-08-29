def solve(a: int, b: int, c: int, d: int) -> bool:
    if b > 2 * (a + 1) or a > 2 * (b + 1):
        return False
    c -= a
    d -= b
    if c > 2 * (d + 1) or d > 2 * (c + 1):
        return False
    return True 


def main():
    t = int(input())
    for _ in range(t):
        a, b, c, d = map(int, input().split())
        print("YES" if solve(a, b, c, d) else "NO")


if __name__ == "__main__":
    main()
