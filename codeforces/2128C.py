def solve(b: list[int], n: int) -> bool:
    minm = float("inf")
    for x in b:
        if x <= 2:
            if x > minm:
                return False
        else:
            v = (x - 1) // 2
            if (x - v) > minm:
                return False
        minm = min(minm, x)
    return True


def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        b = list(map(int, input().split()))
        print("YES" if solve(b, n) else "NO")


if __name__ == "__main__":
    main()
