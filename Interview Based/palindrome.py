""" 
A palindrome number looks like "121" 

Now how to get it!!
 """


number = int(input())

temp = number
reverse_num = 0
while number > 0:
    
    digit=number%10
    reverse_num = reverse_num * 10 + digit
    
    number = number//10
    reverse_num += number//10 * 0

if reverse_num == temp: print("Palindrome")
else: print("Nope")
