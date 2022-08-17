temp = input()
s, cnt = temp.split()
n, cnt = int(s), int(cnt)

def judge(s):
    t = s[::-1]
    if s == t:
        return True
    else:
        return False

flag = 0
if judge(str(n)):
    print(n)
    print(0)
    flag = -1

for i in range(cnt):
    if flag == -1:
        break
    t = int(str(n)[::-1]) + n
    if judge(str(t)):
        print(t)
        print(i + 1)
        flag = 1
        break
    n = t

if flag == 0:
    print(n)
    print(cnt)