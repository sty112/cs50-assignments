from cs50 import get_int, get_string


def luhn_algo(number):
    amount_1 = 0
    amount_2 = 0
    tmp_2 = 0
    tmp = int(number)
    while (tmp >= 1):
        amount_1 += int(tmp % 10)
        tmp = tmp/10
        tmp_2 = int(tmp % 10)*2
        tmp = tmp/10
        if (tmp_2 >= 10):
            for i in str(tmp_2):
                amount_2 += int(i)
        else:
            amount_2 += tmp_2
    return (amount_1 + amount_2)


number = get_string("Number: ")
amount = luhn_algo(number)
n = str(amount)
if (int(n[len(str(amount))-1]) != 0):
    print("INVALID")
else:
    print("pass")
    len = len(number)
    if (len == 13 or len == 15 or len == 16):
        if (len == 15 and number[0] == "3"):
            if (number[1] == "4" or number[1] == "7"):
                print("AMEX")
            else:
                print("INVALID")
        elif (len == 13 or len == 16 and number[0] == "4"):
            print("VISA")
        elif (len == 16 and number[0] == "5"):
            if (number[1] == "1" or number[1] == "2" or number[1] == "3" or number[1] == "4" or number[1] == "5"):
                print("MASTERCARD")
            else:
                print("INVALID")
        else:
            print("INVALID")
    else:
        print("INVALID")
