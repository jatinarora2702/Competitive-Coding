def solve(a: int, x: int, y: int) -> bool:
    if x > y:
        x, y = y, x
    if a < x or a > y:
        return True
    return False


def main():
    t = int(input())
    for _ in range(t):
        a, x, y = map(int, input().split())
        print("YES" if solve(a, x, y) else "NO") 


if __name__ == "__main__":
    main()
