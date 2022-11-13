a = int(input("enter 1st number : "))
b = int(input("enter 2nd number : "))
c = int(input("enter 3rd number : "))
d = int(input("enter 4th number : "))


def sum(a, b, c, d):
    return (a+b+c+d)


def product(a, b, c, d):
    return (a*b*c*d)


def sumOfSquare(a, b, c, d):
    return ((a**2)+(b**2)+(c**2)+(d**2))


def productOfSquare(a, b, c, d):
    return ((a**2)*(b**2)*(c**2)*(d**2))


print("sum is: ",sum(a, b, c, d))
print("product is: ", product(a, b, c, d))
print("sum of square is: ", sumOfSquare(a, b, c, d))
print("product of square is: ", productOfSquare(a, b, c, d))