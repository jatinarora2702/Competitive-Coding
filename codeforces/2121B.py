def solve(s: str, n: int) -> bool:
    if len(s) < 3:
        return False
    if len(s) > 28:
        return True
    x = [0] * 26
    x[ord(s[0]) - ord("a")] = 1
    x[ord(s[-1]) - ord("a")] = 1
    for ch in s[1:-1]:
        v = ord(ch) - ord("a")
        if x[v] > 0:
            return True
        x[v] += 1
    return False


def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        s = input()
        print("Yes" if solve(s, n) else "No")


if __name__ == "__main__":
    main()
