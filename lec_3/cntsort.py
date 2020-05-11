import numpy as np
def countingsort(a):
    n = len(a)
    max = a[0]
    for i in a:
        if i > max:
            max = i
    
    x = np.zeros(max+1)
    for i in a:
        x[i] += 1
    

    li = [] 
    for i in range(len(x)):
        if x[i] != None:
            for c in range(int(x[i])):
                li.append(i)
    
    return li


def main():
    a = [6,3,15,64,4,4,4,4,4,4, 1314142]

    print(countingsort(a))

if __name__ == "__main__":
    main()

