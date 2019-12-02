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

original_state = program #to reset state

for noun in range(100):
	for verb in range(100):
		program = original_state[:]
		program[1] = noun
		program[2] = verb
		#interpret instruction set
		for i in range(0, len(program), 4):
			if program[i] == 99:
				break
			program[program[i+3]] = compute(program[i], program[program[i+1]], program[program[i+2]])
		#check results
		if program[0] == 19690720:
			print(noun, verb, 100 * noun + verb)
			exit()
		#reset state
		program = original_state[:]