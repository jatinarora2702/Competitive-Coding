from collections import defaultdict
import heapq


def bal(hl: list[int], hr: list[int], nl: int, nr: int, mp: dict[int, int]) -> tuple[int, int]:
    while len(hl) > 0 and -hl[0] in mp:
        x = -heapq.heappop(hl)
        mp[x] -= 1
        if mp[x] == 0:
            del mp[x]
    
    if len(hl) > 0 and len(hr) > 0 and hr[0] < hl[0]:
        nl += 1
        nr -= 1
        x = heapq.heappop(hr)
        heapq.heappush(hl, -x)

    while nl > nr:
        nl -= 1
        nr += 1
        x = -heapq.heappop(hl)
        heapq.heappush(hr, x)
    
    while nr >= nl + 2:
        nl += 1
        nr -= 1
        x = heapq.heappop(hr)
        heapq.heappush(hl, -x)

    return nl, nr


def solve(a: list[int], n: int, k: int) -> tuple[int, int, int]:
    mp = defaultdict(int)
    hl, hr = [], []
    nl, nr = 0, 0
    
    for i in range(k):
        heapq.heappush(hr, a[i])
        nr += 1
        nl, nr = bal(hl, hr, nl, nr, mp)
    
    start = 0
    maxm = hr[0]
    lo, hi = start, k-1
    
    for i in range(k, n):
        if a[start] <= hr[0]:
            mp[a[start]] += 1
            nl -= 1
            start += 1
        heapq.heappush(hr, a[i])
        nr += 1
        nl, nr = bal(hl, hr, nl, nr, mp)
        if hr[0] > maxm:
            maxm = hr[0]
            lo, hi = start, i

    while start < n-k:
        mp[a[start]] += 1
        nl -= 1         # maybe this part is incorrect, because we can be removing from the right heap too
        start += 1
        nl, nr = bal(hl, hr, nl, nr, mp)
        if hr[0] > maxm:
            maxm = hr[0]
            lo, hi = start, n-1
        
    return maxm, lo + 1, hi + 1


def main():
    t = int(input())
    for _ in range(t):
        n, k = map(int, input().split())
        a = list(map(int, input().split()))
        print(" ".join(map(str, solve(a, n, k))))


if __name__ == "__main__":
    main()
