def compute(n: int) -> int:
    dgt = digits(n)
    k = len(dgt)
    pre = sum(dgt)
    tot = 0
    p = 1
    for i in range(k-1, -1, -1):
        n //= 10
        d = dgt[i]
        pre -= d
        tot += p * (n * 45 + (d * (d + 1)) // 2 + pre * (d + 1))
        p *= 10
        if i > 0:
            dgt[i-1] -= 1
            pre -= 1
    return tot


def digits(n: int) -> list[int]:
    ret = []
    while n > 0:
        ret.append(n % 10)
        n //= 10
    return ret[::-1]


def solve(k: int) -> int:
    k -= 1
    d = p = 1
    while k >= (d * p * 9):
        k -= d * p * 9
        d += 1
        p *= 10
    n = p + (k // d) - 1
    return compute(n) + sum(digits(n + 1)[: (k % d) + 1])


def main():
    t = int(input())
    for _ in range(t):
        k = int(input())
        print(solve(k))


if __name__ == "__main__":
    main()
