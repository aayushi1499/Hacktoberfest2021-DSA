def user_input():
    List = ["stone","paper","scissor","thread"]
    user_choice = input("Enter stone , paper , scissor or thread...\n");
    user_choice = user_choice.lower()
    count_wrong_choice = 1
    ret_choice = None
    while List.count(user_choice) == 0 and count_wrong_choice != 5:
        print("Wrong choice entered.Please,re-enter your choice :-")
        user_choice = (input()).lower()
        count_wrong_choice += 1
    if List.count(user_choice) == 0:
        ret_choice = "not_interested"
    else:
        ret_choice = user_choice
    return ret_choice

def return_winner(dev_choice,user_choice):
    ret_value = None
    if dev_choice == user_choice:
        ret_value = 0
    else:
        if dev_choice == "stone":
            if user_choice == "scissor":
                ret_value = 1
            else:
                ret_value = 2
        elif dev_choice == "paper":
            if user_choice == "stone":
                ret_value = 1
            else:
                ret_value = 2
        elif dev_choice == "scissor":
            if user_choice == "paper" or user_choice == "thread":
                ret_value = 1
            else:
                ret_value = 2
        else:
            if user_choice == "stone" or user_choice == "paper":
                ret_value = 1
            else:
                ret_value = 2
    return ret_value

def main():
    import random
    import time
    print("\"STONE*PAPER*SCISSOR*THREAD\"\n\n")
    print("NOTE --->\n")
    print("1.)Please,enter correct options during the match(s).")
    print("2.)Incase you entered wrong choic while playing then you will be given the chance to re-enter the correct choice(<=5).")
    print("3.)Maximize your device screen.")
    print("\n---> Get ready for the game while the device gets ready.\n")
    time.sleep(15);
    List = ["stone","paper","scissor","thread"]
    num_matches = int(input("Enter number of matches you want to have with your device :-\n"))
    print("\n")
    matches_device_won = 0
    matches_user_won = 0
    tie_matches = 0
    for i in range(1,num_matches+1,1):
        user_choice = user_input()
        dev_choice = random.choice(List)
        print("-> ",dev_choice)
        if user_choice == "not_interested":
            print("It seems that you are not interested in having the match.\nSo,match over.")
            tie_matches += 1
        else:
            winner = return_winner(dev_choice,user_choice)
            if winner == 0:
                print("It's a tie.Keep it up!")
                tie_matches += 1
            elif winner == 1:
                print("Oops!you lost the match.")
                matches_device_won += 1
            else:
                print("Congratulations!you won the match.")
                matches_user_won += 1
        print("\n")
    print("You won : ",matches_user_won," matches")
    print("You lost : ",matches_device_won," matches")
    print("No. of tie matches : ",tie_matches," matches")

if __name__ == "__main__":
   main()
