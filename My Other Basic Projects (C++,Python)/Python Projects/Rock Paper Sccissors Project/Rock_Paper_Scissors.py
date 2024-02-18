import random

def play():
    user = input(" 'r' for rock, 'p' for paper,'s' for scissors \n")
    computer = random.choice(['r', 'p' , 's'])

    if user == computer:
        return "It's a tie!"
    if is_win(user,computer): #true mu dediði kýsým true ise if'e girer yoksa girmez.Çünkü if in çalýþma mantýðý doðruysa alt satrýlara bakmaktýr.
        return "You won!"
   
    return "You Lost!"


def is_win(player,opponent):
    if (player == 'r' and opponent == 's') or (player == 's' and opponent == 'p' )  or (player == 'p' and opponent == 'r') :
        return True


print(play())
