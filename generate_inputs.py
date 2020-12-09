import random


for i in range(1, 101):
    x = random.randint(2, 100)
    array = []
    for j in range(x):
        number = random.randint(-10000, 10000)
        array.append(number)

    f = open("files\\inputs\\input" + str(i) + ".txt", "w")
    f.write(str(x) + "\n")
    f.write(" ".join(map(str, array)))
    f.close()

    f = open("files\\answers\\answer" + str(i) + ".txt", "w")
    f.write(" ".join(map(str, sorted(array))))
    f.close()

    f = open("files\\outputs\\output" + str(i) + ".txt", "w")
    f.close()
