def lettercomb(digits):
    if len(digits) == 0:
        return []
    x = {'1':" ", '2': "abc", '3': "def", '4': "ghi", '5': "jkl", '6': "mno", '7':"pqrs", '8':"tuv", '9':"wxyz"}
    ind = []
    n = len(digits)
    s = 1
    for i in range(n):
        s *= len(x[digits[i]])
        ind.append(0)
    print(ind)  
    i = 0
    ar = []
    while i < s:
        print(ind)
        xstr = ""
        for t in range(n):
            if x[digits[t]][ind[t]] == ' ':
                continue
            xstr += x[digits[t]][ind[t]]
        
        ar.append(xstr)
        for z in range(n-1, -1, -1):
            m = len(x[digits[z]]) -1 
            if ind[z] < m:
                ind[z] += 1
                break
            else:
                ind[z] = 0
        i += 1
    
    return ar





digits = "99"
print(lettercomb(digits))   