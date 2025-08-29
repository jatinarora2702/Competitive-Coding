def solve(s: str, n: int, k: int) -> None:
    tot = s[:k].count("1")
    if tot == k:
        print("NO")
        return
    
    for i in range(k, n):
        tot += int(s[i]) - int(s[i-k])
        if tot == k:
            print("NO")
            return
    
    print("YES")
    lo, hi = 1, n
    ans = ["0" for _ in range(n)]
    for i in range(n):
        if s[i] == "1":
            ans[i] = str(lo)
            lo += 1
        else:
            ans[i] = str(hi)
            hi -= 1
    print(" ".join(ans))


def main():
    t = int(input())
    for _ in range(t):
        n, k = map(int, input().split())
        s = input()
        solve(s, n, k)


if __name__ == "__main__":
    main()
