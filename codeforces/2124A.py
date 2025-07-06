def solve(a: list[int], n: int) -> None:
    for i in range(1, n):
        if a[i] < a[i-1]:
            print("YES")
            print("2")
            print(f"{a[i-1]} {a[i]}")
            return
    print("NO")


def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        a = list(map(int, input().split()))
        solve(a, n)


if __name__ == "__main__":
    main()
