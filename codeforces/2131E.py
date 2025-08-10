def solve(a: list[int], b: list[int], n: int) -> bool:
    if a[n-1] != b[n-1]:
        return False
    for i in range(n-2, -1, -1):
        if b[i] == a[i]:
            continue
        if b[i] == a[i] ^ a[i+1]:
            continue
        if b[i] == a[i] ^ b[i+1]:
            continue
        return False
    return True


def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        a = list(map(int, input().split()))
        b = list(map(int, input().split()))
        print("YES" if solve(a, b, n) else "NO")


if __name__ == "__main__":
    main()
