"""
Computes the distance between two documents.

d(i) = dictionary with words and their frequency.

angle = arccos(inner_product(d1, d2) / norm(d1)*norm(d2))
norm(d1) = inner_product(d1, d1)


similarity = (90 - angle in degress) * 100 / 90

"""
import sys
import os
import time
import math


def inner_prod(d1, d2):
	sum = 0;
	for word in d1.keys():
		if word in d2.keys():
			sum += d1[word] * d2[word]
	print(sum)
	return sum


def compute_similarity(d1, d2):
	dotprod = inner_prod(d1, d2);
	print("dont1")
	norm1 = math.sqrt(inner_prod(d1, d1))
	norm2 = math.sqrt(inner_prod(d2, d2))
	return math.acos(dotprod / (norm1 * norm2))

#########################################
# Returns word freq list from a list of lines
##########################################
def get_word_freq_list(lines):
	freqList = {}
	for line in lines:
		for word in line.split():
			if word[-1].isalnum() == False:
				word = word[:-1]
			word = word.lower()
			if word in freqList.keys():
				freqList[word] += 1
			else:
				freqList[word] = 1
	return freqList




#########################################
# Reads the document and returns document 
# freq list.
##########################################
def read_file(filename):
	try:
		f = open(filename, "r")
		return f.readlines()
	except IOError:
		print("Input error.")
		sys.exit()



def main():
	if len(sys.argv) != 3:
		print("Usage: docdist.py filename1 filename2")
	else:
		start = time.process_time()
		file1 = read_file(sys.argv[1])
		file2 = read_file(sys.argv[2])
		d1 = get_word_freq_list(file1)
		d2 = get_word_freq_list(file2)

		angle = compute_similarity(d1, d2)
		similarity = ((90 - (angle * 57.2958)) * 100 / 90)

		print("Number of words in file1: {0}".format(len(d1.keys())))
		print("Number of words in file2: {0}".format(len(d2.keys())))
		print("Similarity: {:6.3f}%".format(similarity))
		print("\nTime Taken: {0} seconds".format(time.process_time() - start))
		#decompose documents into word freq dict
		#dot products
		print("hello, world")


if __name__ == "__main__":
	main();


