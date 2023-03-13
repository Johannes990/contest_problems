names = []
lines = int(input())
for _line in range(lines):
    read_string = input()
    if "Sleep" in read_string:
        names.append(read_string.split()[1])
    elif read_string == "Test":
        if names:
            print(names[-1])
        else:
            print("Not in a dream")
    elif read_string == "Kick":
        if names:
            names.pop()