def write_to_file(list_items, path):
    with open (path, 'w') as file:
        if len(list_items)==0:
            return
        headers= list(list_items[0].keys())
        file.write(','.join(headers)+'\n')
        
        for item in list_items:
            values=[]
            for header in headers:
                values.append(str(item.get(header, "")))
            file.write(",".join(values)+'\n')
