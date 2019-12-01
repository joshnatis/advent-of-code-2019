total = 0
f = open('input.txt', 'r')
for line in f:
	total += int(line) // 3 - 2
print(total)