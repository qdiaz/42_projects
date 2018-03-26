def initQueries(line):
    listQueries = [];
    for i in range(1, len(line)):
        if line[i].isspace() or line[i] == '#':
            break
        if line[i] < 'A' or line[i] > 'Z':
            return None
        else:
            listQueries.append(line[i])
    if not listQueries:
        return None
    else:
        return listQueries
