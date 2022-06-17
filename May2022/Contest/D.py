def getbit(val, q):
    return val >> q & 1

def main():
    n, m = [int(num) for num in input().split(" ")]
    index = ["A", "B", "C", "D", "E", "F", "G", "H", "I", "J"]
    value1 = ["mimic", "real"]
    value2 = ["mimics", "real"]
    lt = []
    for i in range(m):
        words = input().split(" ")
        if (len(words) == 5):
            lt.append([
                index.index(words[0]),
                index.index(words[2]),
                value1.index(words[4]),
            ])
        else:
            lt.append([
                index.index(words[0]),
                index.index(words[3]),
                index.index(words[5]),
                value2.index(words[7]),
            ])
    for i in range(2**n):
        brk = True
        for val in lt:
            if (len(val) == 3):
                bool = getbit(i, val[1]) == val[2]
                if (bool != getbit(i, val[0])):
                    brk = False
                    break
            else:
                bool = (getbit(i, val[1]) == val[3]) and (getbit(i, val[2]) == val[3])
                if (bool != getbit(i, val[0])):
                    brk = False
                    break
        if (brk):
            for q in range(n):
                if (getbit(i, q) == 0):
                    print("mimic")
                else:
                    print("real")
            return

main()
