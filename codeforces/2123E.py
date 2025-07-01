def solve(a: list[int], n: int) -> list[int]:
    freq = [0] * (n+1)
    cnts = [0] * (n+1)
    for x in a:
        freq[x] += 1
    i = 0
    while i <= n and freq[i] > 0:
        cnts[freq[i]] += 1
        i += 1
    surplus = n - i
    cnt_tup = []
    i = 0
    while i <= n:
        if cnts[i] > 0:
            cnt_tup.append((i, cnts[i]))
        i += 1
    ans = []
    i, k = 0, 0
    val = 1
    while i <= surplus:
        if k < len(cnt_tup) and i == cnt_tup[k][0]:
            val += cnt_tup[k][1]
            k += 1
        ans.append(val)
        i += 1
    while i <= n:
        ans.append(n - i + 1)
        i += 1
    return ans


def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        a = list(map(int, input().split()))
        ans = solve(a, n)
        for x in ans:
            print(x, end=" ")
        print()


if __name__ == "__main__":
    main()
