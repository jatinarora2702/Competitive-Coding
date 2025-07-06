def solve(a: list[int], n: int) -> int:
    return min(a[0] + a[0], a[0] + a[1])


def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        a = list(map(int, input().split()))
        print(solve(a, n))


if __name__ == "__main__":
    main()
