text = ""

while not text:
    text = input("Text: ")

sentences = 0
words = 0
letters = 0
for c in text:
    if c == "." or c == "!" or c == "?":
        sentences += 1
    elif c == " ":
        words += 1
    elif c.isalpha():
        letters += 1

index = 0.0588 * lett
