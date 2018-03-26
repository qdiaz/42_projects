from color import Color
from color import printColor

def printRules(rules):
    printColor(Color.PURPLE, str(len(rules.keys())) + " letters have a rule associated with them")
    printColor(Color.CYAN, 'Here\'s the result of the rules stocking: ' + '\n')
    sizeCol1 = len('letters') + 2 if len('letters') + 2 > max(map(len, rules)) else max(map(len, rules)) + 2
    sizeCol2 = len('rules') + 2 if len('rules') + 2 > max(map(len, rules.values())) else max(map(len, rules.values())) + 2
    p = '\033[36m' + '|' + '\033[0m'
    printColor(Color.DARKCYAN, '+' + '-' * sizeCol1 + '+' + '-' * sizeCol2 + '+');
    print(p + ' Letters' + ' ' * (sizeCol1 - 8) + p + ' Rules' + ' ' * (sizeCol2 - 6) + p)
    printColor(Color.DARKCYAN, '+' + '-' * sizeCol1 + '+' + '-' * sizeCol2 + '+');
    for key, value in rules.items():
        print(p + ' ' + key + ' ' * (sizeCol1 - len(key) - 1) + p + ' ' + value + ' ' * (sizeCol2 - len(value) - 1) + p)
        printColor(Color.DARKCYAN, '+' + '-' * sizeCol1 + '+' + '-' * sizeCol2 + '+');
    print('')

def formatRules(line, separator):
    line = line.replace('\n', '')
    line = line.replace(' ', '')
    prop, conc = line.split(separator)
    if prop.count('(') != prop.count(')'):
        printColor(Color.RED, 'Opened or Closed bracket missing here: ' + prop)
        return None, None
    if prop.find('!') != -1 and prop[prop.find('!') + 1] == '!':
        printColor(Color.RED, 'You cannot put two consecutives `!` in your rule: ' + prop)
        return None, None
    return prop, conc

def printErrorInverseConc(letters):
    printColor(Color.RED, letters + ' has been set to false then to true in two same consecutives propositions\n')
    return -1

def addRules(rules, prop, conc):
    if conc.find('|') == -1:
        i = 0
        xorDict = {}
        for segment in conc.split('^'):
            xorDict[i] = segment
            i += 1
        for j in xorDict:
            for letters in xorDict[j].split('+'):
                if letters in rules:
                    rules[letters] = rules[letters] + '|' + '(' + prop + ')'
                elif '!' + letters in rules and '(' + prop + ')' == rules['!' + letters]:
                    return printErrorInverseConc(letters)
                elif [value for key, value in rules.items() if '!' + key == letters and '(' + prop + ')' == rules[key]]:
                    return printErrorInverseConc(letters[1:])
                else:
                    rules[letters] = '(' + prop + ')'
                for k in xorDict:
                    if letters not in xorDict[k]:
                        rules[letters] = rules[letters] + '+' + '!(' + xorDict[k] + ')'
    else:
        rules[conc] = '(' + prop + ')'
    return 0

def stockRules(rules, line):
    if line.find('<') != -1:
        prop, conc = formatRules(line, '<=>')
        if prop is None or conc is None:
            return -1
        if list(set([c for c in prop if c in conc and c.isupper()])):
            printColor(Color.RED, 'You can\'t have a conclusion that implies itself in the proposition')
            return -1
        if addRules(rules, prop, conc) == -1:
            return -1
        if addRules(rules, conc, prop) == -1:
            return -1
    else:
        prop, conc = formatRules(line, '=>')
        if prop is None or conc is None:
            return -1
        if list(set([c for c in prop if c in conc and c.isupper()])):
            printColor(Color.RED, 'You can\'t have a conclusion that implies itself in the proposition')
            return -1
        if addRules(rules, prop, conc) == -1:
            return -1
    return 0
