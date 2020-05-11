import math

def left(i):
	return 2*(i) + 1

def right(i):
	return 2*i + 2

def parent(i):
	return i /2;


# def max_heapify(a, i):
# 	# print("heapifyiing::: ")
# 	# print(a)
# 	l = left(i)
# 	r = right(i)
# 	largest = i

# 	if l < len(a) and a[l] > a[largest]:
# 		largest = l;
# 	if r < len(a) and a[r] > a[largest]:
# 		largest = r;

# 	if largest != i:
# 		temp = a[largest]
# 		a[largest] = a[i]
# 		a[i] = temp
# 		max_heapify(a, largest)


def max_heapify(a, size, i):
	l = left(i)
	r = right(i)
	largest = i
	if l < size and a[l] > a[largest]:
		largest = l
	if r < size and a[r] > a[largest]:
		largest = r

	if largest != i:
		temp = a[largest]
		a[largest] = a[i]
		a[i] = temp
		max_heapify(a, size, largest)



def build_max_heap(a):
	for i in range(int(len(a)/2 -1), -1, -1):
		max_heapify(a, len(a), i)

def extract_max(a):
	max = a[0]
	a[0] = a[len(a)-1]
	a = a[0:len(a)-1]
	max_heapify(a, len(a), 0)
	return max

def heap_delete(a, i):
 	a[i] = a[len(a)-1]
 	a = a[0:len(a)-1]
 	print("a is")
 	print(a)
 	max_heapify(a, len(a),i)
 	print("Aget")
 	print(a)

def heapsort(a):
	build_max_heap(a)
	print("here")
	for i in range(len(a) - 1, -1, -1):
		temp = a[0]
		a[0] = a[i]
		a[i] = temp
		max_heapify(a, i-1, 0)


def main():
	heap = [1,8, 5, 3, 2, 9]
	
	print(heap)
	build_max_heap(heap)
	# heapsort(heap);
	# create a
	heap_delete(heap, 2)
	# print(extract_max(heap))



if __name__ == "__main__":
	main()