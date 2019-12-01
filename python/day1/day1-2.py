def calcfuel(line, total):
	fuel = line // 3 - 2
	
	if(fuel <= 0):
		return total

	total += fuel
	return calcfuel(fuel, total)

total = 0
f = open('input.txt', 'r')
for line in f:
	total = calcfuel(int(line), total)
print(total)
