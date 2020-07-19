import sys

def typeof(i):
    if i == '{' or i == '}':
        return 0
    elif i == '(' or i == ')':
        return 1
    elif i == '[' or i == ']':
        return 2

def isBalanced(s):
    opening = ['{', '(', '[']
    closing = ['}', ')', ']']
    x = []
    for i in s:
        #opening braces
        if i in opening:
            x.append(i);
        elif i in closing:
            c = x[len(x) - 1]
            if typeof(i) == typeof(c):
                x.pop()

    if len(x) == 0:
        return True
    else:
        return False
        
    
def main():
    x = sys.stdin.readline()
    if int(x) < 0 or int(x) > 1000:
        print("Invalid input. Number must be < 0 and > 1000")
        sys.exit()
    s = []
    for i in range(int(x)):
        r = ""
        r = sys.stdin.readline()
        if isBalanced(r):
            s.append("YES")
        else:
            s.append("NO")

    for i in s: print(i)
if __name__ == "__main__":
    main()