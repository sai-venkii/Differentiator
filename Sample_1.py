largestNumber = int(input("Enter a number "))
code = "Y";
while code == "Y":
    smallestNumber = int(input("Enter a number "))
    if largestNumber < smallestNumber:
        largestNumber = smallestNumber
    if smallestNumber > largestNumber:
        smallestNumber = largestNumber
    code = input("To conitinue enter Y or N to terminate: ")

# cumilative total

length1 = len(chr(largestNumber))
length2 = len(chr(smallestNumber))

largestNumberSum = 0
for i in range(length1):
    largestNumberSum = largestNumberSum + largestNumber[i]

smallestNumberSum = 0
for i in range(length2):
    smallestNumberSum = smallestNumberSum + smallestNumber[i]



print("The largest number is ", largestNumber, "The smallest number is ", smallestNumber)
print("The largest number's cumilative sum is ", largestNumberSum)
print("The smallest number's cumilative sume is ", smallestNumberSum)