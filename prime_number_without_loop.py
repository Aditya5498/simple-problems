def prime(a):
	def until(n):
		if (n<2):
			return True
		else:
			return a%n!=0 & until(n-1)
	return until(int(a/2))
a=int(input("Enter the number you would like to check = "))
if(prime(a)==True):
	print("Your number, "+str(a)+" which was entered is a valid prime number")
else:
	print("Your number, "+str(a)+" which was entered is NOT a prime number")