def gcd(x: int, y: int) -> int:
    if x < y:
        x, y = y, x
    
    while y > 0:
        x, y = y, x % y

    return x

def lcm(x: int, y: int) -> int:
    return (x * y) // gcd(x, y)


def solve(n: int, p: list[int], s: list[int]) -> bool:
    a = [lcm(xp, xs) for xp, xs in zip(p, s)]

    if a[0] != p[0] or a[n-1] != s[n-1] or p[n-1] != s[0]:
        return False

    for i in range(1, n):
        if gcd(p[i-1], a[i]) != p[i]:
            return False
    
    for i in range(n-2, -1, -1):
        if gcd(s[i+1], a[i]) != s[i]:
            return False

    return True


def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        p = list(map(int, input().split()))
        s = list(map(int, input().split()))
        print("YES" if solve(n, p, s) else "NO")


if __name__ == "__main__":
    main()
