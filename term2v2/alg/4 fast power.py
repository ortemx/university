a = 12898
n = 45657
s = 1
k = a
while n > 0:
    r = 0
    q = 0
    ntemp = 0
    while ntemp < n-1:
        q += 1
        ntemp += 2
    r = n - ntemp
    if r == 1:
        s *= k
    k *= k
    n = q
print(s)

