import random
from Words import words
from Pic import lives_visual_dict


def rand_func():
    number = random.randint(0, 500)
    while '-' in words[number]:
        if " " in words[number]:
            number = random.randint(0, 500)  # len(words) - 1

    return words[number]


word = rand_func()
print(len(word) * " _")
print(word)
used_letter = []

lives = len(word) + 2
x = 7
while lives > 0:
    word_last = ""
    a = 0

    users_letter = input("Enter the letter: ")
    lives -= 1
    used_letter.append(users_letter)

    if users_letter not in word:
        if x >= 0:
            print(lives_visual_dict[x])
            x = x - 1

    for i in word:
        if i in used_letter:
            word_last = word_last + i
            a += 1
        else:
            word_last = word_last + "_"

    print(word_last)

    if lives == 0:
        print("You lost!")

    print("You used this letters: ", ', '.join(used_letter))
    if word_last == word:
        print("You Won!")
        break

    print(f"You have {lives} lives")
