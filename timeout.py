#!/usr/bin/env python3

import os
import time
import subprocess

# Variables
books = {
		"alice.txt" : "174K",
		"peter.txt" : "291K",
		"beowulf.txt" : "301k"
}

backends = [ "unsorted", "sorted", "bst", "rbtree", "treap", "unordered",
			"chained", "open"]

# Heading
print("| {:21}| {:22}| {:10}| {:14}| {:10}|".format("Backend", "Text", "File Size", "Elapsed Time", "Memory"))
print("|{:-<22}|{:-<23}|{:-<11}|{:-<15}|{:-<11}|".format("-", "-", "-", "-","-"))

# Running
max_run_time = 600
FAILED = False

for key, value in books.items():
	book = key
	filesize = value
	for backend in backends:
		#Define Time
		start = time.time()
		end = start + max_run_time
		interval = max_run_time / 1000.0

		#Run Command
		command = "measure ./frequencies -b " + backend + " < " + book
		p = subprocess.Popen(command, shell=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)

		#Check if still waiting
#		while True:
#			result = p.poll()
#			print(result)
#			if result is not None:
#				break
#			if time.time() >= end:
#				p.kill()
#				print("| {:12}| {:22}| {:10}| {:14}|".format(backend.upper(), book, filesize, "INFINITY"))
#				FAILED = True
#				break
#			time.sleep(interval)
			
#		if not FAILED:
		stream, err  = p.communicate()
		stream = stream.decode().split()
		print("| {:21}| {:22}| {:10}| {:14}| {:10}|".format(backend.upper(), book, filesize, stream[-4], stream[-2]))
		p.kill()

#		FAILED = False