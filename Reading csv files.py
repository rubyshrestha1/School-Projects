## To get the header from the file
def parse_header(header_line):
    return header_line.strip().split(",")

## to get the values as float
def parse_values(line):
    val=[]
    temp=line.strip().split(",")
    for i in temp:
        if i!="":
            val.append(float(i))
        else:
            val.append(0.0)
    return val

## Storing the column header and values as key-value pair
def create_dict(header, values):
    result={}
    for header, value in zip(header, values):
        result[header]= value
    return result
        
## main method to read from file
def read_csv(path):
    result=[]
    with open(path, 'r') as file:
        file_line= file.readlines()
        header= parse_header(file_line[0])
        for line in file_line[1:]:
            value= parse_values(line)
            temp_dict=create_dict(header, value)
            result.append(temp_dict)
    return result
