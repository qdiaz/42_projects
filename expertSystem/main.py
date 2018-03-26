from hash_letters import initHash
from list_queries import initQueries
from format_rules import stockRules
from format_rules import printRules
from color import Color
from color import printColor
from color import colorString
from copy import deepcopy
import re
import sys

display = True

class ExpertSystem:

    def __init__(self):
        self.hashLetters = None
        self.rules = {}

    def pop(self, a, b, op):
        if op == '+' and (a == 'Undetermined' or b == 'Undetermined'):
            if a != False and b != False:
                return 'Undetermined'
        elif op == '|' and (a == 'Undetermined' or b == 'Undetermined'):
            if a == True or b == True:
                return True
            else:
                return 'Undetermined'
        elif op == '^' and (a == 'Undetermined' or b == 'Undetermined'):
            return 'Undetermined'
        elif op == '+' and (a == True and b == True):
            return True
        elif op == '|' and (a == True or b == True):
            return True
        elif op == '^':
            if a == True and b == False:
                return True
            elif a == False and b == True:
                return True
        return False

    def backwardCalc(self, stack, output):
        popRes = self.pop(output[len(output) - 1], output[len(output)], stack[len(stack)])
        del stack[len(stack)]
        del output[len(output)]
        del output[len(output)]
        output[len(output) + 1] = popRes

    def backwardFinalCalc(self, stack, output, nt = 0):
        popRes = self.pop(output[len(output) - 1], output[len(output)], stack[len(stack)])
        del output[len(output)]
        del stack[len(stack)]
        output[len(output)] = popRes

    def calcProp(self, prop):
        stack = {}
        output = {}
        for i in iter(prop):
            if i == '(':
                stack[len(stack) + 1] = i
            elif i == ')':
                while stack and stack[len(stack)] != '(':
                    self.backwardFinalCalc(stack, output)
                del stack[len(stack)]
                if stack and stack[len(stack)] == '!':
                    del stack[len(stack)]
                    output[len(output)] = not output[len(output)]
            elif i == '+' or i == '|' or i == '^':
                if i == '|' and stack and stack[len(stack)] == '+':
                    while stack and stack[len(stack)] == '+':
                        self.backwardCalc(stack, output)
                elif i == '^' and stack and (stack[len(stack)] == '+' or stack[len(stack)] == '|'):
                    while stack and stack[len(stack)] != '^' and stack[len(stack)] != '(':
                        self.backwardCalc(stack, output)
                stack[len(stack) + 1] = i
            elif i == '!':
                stack[len(stack) + 1] = i
            else:
                if stack and stack[len(stack)] == '!':
                    self.backwardChaining(i)
                    del stack[len(stack)]
                    output[len(output) + 1] = not self.hashLetters[i]['value']
                else:
                    self.backwardChaining(i)
                    output[len(output) + 1] = self.hashLetters[i]['value']
        while len(stack) > 0:
            self.backwardFinalCalc(stack, output)
        return output[len(output)]

    def backwardChaining(self, query):
        for key, rule in self.rules.items():
            if key.find(query) != -1 and self.hashLetters[query]['state'] == 0:
                if key.find('|') != -1:
                    for i in range(len(key)):
                        if key[i].isupper():
                            self.hashLetters[key[i]]['state'] = 1
                            q = raw_input(colorString(Color.CYAN, 'Do you want to set ') + colorString(Color.PURPLE, key[i]) + colorString(Color.GREEN, ' True(T) ') + colorString(Color.CYAN, 'or ') + colorString(Color.RED, 'False(F)') + colorString(Color.CYAN, ' ? ') + 'To leave it ' + colorString(Color.YELLOW, 'undetermined') + ' please enter any other key. \n' + colorString(Color.PURPLE, '[=> '))
                            if q.lower() == 't' or q.lower() == 'true':
                                self.hashLetters[key[i]]['value'] = True
                                print(colorString(Color.GREEN, key[i] + " as been set to " + str(self.hashLetters[key[i]]['value'])))
                            elif q.lower() == 'f' or q.lower() == 'false':
                                self.hashLetters[key[i]]['value'] = False
                                print(colorString(Color.RED, key[i] + " as been set to " + str(self.hashLetters[key[i]]['value'])))
                            else:
                                self.hashLetters[key[i]]['value'] = 'Undetermined'
                                print(colorString(Color.YELLOW, key[i] + " as been set to " + str(self.hashLetters[key[i]]['value'])))
                            print('')
                else:
                    self.hashLetters[query]['state'] = 1
                    if display is True:
                        print(colorString(Color.WHITE, 'The letter ') + colorString(Color.PURPLE, query) + colorString(Color.WHITE, ' is linked to this rule: ') + colorString(Color.PURPLE, rule))
                        printColor(Color.DARKCYAN, 'Calculating this new rule...')
                    if key.find('!') != -1:
                        self.hashLetters[query]['value'] = not self.calcProp(rule)
                    else:
                        self.hashLetters[query]['value'] = self.calcProp(rule)

    def printFacts(self):
        i = 0
        printColor(Color.CYAN, 'The initial facts are:')
        for key, value in self.hashLetters.items():
            if value['value'] == True:
                print('The letter ' + colorString(Color.PURPLE, key) + ' has been set to ' + colorString(Color.GREEN, 'True'))
                i = 1
        if i == 0:
            printColor(Color.RED, 'There is no initial fact')
        print('')

    def parseFile(self, argv):
        listQueries = None
        with open(argv) as fp:
            for line in iter(fp.readline, ''):
                regex = r"^([(]*[!]?[(]*)*[A-Z][)]*[ ]*([\+|\||\^][ ]*([(]*[!]?[(]*)*[A-Z][)]*[ ]*)*[)]*[<]?[=][>][ ]*[!]?[A-Z][ ]*([\+|\||\^][ ]*[!]?[A-Z]*[ ]*)*[ \t]*[\n]$"
                if re.search(regex, line) is None:
                    if line[0] == '=' and self.hashLetters is None:
                        self.hashLetters = initHash(line)
                    elif (line[0] == '=' and self.hashLetters is not None):
                        printColor(Color.RED, 'There can\'t be two consecutive facts')
                        return -1
                    elif line[0] == '?' and listQueries is None:
                        listQueries = initQueries(line)
                    elif line[0] == '?' and listQueries is not None:
                        printColor(Color.RED, 'There can\'t be two consecutive queries')
                        return -1
                    elif line[0] != '#' and not re.search(r"^[\s]*$", line):
                        printColor(Color.RED, 'Rules is not valid: ' + line)
                        return -1
                else:
                    if stockRules(self.rules, line) == -1:
                        return -1
            if self.hashLetters is None or not self.hashLetters:
                printColor(Color.RED, 'There must be a fact\'s declaration preceded by a \'=\' or a valid serie of facts')
                return -1
            if listQueries is None or not listQueries:
                printColor(Color.RED, 'There must be a declaration of queries preceded by a \'?\' or a valid serie of queries')
                return -1
            if self.rules is None or not self.rules:
                printColor(Color.RED, 'There must be a declaration of rules or a valid serie of rules')
                return -1
            if display is True:
                printRules(self.rules)
                self.printFacts()
            stockLetters = deepcopy(self.hashLetters)
            for query in listQueries:
                printColor(Color.CYAN, 'We are looking for the result of this query: ' + query)
                self.backwardChaining(query)
                if self.hashLetters[query]['value'] == False:
                    printColor(Color.RED, query + ' is: ' + str(self.hashLetters[query]['value']))
                elif self.hashLetters[query]['value'] == True:
                    printColor(Color.GREEN, query + ' is: ' + str(self.hashLetters[query]['value']))
                elif self.hashLetters[query]['value'] == 'Undetermined':
                    printColor(Color.YELLOW, query + ' is: ' + str(self.hashLetters[query]['value']))
                print('')
                self.hashLetters = deepcopy(stockLetters)

def main():
    global display
    if len(sys.argv) < 2:
        printColor(Color.RED, 'The program must have at least one argument')
        exit(-1)
    d = raw_input(colorString(Color.CYAN, 'Do you wish to have the detailled process (Y/n):\n' + colorString(Color.PURPLE, '[=> ')))
    while d.lower() != 'y' and d.lower() != 'n':
        d = raw_input(colorString(Color.CYAN, 'Input not valid please use (Y/n):\n' + colorString(Color.PURPLE, '[=> ')))
    if d == 'y' or d == 'Y':
        display = True
    else:
        display = False
    for i in range(1, len(sys.argv)):
        expertSystem = ExpertSystem()
        expertSystem.parseFile(sys.argv[i])

if __name__ == '__main__':
    main()
