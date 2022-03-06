# TODO
from cs50 import get_string

string = get_string("String: ")
# string = "Congratulations! Today is your day. You're off to Great Places! You're off and away!"


def check_index(w, c, sn):
    char_100w = (100 * c) / w
    sn_100w = (100 * sn) / w
    idx = round((0.0588 * char_100w) - (0.296 * sn_100w) - 15.8)

    if (idx > 16):
        print("Grade 16+")
    elif (idx < 1):
        print("Before Grade 1 ")
    else:
        print(f"Grade {idx}")


def get_char(s):
    c = 0
    for i in range(len(s)):
        if (s[i].isalpha()):
            c += 1
    # print(f"char are {c}")
    return c


def get_words(s):
    w = 0
    for i in range(len(s)):
        if (s[i].isspace()):
            w += 1
    w += 1
    # print(f"words are {w}")
    return w


def get_senetences(s):
    sn = 0
    for i in range(len(s)):
        # if (s[i] == "." or s[i] == "!" or s[i] == "?"):
        if (ord(s[i]) == 46 or ord(s[i]) == 33 or ord(s[i]) == 63):
            sn += 1
    # print(f"sn are {sn}")
    return sn


c = get_char(string)
w = get_words(string)
sn = get_senetences(string)
check_index(w, c, sn)

