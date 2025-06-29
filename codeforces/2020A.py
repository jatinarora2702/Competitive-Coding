def solve(l1: int, b1: int, l2: int, b2: int, l3: int, b3: int) -> bool:
    if l1 == l2 and l2 == l3 and b1 + b2 + b3 == l1:
        return True
    if b1 == b2 and b2 == b3 and l1 + l2 + l3 == b1:
        return True
    if b1 + b2 == l1 and l1 == l2 + l3 and b2 == b3:
        return True
    if l1 + l2 == b1 and b1 == b2 + b3 and l2 == l3:
        return True
    return False


def main():
    t = int(input())
    for _ in range(t):
        l1, b1, l2, b2, l3, b3 = map(int, input().split())
        print("YES" if solve(l1, b1, l2, b2, l3, b3) else "NO")


if __name__ == "__main__":
    main()
