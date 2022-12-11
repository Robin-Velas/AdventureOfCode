# a function that reads a file and returns a list of lines
def read_file(filename):
    with open(filename) as f:
        return f.readlines()

# take a line, and will read the first char as the opponent and the character after the whitespace as the move
def parse_line(line):
    opponent, me = line.split(' ')
    #remove new line properly
    me = me.replace('\n', '')

    switcher = {
        'A': 0,
        'B': 1,
        'C': 2,
        'X': 0,
        'Y': 1,
        'Z': 2
    }
    return switcher.get(opponent), switcher.get(me)
valeur = [
    #   R P S me
    # R
    # P
    # S
    [1+3, 2+6, 3],
    [1, 2+3, 3+6],
    [1+6, 2, 3+3]
]

correspondance = [
    #   X Y Z me
    # R
    # P
    # S
    #['S', 'R', 'P'],
    #['R', 'P', 'S'],
    #['P', 'S', 'R']

    [2, 0, 1],
    [0, 1, 2],
    [1, 2, 0]
]

def get_winner(opponent, me):
    return valeur[opponent][me]

def main():

    # read the file
    lines = read_file('input.txt')
    #part 1
    parsed_lines = [parse_line(line) for line in lines]
    score = 0
    for opponent, me in parsed_lines:
        score += get_winner(opponent, me)
    print(score)

    #part 2
    score = 0
    for opponent, me in parsed_lines:
        #convert to the new system
        me = correspondance[opponent][me]
        score += get_winner(opponent, me)
    print(score)

main()