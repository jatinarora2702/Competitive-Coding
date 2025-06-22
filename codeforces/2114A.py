def solve(n: int) -> str:
    for x in range(100):
        if x * x == n:
            return f"{x} 0"
        if x * x > n:
            return "-1"
    return "-1"


def main() -> None:
    t = int(input())
    for _ in range(t):
        print(solve(int(input())))


if __name__ == "__main__":
    main()
