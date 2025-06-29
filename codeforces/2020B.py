def solve(n: int, s: int) -> int:
    cnt = 0
    for _ in range(n):
        dx, dy, x, y = map(int, input().split())
        if dx == dy and x == y:
            cnt += 1
        if dx != dy and x + y == s:
            cnt += 1
    return cnt


def main():
    t = int(input())
    for _ in range(t):
        n, s = map(int, input().split())
        print(solve(n, s))


if __name__ == "__main__":
    main()
