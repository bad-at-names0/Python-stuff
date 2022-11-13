def createList():
    l=[]
    t=()
    for i in range(1,11,1):
        t=(i,i*2,i*3)
        l.append(t)
        t=()
    return l
print(createList())