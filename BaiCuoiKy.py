import math
import sys

hp1 = int
hp2 = int
d = int
c = []
s = int
t = ["Flood", "Storm", "Rain", "Shower", "Drizzle", "Cloudy"]
fdst = float
p = float
P1, P2, P3, P4 = int, int, int, int

def PrimeNumberCheck(n):
    count = int(0)
    if n < 2:
        return count
    for i in range(2, n):
        if (n % i) == 0:
            count = 1
            break
    return count

def ArmstrongNumberCheck(n):
    temp = n
    add_sum = 0
    count = 0
    while temp != 0:
        k = temp % 10
        add_sum += k * k * k
        temp = temp // 10
    if add_sum == n:
        count = 1
    else:
        count = 0
    return count

def TriangularNumber(n):
    j = 1
    k = 1
    for i in range(n):
        j += 1
        k += j
    return k

def Calculate(d, s, c):
    gs = float(0)
    pt = float(0)
    sodu = s % 6
    if sodu == 0:
        gs = 2 * float (s)
        pt = -0.1;
        for i in range(5):
            if c == t[0]:
                break
            pt += 0.05
    elif sodu == 1:
        gs = float (s) / 2
        pt = -0.15
        for i in range(5):
            if c == t[1]:
                break
            pt += 0.05
    elif sodu == 2:
        gs = float(- float(pow((s % 9), 3) / 5))
        pt = -0.2
        for i in range(5):
            if c == t[2]:
                break
            pt += 0.05
    elif sodu == 3:
        gs = float(- float(pow((s % 30), 2) + 3 * float(s)))
        pt = -0.25
        for i in range(5):
            if c == t[3]:
                break
            pt += 0.05
    elif sodu == 4:
        gs = - float(s)
        pt = -0.05
        for i in range(5):
            if c == t[4]:
                break
            pt += 0.05
    elif sodu == 5:
        n = (s % 5) + 5
        T = int(TriangularNumber(n))
        gs = - float(T)
        pt = 0
        for i in range(5):
            if c == t[5]:
                break
            pt += 0.05
    fdst = float ((40 - (abs((float (d) - 500)) / 20) + gs) * (1 + pt))
    return fdst

#* Read data from input.txt file
f = open("Code\Learning\input.txt", "r")
hp1 = int(f.readline())
hp2 = int(f.readline())
d = int(f.readline())
c = str(f.readline())
s = int(f.readline())
f.close()

#* Write data to output.out file
f = open("Code\Learning\output.out", "w")
if hp1 < 1 or hp2 < 0 or d < 0 or s < 0 or hp1 > 999 or hp2 > 500 or d > 1000 or s > 101:
    p = -1
    p = round(p, 3)
    f.write(str(p))
    sys.exit()

count_1 = int(PrimeNumberCheck(hp1))
count_2 = int(PrimeNumberCheck(hp2))
if count_1 == 0:
    P1 = 1000
    P2 = (hp1 + s) % 1000
else:
    P1 = hp1
    P2 = (hp1 + d) % 100

if count_2 == 0:
    P3 = hp2
    P4 = (hp2 + d) % 100
else:
    P3 = 1000
    P4 = (hp2 + s) % 1000

count_3 = int(ArmstrongNumberCheck(hp1))
count_4 = int(ArmstrongNumberCheck(hp2))
if count_3 == 1 and count_4 == 1:
    p = 1
    p = round(p, 3)
    f.write(str(p))
    sys.exit()

if d < 200:
    fdst = 0
elif d < 300:
    snake = float((((float (d) + float (P1) + float (P2) + (float (d) + float (P3) + float (P4))) / 1000) / 2))
    if snake > 0.8:
        p = 0
        p = round(p, 3)
        f.write(str(p))
        sys.exit()
    else:
        hp1 -= 100
        hp2 -= 50
        d += 100
        if hp1 < 1 or hp2 < 0 or d < 0 or s < 0 or hp1 > 999 or hp2 > 500 or d > 1000 or s > 101:
            p = -1
            p = round(p, 3)
            f.write(str(p))
            sys.exit()

        count_1 = int(PrimeNumberCheck(hp1))
        count_2 = int(PrimeNumberCheck(hp2))
        if count_1 == 0:
            P1 = 1000
            P2 = (hp1 + s) % 1000
        else:
            P1 = hp1
            P2 = (hp1 + d) % 100

        if count_2 == 0:
            P3 = hp2
            P4 = (hp2 + d) % 100
        else:
            P3 = 1000
            P4 = (hp2 + s) % 1000

        count_3 = int(ArmstrongNumberCheck(hp1))
        count_4 = int(ArmstrongNumberCheck(hp2))
        if count_3 == 1 and count_4 == 1:
            p = 1
            p = round(p, 3)
            f.write(str(p))
            sys.exit()
        fdst = Calculate(d, s, c)
elif d <= 800:
    fdst = Calculate(d, s, c)
elif d > 800:
    fdst = ((-float(d) * float(s)) / 1000)
p = float((((float(P1) + float(P2) * fdst) / (1000 + abs((float(P2) * fdst))) + ((float(P3) + float(P4) * fdst) / (1000 + abs(float(P4) * fdst)))) / 2))
if p < 0:
    p = 0
if p > 1:
    p = 1
p = round(p, 3)
f.write(str(p))
f.close
sys.exit()