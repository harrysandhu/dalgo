def cycleLen(n):
    c = 1
    while n != 1:
        if n % 2 != 0:
            n = 3* n + 1
        else:
            n /= 2
        c += 1
    return c


def cyc(n):
    if n == 1:
        return 1
    elif n % 2 != 0:
        return 1 + cyc( 3*n+1)
    return 1 + cyc(n/2)



def maxCycleLength(i, j):
    prevals = {}
    max = 1
    for k in range(i, j+1):
        c = 1
        n = k
        while n != 1:
            if n in prevals:
                c += prevals[n]
                n = 1;
            else:
                c += 1
                if n % 2 != 0:
                    n = 3*n +1
                else:
                    n /= 2
        prevals[k] = c        
        if c > max:
            max = c


    return max

def main():
    i = 1
    j = 8

    c = maxCycleLength(i, j)
    print("{0} {1} {2}".format(i, j, c))

    print(cycleLen(22))

if __name__ == "__main__":
    main()
