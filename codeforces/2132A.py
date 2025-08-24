from collections import deque


def solve(a: list[int], n: int, b: list[int], c: list[int], m: int) -> str:
    dq = deque([a])
    for x, ch in zip(b, c):
        if ch == "V":
            dq.appendleft(x)
        else:
            dq.append(x)
    return "".join(dq)


def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        a = input()
        m = int(input())
        b = input()
        c = input()
        print(solve(a, n, b, c, m))


if __name__ == "__main__":
    main()
