def obtenerMayor(param1,param2):
    if param1 < param2:
        print('{} es mayor que {}'. format(param2, param1))
        obtenerMayor(5, 7)
        obtenerMayor(7, 5)
        x = y = z = 3
        if x == y == z:
            print(True)

def obtenerMayorv2(param1, param2):
    if param1 < param2:
        return param2
    else:
        return param1
    print("El mayor es {}".format( obtenerMayorv2(4, 20)))
    print("El mayor es {}".format( obtenerMayorv2(11, 6)))

def obtenerMayor_idiom(param1, param2):
    valor = param2 if (param1 < param2) else param1
    return valor
print("El mayor es {}".format(obtenerMayor_idiom(11, 6)))

def numeros(num):
    if num==1:
        print ("tu numero es 1")
    elif num==2:
        print ("el numero es 2")
    elif num==3:
        print("el numero es 3")
    elif num==4:
        print("el numero es 4")
    else:
        print("no hay opcion")

def numeros_idiom(num):
    if num in (1,2,3,4):
        print("tu numero es {}".format(num))
    else: 
        print("{} no es una opcion".format(num))

def obtenerMasGrande(a, b, c):
    if a > b:
        if a > c:
            return a 
        else:
            return c
    else:
        if b > c:
            return b
        else:
            return c
        print ("El mas grande es {}".format(obtenerMasGrande(7,13,1)))
        

