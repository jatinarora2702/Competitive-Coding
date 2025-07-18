def solve(a: list[int], n: int, k: int) -> int:
    if n < k:
        return 0
    cnt, start = 0, 0
    for i in range(n):
        if a[i] == 1:
            start = i + 1
            continue
        if i - start + 1 == k:
            cnt += 1
            start = i + 2
    return cnt


def main():
    t = int(input())
    for _ in range(t):
        n, k = map(int, input().split())
        a = list(map(int, input().split()))
        print(solve(a, n, k))


if __name__ == "__main__":
    main()
