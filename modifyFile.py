try:
    with open("amazon-meta.txt", "r") as file_input: #deleted file from git because of large size
        lines = file_input.readlines()
        with open("225FPDataset/amazon-meta-reduced.txt", "w") as output: 
            for line in lines:
                if line.find("Id:") != -1 or line.find("discontinued product") != -1 or line.find("title:") != -1:
                    output.write(line)
    print("Finished")
except:
    print("Error")