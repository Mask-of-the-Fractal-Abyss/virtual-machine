def addNewFunction(name, impl):
    return f"""
int {name} (Space* space) """ + "{" + impl + "}"

lst = []
functions = ""

def operate(name, op, num):
    global functions
    lst.append(name + f"{num}Tracker")
    lst.append(name + f"{num}Current")
    functions += addNewFunction(name + f"{num}Tracker", f"""\
combineTriple(space->tracker->vectors[{num}], {op}, space->space[currentPosition]->vectors[{num}]); return 0;""")
    functions += addNewFunction(name + f"{num}Current", f"""\
combineTriple(space->space[currentPosition]->vectors[{num}], {op}, space->tracker->vectors[{num}]); return 0;""")

for i in range(3):
    operate("set", " =", i)
    operate("add", "+=", i)
    operate("sub", "-=", i)
    operate("div", "/=", i)
    operate("mul", "*=", i)
    operate("mod", "%=", i)

s = "opCode codes[] = {"
for i in range(len(lst)):
    s += lst[i] + f', //{i}\n'
s += "};"
lst1 = [functions, s]
fileText = ""
with open("vm.c", "r") as f:
    fileText = f.read()
# print(fileText)
for i in range(len(lst1)):
    fileText = fileText.replace(f"/*{i}*/", lst1[i])
print(fileText)
with open("vm.c", "w") as f:
    f.write(fileText)
