class Color:
    PURPLE = '\033[95m'
    CYAN = '\033[96m'
    DARKCYAN = '\033[36m'
    BLUE = '\033[94m'
    GREEN = '\033[92m'
    YELLOW = '\033[93m'
    RED = '\033[91m'
    BOLD = '\033[1m'
    WHITE = '\033[37m'
    UNDERLINE = '\033[4m'
    END = '\033[0m'
    ONCYAN = '\033[46m'
    ONYELLOW = '\033[43m'

def colorString(color, string):
    return color + string + Color.END

def printColor(color, line):
    print(color + line + Color.END)
