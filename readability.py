from cs50 import get_string


def main():
    text = get_string("TEXT: ")
    letter = let_count(text)
    sentence = sent_count(text)
    word = word_count(text)
    index = round(0.0588 * (letter/word)*100 - 0.296 * (sentence/word)*100 - 15.8)
    if (index < 1):
        print("Before Grade 1")
    elif (index > 15):
        print("Grade 16+")
    else:
        print(f"Grade {index}")

def let_count(text):
    count = 0
    for i in text:
        if (i >= "A" and i <= "Z"):
            count += 1
        elif (i >= "a" and i <= "z"):
            count += 1
        else:
            pass
    return (count)

def sent_count(text):
    count = 0
    for i in text:
        if (i == "." or i == "?" or i == "!"):
            count += 1
        else:
            pass
    return (count)

def word_count(text):
    count = 1
    for i in text:
        if (i == " "):
            count += 1
        else:
            pass
    return (count)

main()
