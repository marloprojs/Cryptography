#This encrypter has three different cryptosystems (ElGammal, RSA, Goldwasser-Micali)
# and a public key exchange system (Diffie-Hellman).

# Fast powering algorithm utilizes successive squaring
def FPA(g, n, p):

	result = 1

	while n > 0:
		#Check if n is even, if so then divide n by 2 and square the base g. 
		if n%2 == 0:
			n = n/2
			g = (g*g)%p
		#If n is odd, then subtract 1 and now n is even
		else:
			n = n-1
			result = (result*g)%p

	return result

#This will calculate the common key
def DiffieHellman(p, g, a, b):
	#The common key is g^(ab) mod p
	key = FPA(g, (a*b), p)
	return key


#This cryptosystem uses the key generated by Diffie Hellman to encrypt some plaintext message
def ElGammal(p, g, a, b, m):
	key = DiffieHellman(p, g, a, b)
	ciphertext = (key*m)%p
	return ciphertext

# Reference: https://en.wikibooks.org/wiki/Algorithm_Implementation/Mathematics/Extended_Euclidean_algorithm
def extEucl(a, b):
	#au + bv = gcd(a, b)
	u0 = 0
	u1 = 1 
	v0 = 1
	v1 = 0
	temp = 0

	while a != 0:
		temp = a
		(q, a) = divmod(b, a)
		b = temp
		temp = v0
		v0 = v1
		v1 = temp - (q*v1)
		temp = u0
		u0 = u1
		u1 = temp - (q*u1)

	return (u0, v0)

#In order to decrypt ElGammal, you must find the inverse of the common key and multiply the inverse and ciphertexts
def decryptEG(p, key, c):
	inverse = 0;
	#Find inverse of the key with the Extended Euclidean Algorithm or Fermat's little Theoren
	if p%key != 0:
		#Since p does not divide the key then key^(p-1) is congruent to 1 mod p => key*key^(p-2) is congruent to 1 mod p
		inverse = FPA(key, p-2, p)
	#If FlT is not applicable to find the inverse, then use the Extended Euclidean Algorithm
	else:
		# Double check if this checks out for if a>b and b>a
		printf("here")
		(a, b) = extEucl(p, key)
		inverse = a
	return inverse


