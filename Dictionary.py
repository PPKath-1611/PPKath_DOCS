import json
from difflib import get_close_matches

data = json.load(open("DATA.json"))


def translate(word):
    word = word.lower()
    if word in data:
        return data[word]
    elif word.title() in data:
        return data[word.title()]
    elif word.upper() in data:
        return data[word.upper()]
    elif len(get_close_matches(word, data.keys())) > 0:
        print("Did you mean %s" % get_close_matches(word, data.keys())[0])
        decide = input("Press Y/y for yes and N/n for no ")
        if decide == "y":
            return data[get_close_matches(word, data.keys())[0]]
        elif decide == "n":
            print("Please Try Again!")
        else:
            print("Wrong Input! Please enter y or n only")
    else:
        print("SORRY! Please try again!")


word = input("Enter the word to have the definition of it ")
output = translate(word)
if type(output) == list:
    for i in output:
        print(i)
