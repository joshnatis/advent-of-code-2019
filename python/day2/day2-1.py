def compute(opcode, in1, in2):
	if opcode == 1:
		return in1 + in2
	if opcode == 2:
		return in1 * in2
		
program = []
with open('input.txt', 'r') as f:
	line = f.readline()
	program = line.split(',')
	program[-1] = program[-1].strip() #remove \n
	program = [int(x) for x in program] #conver to ints

#restore state to 1202 program alarm
program[1] = 12
program[2] = 2

for i in range(0, len(program), 4):
	if program[i] == 99:
		break
	program[program[i+3]] = compute(program[i], program[program[i+1]], program[program[i+2]])

print(program[0])