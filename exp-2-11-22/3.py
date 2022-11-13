a=int(input("enter 1st number : "))
b=int(input("enter 2nd number : "))

def HCF(a,b):
    for i in range(1,a+1,1):
        if(a%i==0 and b%i==0):
            ans=i
    return ans

print("Highest Common Factor",HCF(a,b))    