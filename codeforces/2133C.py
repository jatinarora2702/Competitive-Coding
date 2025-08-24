import sys
from collections import defaultdict


def solve(n: int) -> None:
    mp = defaultdict(list)
    
    s = " ".join(str(x) for x in range(1, n+1))
    for x in range(1, n+1):
        print(f"? {x} {n} {s}")
        sys.stdout.flush()
        l = int(input())
        if l == -1:
            sys.exit(0)
        mp[l].append(x)
    
    lens = sorted(list(mp.keys()), reverse=True)
    m = len(lens)
    
    s = mp[lens[0]][0]
    ans = [s]
    for i in range(1, m):
        if len(mp[lens[i]]) == 1:
            s = mp[lens[i]][0]
            ans.append(s)
            continue
        
        for x in mp[lens[i]]:
            print(f"? {s} 2 {s} {x}")
            sys.stdout.flush()
            r = int(input())
            if r == -1:
                sys.exit(0)
            if r == 2:
                ans.append(x)
                s = x
                break
    
    path = " ".join(str(x) for x in ans)
    print(f"! {len(ans)} {path}")
    sys.stdout.flush()


def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        solve(n)


if __name__ == "__main__":
    main()
