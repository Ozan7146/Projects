import random

def play():
    user = input(" 'r' for rock, 'p' for paper,'s' for scissors \n")
    computer = random.choice(['r', 'p' , 's'])

    if user == computer:
        return "It's a tie!"
    if is_win(user,computer): #true mu dedi�i k�s�m true ise if'e girer yoksa girmez.��nk� if in �al��ma mant��� do�ruysa alt satr�lara bakmakt�r.
        return "You won!"
   
    return "You Lost!"


def is_win(player,opponent):
    if (player == 'r' and opponent == 's') or (player == 's' and opponent == 'p' )  or (player == 'p' and opponent == 'r') :
        return True


print(play())
