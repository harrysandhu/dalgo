def insertionSort(a):
	n = len(a)
	for i in range(n):
		temp = a[i]
		j = i-1
		while j >= 0 and a[j] > temp:
			a[j+1] = a[j]
			j = j-1
		a[j+1] = temp

	return a


def main():
	ar = [4, 3, 5, 5, 6, 2]
	gr = insertionSort(ar)
	print(gr)


if __name__ == "__main__":
	main()