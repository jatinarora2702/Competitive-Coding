def solve(n: int) -> int:
    if n == 0:
        return 0
    
    minm = 10
    while n > 0:
        minm = min(minm, n % 10)
        n //= 10
    return minm


def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        print(solve(n))


if __name__ == "__main__":
    main()
