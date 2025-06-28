def solve(a: list[int], b: list[int], n: int) -> None:
    ans = []
    for _ in range(n):
        for i in range(n-1):
            if a[i] > a[i+1]:
                ans.append(f"1 {i + 1}")
                a[i], a[i+1] = a[i+1], a[i]
    
    for _ in range(n):
        for i in range(n-1):
            if b[i] > b[i+1]:
                ans.append(f"2 {i + 1}")
                b[i], b[i+1] = b[i+1], b[i]

    for i in range(n):
        if a[i] > b[i]:
            ans.append(f"3 {i + 1}")
            a[i], b[i] = b[i], a[i]
    
    print(f"{len(ans)}")
    for x in ans:
        print(f"{x}")


def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        a = list(map(int, input().split()))
        b = list(map(int, input().split()))
        solve(a, b, n)


if __name__ == "__main__":
    main()
