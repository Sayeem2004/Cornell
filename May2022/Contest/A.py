def main():
    convert1 = {
        "life": "0",
        "heaven": "1",
        "earth": "2",
    }
    n, m = [int(num) for num in input().split(" ")]
    num1 = input().split(" ")
    num2 = input().split(" ")
    first = ""
    second = ""
    for val in num1:
        first += convert1[val]
    for val in num2:
        second += convert1[val]
    res = int(first, 3) + int(second, 3)
    convert2 = {
        0: "life",
        1: "heaven",
        2: "earth",
    }
    pnt = ""
    while (res > 0):
        pnt = convert2[res % 3] + " " + pnt
        res //= 3
    print(pnt[:-1])

main()
