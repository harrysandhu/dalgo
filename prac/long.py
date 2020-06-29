
def is_pal(s):    
    n = len(s)
    for i in range(n):
        if s[i] != s[n-i-1]:
            return False
    return True
    

def str_contains(s, x):
    data = []
    for i in range(len(s)-1, -1, -1) :
        if s[i] == x:
            data.append(i)
    
    return data
        

"""
    input : babad
    output: bab
    
    cbbdbb
    : bbdbb

"""
def lp(s):
    res = ""
    t = ""
    n = len(s)
    lp = ""
    for i in range(n):
        j = -1
        data = str_contains(s, s[i])
        if len(data) > 0: 
            for index in data:
                # print(s[i:index+1])
                if is_pal(s[i:index+1]):
                    if len(s[i:index+1]) > len(lp):
                        lp = s[i:index+1]
    
    return lp






def main():
    s = "abcbe"
    # print(s)
    # print(lp(s))

    print(s)
    print(lp(s))




if __name__ == "__main__":
    main()  