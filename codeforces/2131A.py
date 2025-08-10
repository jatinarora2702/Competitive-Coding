def solve(a: list[int], b: list[int], n: int) -> int:
    tot = 0
    for ax, bx in zip(a, b):
        if ax > bx:
            tot += ax - bx
    return tot + 1


def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        a = list(map(int, input().split()))
        b = list(map(int, input().split()))
        print(solve(a, b, n))


if __name__ == "__main__":
    main()
