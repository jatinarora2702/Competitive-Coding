def fact(n) :
	p = n; 
	# print("n=" + str(n))
	for i in range(1, n) :
		# print("i=" + str(i)) 
		p *= i
	if(n == 0) :
		return 1
	return p
def ncr(n, r) : 
	return fact(n) // fact(n-r) // fact(r)
n = int(input())
c = []
for i in range(n) :
	k = int(input()) 
	c.insert(len(c), k)
	# print("hi - " + str(c[i]))
p = 1
sum = 0
for i in range(n) :
	# print("i=" + str(i)) 
	sum += c[i]
	# print("sum=" + str(sum))
# print(sum);
for i in range(n, 0, -1) :
	# print("alala : " + str(ncr(sum-1, c[i-1]-1)))
	# print("sum=" + str(sum-1) + " c : " + str(c[i-1]-1))
	p = p * ncr(sum-1, c[i-1]-1)
	p %= 1000000007
	sum -= c[i-1]
print(int(p))