discontinued = []
ids = []
ID_VALUES = []
try:
    with open("amazon-meta.txt", "r") as file_input: #deleted file from git because of large size
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
        for key in discontinued:
            temp = ""
            for letter in lines[key]:
                if letter.isdigit():
                    temp = temp + letter
            ids.append(temp)
    ID_VALUES = [int(number) for number in ids]
    print("Finished")
    print(ID_VALUES)
except:
    print("Error")