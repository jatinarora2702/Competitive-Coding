def solve(inpS: list[int], inpT: list[int], n: int, k: int) -> bool:
    s = [0 for _ in range(n)]
    t = [0 for _ in range(n)]
    
    for i in range(n):
        x = inpS[i] % k
        y = inpT[i] % k
        s[i] = min(x, k - x)
        t[i] = min(y, k - y)
    
    s.sort()
    t.sort()
    
    for x, y in zip(s, t):
        if x != y:
            return False
    return True


def main():
    t = int(input())
    for _ in range(t):
        n, k = map(int, input().split())
        inpS = list(map(int, input().split()))
        inpT = list(map(int, input().split()))
        print("YES" if solve(inpS, inpT, n, k) else "NO")


if __name__ == "__main__":
    main()
