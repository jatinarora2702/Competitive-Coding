import heapq


def main():
	n, m = [int(t) for t in input().split()]
	g = [[] for x in range(n)]
	for i in range(m):
		x, y, z = [int(t) for t in input().split()]
		g[x].append((y, z))
		g[y].append((x, z))
	s = int(input())
	dist = [float("inf") for x in range(n)]
	p = [-1 for x in range(n)]
	h = [(0, s, -1)]
	heapq.heapify(h)
	while len(h) > 0:
		d, t, pt = heapq.heappop(h)
		if dist[t] <= d:
			continue
		dist[t] = d
		p[t] = pt
		for x, w in g[t]:
			heapq.heappush(h, (d+w, x, t))
	print("dist:", list(dist))
	print("parent:", list(p))


if __name__ == "__main__":
	main()

'''
inp:

9 14
0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 5 4
2 8 2
3 4 9
2 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7
0

out:

dist: [0, 4, 12, 19, 21, 11, 9, 8, 14]
parent: [-1, 0, 1, 2, 5, 6, 7, 0, 2]

'''