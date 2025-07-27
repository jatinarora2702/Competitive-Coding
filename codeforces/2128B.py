def solve(p: list[int], n: int) -> str:
    ans = []
    turn = 1
    lo, hi = 0, n-1
    while lo <= hi:
        if turn == 0:
            if p[lo] < p[hi]:
                lo += 1
                ans.append("L")
            else:
                hi -= 1
                ans.append("R")
        else:
            if p[lo] < p[hi]:
                hi -= 1
                ans.append("R")
            else:
                lo += 1
                ans.append("L")
        turn ^= 1
    return "".join(ans)


def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        p = list(map(int, input().split()))
        print(solve(p, n))


if __name__ == "__main__":
    main()
