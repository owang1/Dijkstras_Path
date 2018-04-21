#!/usr/bin/env python3

import os
import time
import subprocess
import random

# Variables
N_vals = ["10", "20", "50", "100", "200", "500", "1000"]

# Heading
print("| {:15}| {:15}| {:15}|".format("N", "Elapsed Time", "Memory Usage"))
print("|{:-<16}|{:-<16}|{:-<16}|".format("-", "-", "-"))

# Running
FAILED = False

for N in N_vals:

	# Make Input
	num_costs = "6"
	costs_dict = {"f":"3", "g":"1", "G":"2", "h":"4", "m":"7", "r":"5"}
	costs = ""
	keys = ""
	for key, value in costs_dict.items():
		costs = costs + key + " " + value + "\n"

	for row in range(0, int(N)):
		for col in range(0, int(N)):
			key = random.choice(list(costs_dict.keys()))
			keys = keys + " " + key
		keys = keys + "\n"

	input_string = num_costs + "\n" + costs + N + " " + N + "\n" + keys + "0 0\n" + N + " " + N + "\n"
	
	# Run Command
	command = "./measure ./dijkstras"
	p = subprocess.Popen(command, shell=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, stdin=subprocess.PIPE)
		
	# Output
	stream, err  = p.communicate(input=input_string.encode())
	stream = stream.decode().split()
	print("|{:-<16}|{:-<16}|{:-<16}|".format(N, stream[-4], stream[-2]))
	p.kill()
