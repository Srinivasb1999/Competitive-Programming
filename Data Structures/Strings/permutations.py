def permutations(str):
    if(str == ""): return [""]
    permutes = []
    for char in str:
        subpermutes = permutations(str.replace(char, '', 1))
        for each in subpermutes:
            permutes.append(char + each)
    return permutes

def getPermutations(array):
    # Write your code here.
    if(len(array) == 0): return []
    permutes = []
    for index in range(len(array)):
        prefix, rest = array[index: index + 1], array[0:index] + array[index + 1:]
        subpermutes = getPermutations(rest)
        if len(subpermutes) == 0: permutes.append(prefix)
        else:
            for each in subpermutes:
                permutes.append(prefix + each)
    return permutes


print(*permutations('abc'))
print(*getPermutations([1, 2, 3]))