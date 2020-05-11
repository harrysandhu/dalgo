from heap import max_heapify, build_max_heap, heapsort
import numpy as np

"""
Creates a young tableau, 
rows and columns sorted.
"""
def createYoungTab(t):
	for r in t:
		build_max_heap(r)
		heapsort(r)

	nr = len(t[0]) #no of columns
	nc = len(t)

	a = []
	for j in range(nc):
		cs = []
		for i in range(nr):
			cs.append(t[i][j])
		heapsort(cs)


	a_n = np.array(a)
	print(a_n)
	print("=-")
			



def main():
	table = [[1,5,2],
			 [8,3,4],
		 	 [9,0,7]]

	createYoungTab(table)
	ar = np.array(table)
	print(ar)


if __name__ == "__main__":
	main()