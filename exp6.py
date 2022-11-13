s = "I am in Ranchi"

temp = ""

length = len(s)

for i in range(length):
    if(s[i] == ' ') :
        print(temp)
        temp=''
    else :
        temp += s[i]

print(temp)


print(length)