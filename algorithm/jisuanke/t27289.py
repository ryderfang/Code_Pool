def gcd(a, b):
    if a >= b:
        if a % b == 0:
            return b
        else:
            return gcd(b, a - b)
    else:
        return gcd(b, a)

def f(x):
    s = str(x)
    ret = 1
    lst = list(map(lambda t: int(t), s))
    for i in lst:
        ret *= i
    return ret

# ftbl = []
# for i in range(1, 1001):
#     ftbl.append(f(i))

n, k = input().split(' ')
n = int(n)
k = int(k)
cnt = 0
for i in range(1, n + 1):
    for j in range(1, n + 1):
        fi = f(i)
        fj = f(j)
        if gcd(fi, fj) <= k:
            cnt += 1

print(cnt)
