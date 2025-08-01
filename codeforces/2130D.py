def query(ft: list[int], index: int) -> int:
    tot = 0
    while index > 0:
        tot += ft[index]
        index -= index & -index
    return tot


def update(ft: list[int], index: int, val: int) -> None:
    while index < len(ft):
        ft[index] += val
        index += index & -index


def solve(p: list[int], n: int) -> int:
    ft = [0] * (n+1)
    ans = 0
    for i, x in enumerate(p, 1):
        k = query(ft, x)
        lt = i - k - 1
        rt = n - x - lt
        ans += min(lt, rt)
        update(ft, x, 1)
    return ans


def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        p = list(map(int, input().split()))
        print(solve(p, n))


if __name__ == "__main__":
    main()
