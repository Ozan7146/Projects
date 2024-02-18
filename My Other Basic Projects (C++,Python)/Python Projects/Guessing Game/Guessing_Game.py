
# https://docs.python.org/3/library/random.html
import random

def guess(x):

    random_number = random.randint(1, x)
    guess = 0 #asla s�f�r olmayaca��n� bildi�imiz i�in b�yle yaz�yoruz
    while guess != random_number:
        guess = int(input(f"Guess a number between 1 and {x}: "))
        print(guess)
        if guess < random_number:
            print("Try Higher")
        
        elif random_number < guess:
            print("Try Lower")
        
    print("Correct One")


guess(10)

def guess1(x):

    random_number = random.randint(1, x)
    guess = 0 #asla s�f�r olmayaca��n� bildi�imiz i�in b�yle yaz�yoruz
    while 1:
        guess = int(input(f"Guess a number between 1 and {x}: "))
        print(guess)
        
        if random_number == guess:
            print("Correct Number")
            break

        elif random_number < guess:
            print("Try Lower")
        
        else:
            print("Higher")
    


guess1(10)


def computer_guess(x):
    low= 1
    high= x
    feedback= ''
    while feedback != 'c':
        if low != high:
            guess = random.randint(low,high)
        else: #if low = high
            guess = low #or high because they are same thing

        feedback = input(f"Is {guess} too high (H),too low (L) or correct (C) ").lower()
        if feedback == 'h':
            high = guess-1
        elif feedback == 'l':
            low = guess + 1

    print("Computer find the correct number which is: ",guess)


computer_guess(1000)
            
