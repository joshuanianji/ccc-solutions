mvs = input()

h = 0
v = 0

for c in mvs:
    if c == 'H':
        h += 1
        h %= 2
    elif c == 'V':
        v += 1
        v %= 2

if h == 0 and v == 0:
    print("1 2\n3 4")

if h == 1 and v == 0:
    print("3 4\n1 2")
if h == 0 and v == 1:
    print("2 1\n4 3")
if h == 1 and v == 1:
    print("4 3\n2 1")
