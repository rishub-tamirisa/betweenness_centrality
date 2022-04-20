discontinued = []
ids = []
ID_VALUES = {}
try:
    with open("225FPDataset/amazon-meta.txt", "r") as file_input: #deleted file from git because of large size
        lines = file_input.readlines()
        x = len(file_input.readlines())
        with open("225FPDataset/amazon-meta-reduced.txt", "w") as output: 
            count = 0
            for line in lines:
                if line.find("Id:") != -1 and lines[count + 2].find("discontinued product") != -1:
                    discontinued.append(count)
                    count = count + 1
                    continue
                if line.find("Id:") != -1 or line.find("title:") != -1:
                    output.write(line)
                count = count + 1
        output.close()
    file_input.close()

    TOTAL_REMOVED = {}
    for key in discontinued:
            temp = ""
            for letter in lines[key]:
                if letter.isdigit():
                    temp = temp + letter
            ids.append(temp)
    for i in range(len(ids)):
        ID_VALUES[ids[i]] = None
    with open("225FPDataset/com-amazon.ungraph.txt", "r") as file_input:
        lines = file_input.readlines()
        with open("225FPDataset/com-amazon-reduced.ungraph.txt", "w") as output:
            for line in lines:
                split = line.split()
                if split[0] in ID_VALUES:
                    TOTAL_REMOVED[split[0]] = None
                    continue
                if split[1] in ID_VALUES:
                    TOTAL_REMOVED[split[1]] = None
                    continue
                output.write(line)
            print("Removed {} Discontinued Products".format(len(TOTAL_REMOVED)))
        output.close()
    file_input.close()
except:
    print("Error")
print("Finished")
