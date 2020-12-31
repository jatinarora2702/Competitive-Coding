class TrieNode:
	def __init__(self):
		self.cnt = 0
		self.child = dict()

	def insert(self, x):
		if x == "":
			self.cnt += 1
			return
		if x[0] not in self.child:
			self.child[x[0]] = TrieNode()
		self.child[x[0]].insert(x[1:])

	def search(self, x):
		if x == "":
			return self.cnt > 0
		return x[0] in self.child and self.child[x[0]].search(x[1:])

	def delete(self, x):
		if x == "":
			self.cnt -= 1
			return
		self.child[x[0]].delete(x[1:])


class Trie:
	def __init__(self):
		self.root = TrieNode()

	def insert(self, x):
		self.root.insert(x)

	def search(self, x):
		return self.root.search(x)

	def delete(self, x):
		self.root.delete(x)


def main():
	t = Trie()
	while True:
		c = input("1. insert, 2. delete, 3. search: ")
		if c == "1":
			t.insert(input("insert: "))
		elif c == "2":
			t.delete(input("delete: "))
		else:
			print(t.search(input("search: ")))


if __name__ == "__main__":
	main()
