total = 0
lines = []
with open("input.txt") as file:
    counter = 0
    start = 0
    stop = 3
    for line in file:
        lines.append(line.strip())
        curr_group = lines[start:stop]
        counter += 1

        if counter%3 == 0:
            for letter in curr_group[0]:
                if letter in curr_group[1]:
                    if letter in curr_group[2]:
                        #if upper
                        if letter.isupper():
                            total += ord(letter) - 64 + 26
                        #if lower
                        elif letter.islower():
                            total += ord(letter) - 96 
                        break
            start += 3
            stop += 3

print(total)