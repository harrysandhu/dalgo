#!/usr/bin/env python3
def file_input(filename: str) -> list:
    """
    Handle file input.
    :return: list, the contents of the file as array of lines.
    """
    f = open(filename, "r")
    data = f.readlines()
    return data


def process_matrix(matrix: list, n: int, m: int) -> list:
    """
    Process the matrix.
    :param matrix: list, the matrix to process of size (n x m)
    :param n: int, number of rows in the matrix.
    :param m: int, number of columns in the matrix.
    :return: list, the output matrix.
    """
    output = [[0 for i in range(m)] for i in range(n)]
    bounds = [0, 1, -1]
    for i in range(n):
        for j in range(m):
            if matrix[i][j] == "*":
                output[i][j] = "*"
                neighbours = []
                for x in range(len(bounds)):
                    for y in range(len(bounds)):
                        if bounds[x] != 0 or bounds[y] != 0:
                            neighbours.append((i+bounds[x], j+bounds[y]))
                

                for cell in neighbours:
                    if cell[0] >= 0 and cell[0] < n:
                        if cell[1] >= 0 and cell[1] < m:
                            if output[cell[0]][cell[1]] != '*':
                                output[cell[0]][cell[1]] += 1

    return output


def main():
    """
    Get the matrix params, and output the processed matrix.
    """
    data = file_input("./input.txt")
    n, m = int(data[0].split()[0]), int(data[0].split()[1])
    matrix = data[1:]

    output = process_matrix(matrix, n, m)
    for i in output:
        for j in i:
            print(j, end="")
        print()
    

    

   

if __name__ == "__main__":
    main()




