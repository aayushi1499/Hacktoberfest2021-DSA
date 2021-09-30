
word = input()

rev_word = ""


for letters in word:
	rev_word = letters + rev_word
    

if (word == rev_word):
	print("Yes")
else:
	print("No")

