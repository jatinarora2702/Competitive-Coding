def solve(a: list[tuple[int, int]], n: int, k: int) -> int:
    a.sort()
    curr = k
    for l, real in a:
        if l > curr:
            break
        if curr >= -real:
            continue
        curr = -real
    return curr


def main():
    t = int(input())
    for _ in range(t):
        n, k = map(int, input().split())
        a = []
        for _ in range(n):
            l, r, real = map(int, input().split())
            a.append((l, -real))
        print(solve(a, n, k))


if __name__ == "__main__":
    main()
