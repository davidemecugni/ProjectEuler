import csv
#Returns the sum of the chars(positional number) in a string
#COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53
def StringToSumOfChars(s):
    n=0
    for letter in s:
        n+= ord(letter.upper())-64
    return n
if __name__ == "__main__":
    l = []
    with open("Id022\p022_names.txt") as f:
        l = list(csv.reader(f))[0]
    #File alphabetically sorted
    l.sort()
    tot = 0
    for i in range(len(l)):
        #Adds to total the sum of the chars of the name times its position in the sorted list
        tot += StringToSumOfChars(l[i])*(i+1)
    print(f"The result is : {tot}")