import random

with open("data.txt", "a") as o:
    l = [x for x in range(1, 129)]
    random.shuffle(l)
    for x in l:
        o.write(str(x) + "\n")