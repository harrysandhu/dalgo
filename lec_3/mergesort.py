import sys
import numpy as np


def merge(a, s, mid, e):
	b1s = mid -s  + 1
	b2s = e - mid;
	b1 = []
	b2 = []
	for x in range(0,b1s):
		b1.append(a[x+s])

	for x in range(0,b2s):
		b2.append(a[x + mid+1])

	i = 0
	j = 0
	c = s
	while (i < b1s or j < b2s):
		if (i < b1s and j < b2s):
			if b1[i] <= b2[j]:
				a[c] = b1[i]
				c += 1
				i += 1
			elif b1[i] >= b2[j]:
				a[c] = b2[j]
				c += 1
				j += 1

		elif (i >= b1s and j < b2s):
			a[c] = b2[j]
			c += 1
			j += 1
			
		elif (j >= b2s and i < b1s):
			a[c] = b1[i]
			c += 1
			i += 1
			



def mergeSort(a, s, e):
	if s < e:
		mid = (s+e)/2
		mergeSort(a, s, mid)
		mergeSort(a, mid+1, e)
		merge(a, s, mid, e)



def read_file(filename):
	try:
		file = open(filename, 'r')
		d = []
		for line in file.readlines():
			d.append(int(line.split('\n')[0]))

		return d
	except IOError:
		print("Input error")
		sys.exit()



def main():
	if len(sys.argv) != 2:
		print("Usage: mergeSort.py filename.txt")
		sys.exit()

	data = read_file(sys.argv[1])
	print(data)
	ar = np.array(data)
	mergeSort(data, 0, len(data) -1)
	print(data)	
	ar = np.array(data)
	print(ar)


if __name__ == "__main__":
	main();