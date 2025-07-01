def solve(a: list[int], n: int, j: int, k: int) -> bool:
    return k >= 2 or a[j-1] == max(a)


def main():
    t = int(input())
    for _ in range(t):
        n, j, k = map(int, input().split())
        a = list(map(int, input().split()))
        print("YES" if solve(a, n, j, k) else "NO")


if __name__ == "__main__":
    main()
