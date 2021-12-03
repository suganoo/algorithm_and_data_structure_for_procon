N = int(input())

def judge(candidate):
    dep = 0
    for i in range(len(candidate)):
        if candidate[i] == "(":
            dep += 1
        if candidate[i] == ")":
            dep -= 1
        if dep < 0:
            return False
    if dep == 0:
        return True

for i in range(1<<N):
    candidate = ""
    for j in range(N, 0, -1):
        if ( (i & (1<<j) ) == 0):
            candidate += "("
        else:
            candidate += ")"

    if judge(candidate):
        print(candidate)
