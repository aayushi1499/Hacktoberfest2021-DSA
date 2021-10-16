import random

choice=[1,2,3,4,5,6]

over=int(input("\nEnter the number of overs="))

over_1=over

no_of_overs=1

your_run=0

ball=1

comp_ball=random.randint(0,over)

comp_score=comp_ball *36

print(f"computer has scored runs= {comp_score}.")

print(f"Your target runs= {comp_score +1}.","\n")

while(no_of_overs<over and your_run<=comp_score):

 print("over=",no_of_overs,"ball=",ball,"\n")

 runs=int(input("enter number to bat="))

 comp_choice=random.randint(1,6)

 print("computer's number=",comp_choice,"\n")

 your_run=your_run + runs

 ball=ball+1

 if runs==comp_choice:
  
  print("total runs=",your_run,"\n")
  print("you are out","\n")
  break
 
 elif runs>6:
  print("enter numbers only till 6\n")
  continue
 
else:
  your_run=your_run + runs
  print("over=",no_of_overs,"ball=",ball)
  print("enter number to bat=",runs,"\n")
  print("computer's number=",comp_choice,"\n")
  print("total runs=",your_run,"\n")
  no_of_overs_1 = ball/6
 
 
if(your_run>comp_score):
 print("You WON the Match!!")

elif(your_run==comp_score):
 print("It's a TIE !!")

else:
 print("You LOST the Match!!")
