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

index = 0.0588 * (100.0 * letters / words) - 0.296 * (100.0 * sentences / words) - 15.8

if index < 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print("Grade " + str(index))
