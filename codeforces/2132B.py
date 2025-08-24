def solve(n: int) -> None:
    f = 10
    ans = []
    while f < n:
        if n % (f + 1) == 0:
            ans.append(str(n // (f + 1)))
        f *= 10
    
    if len(ans) == 0:
        print("0")
    else:
        print(len(ans))
        print(" ".join(ans[::-1]))


def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        solve(n)


if __name__ == "__main__":
    main()
