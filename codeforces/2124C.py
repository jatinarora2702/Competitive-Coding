def getx(a: int, b: int, p: list[int]) -> int:
    x = 1
    for prime in p:
        while a % prime == 0 and b % prime == 0:
            a //= prime
            b //= prime
        while b % prime == 0:
            b //= prime
            x *= prime
        if b == 1:
            break
    return x


def solve(b: list[int], n: int, p: list[int]):
    x = 1
    for i in range(n - 1):
        if b[i+1] % b[i] == 0:
            continue
        b[i] //= x
        if b[i+1] % b[i] == 0:
            continue
        x = x * getx(b[i+1], b[i], p)
    return x


def primes() -> list[int]:
    p = [2]
    arr = [True] * 1_00_000
    for x in range(3, len(arr), 2):
        if not arr[x]:
            continue
        p.append(x)
        while x < len(arr):
            arr[x] = False
            x += x
    return p


def main():
    p = primes()
    t = int(input())
    for _ in range(t):
        n = int(input())
        b = list(map(int, input().split()))
        print(solve(b, n, p))


if __name__ == "__main__":
    main()
