def solve(s: str, n: int, k: int) -> bool:
    if n < (2 * k):
        return True     # Alice
    cnt = s.count("1")
    if cnt <= k:
        return True     # Alice
    return False        # Bob


def main():
    t = int(input())
    for _ in range(t):
        n, k = map(int, input().split())
        s = input()
        print("Alice" if solve(s, n, k) else "Bob")


if __name__ == "__main__":
    main()
