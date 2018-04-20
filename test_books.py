#!/usr/bin/env python3

import os
import time
import subprocess

# Variables
N_vals = [10, 20, 50, 100, 200, 500, 1000]

# Heading
print("| {:15}| {:15}| {:15}|".format("N", "Elapsed Time", "Memory Usage"))
print("|{:-<16}|{:-<16}|{:-<16}|".format("-", "-", "-"))

# Running
FAILED = False

for N in N_vals:
	#Define Time
	start = time.time()
	end = start + max_run_time
	interval = max_run_time / 1000.0

	# Make Map

	#Run Command
	command = "measure ./frequencies -b " + "backend" + " < " + "book"
	p = subprocess.Popen(command, shell=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
		
#		if not FAILED:
	stream, err  = p.communicate()
	stream = stream.decode().split()
	print("|{:-<16}|{:-<16}|{:-<16}|".format(N, stream[-4], stream[-2]))
	p.kill()

#		FAILED = False