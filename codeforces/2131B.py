def solve(n: int) -> list[int]:
    ans = [0] * n
    for i in range(n):
        ans[i] = -1 if i % 2 == 0 else 3
    if n % 2 == 0:
        ans[-1] = 2
    return ans


def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        print(" ".join(map(str, solve(n))))


if __name__ == "__main__":
    main()
