def solve(a: list[int], n: int, s: int) -> int:
    tot = 0
    cnts = [0, 0, 0]
    for x in a:
        tot += x
        cnts[x] += 1
    if s < tot or s == tot + 1:
        while cnts[0] > 0:
            print("0", end=" ")
            cnts[0] -= 1
        while cnts[2] > 0:
            print("2", end=" ")
            cnts[2] -= 1
        while cnts[1] > 0:
            print("1", end=" ")
            cnts[1] -= 1
        print()
    else:
        print("-1")


def main():
    t = int(input())
    for _ in range(t):
        n, s = map(int, input().split())
        a = list(map(int, input().split()))
        solve(a, n, s)


if __name__ == "__main__":
    main()
