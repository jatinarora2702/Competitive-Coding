def solve(s: str, n: int, k: int) -> bool:
    d = n // 2 - k
    if d < 0:
        return False
    cnt0 = s.count("0")
    cnt1 = n - cnt0
    cnt0, cnt1 = cnt0 - d, cnt1 - d
    if cnt0 < 0 or cnt1 < 0 or cnt0 % 2 == 1 or cnt1 % 2 == 1:
        return False
    return True


def main():
    t = int(input())
    for _ in range(t):
        n, k = map(int, input().split())
        s = input()
        print("YES" if solve(s, n, k) else "NO")


if __name__ == "__main__":
    main()
