for i in range(1, 101):

    f = open("files\\answers\\answer" + str(i) + ".txt", "r")
    answer = f.read()
    f.close()

    f = open("files\\outputs\\output" + str(i) + ".txt", "r")
    output = f.read()[:-1]
    f.close()

    print("TEST №" + str(i), "OK" if answer == output else "WRONG ANSWER")
