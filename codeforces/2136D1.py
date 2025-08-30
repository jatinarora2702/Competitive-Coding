def solve(a: list[list[int]], n: int) -> None:
    maxm = 1_000_000_000
    
    s = -1
    for d in ["D", "D", "L", "L"]:
        print(f"? {d} {maxm}", flush=True)
        s = int(input())
        if s == -1:
            sys.exit(0)
    
    c1 = 4 * maxm + min(x + y for x, y in a) - s

    s = -1
    for d in ["R", "R", "R", "R"]:
        print(f"? {d} {maxm}", flush=True)
        s = int(input())
        if s == -1:
            sys.exit(0)
    
    c2 = 4 * maxm + min(y - x for x, y in a) - s

    x = (c1 - c2) // 2
    y = (c1 + c2) // 2

    print(f"! {x} {y}", flush=True)
    

def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        a = [list(map(int, input().split())) for _ in range(n)]
        solve(a, n)


if __name__ == "__main__":
    main()
