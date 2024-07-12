from cs50 import get_float

amount = int(get_float("Change: ")*100)
count = 0
while(True):
    if(amount > 0):
        break
    else:
        amount = int(get_float("Change: ")*100)
while(amount > 0):
    if(amount >= 25):
        amount -= 25
        count += 1
    elif(amount < 25 and amount >= 10):
        amount -= 10
        count += 1
    elif(amount < 10 and amount >= 5):
        amount -= 5
        count += 1
    elif(amount < 5 and amount >= 1):
        amount -= 1
        count += 1
print(f"{count}")
