def solve(a: list[int], n: int) -> bool:
    return len(set(a)) < n


def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        a = list(map(int, input().split()))
        print("YES" if solve(a, n) else "NO")


if __name__ == "__main__":
    main()
