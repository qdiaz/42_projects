import string

def initHash(facts):
    tab = {}
    i = 65;
    while i <= 90:
        tab[chr(i)] = {'value': False, 'state': 0}
        i += 1
    for i in range(1, len(facts)):
        if facts[i].isspace() or facts[i] == '#':
            break
        elif facts[i] < 'A' or facts[i] > 'Z':
            return None
        else:
            tab[facts[i]]['value'] = True
    return tab
