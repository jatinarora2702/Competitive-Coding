def solve(s: list[int], n: int) -> int:
    tot = 0
    cnt0 = 0
    for x in s:
        tot += x
        if x == 0:
            cnt0 += 1
    return sum(s) + cnt0


def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        s = list(map(int, input().split()))
        print(solve(s, n))


if __name__ == "__main__":
    main()
