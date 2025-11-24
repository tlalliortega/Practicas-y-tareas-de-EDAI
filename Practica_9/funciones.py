def imprime_nombre(nombre):
    print("hola " + nombre)

imprime_nombre("JJ")

def cuadrado(x):
    return x**2

x = 5
resultado_cuadrado = cuadrado(x)
print(f"El cuadrado de {x} es: {resultado_cuadrado}")

def varios(x):
    return x**2, x**3, x**4

val1, val2, val3 = varios(2)
print("{} {} {}".format(val1, val2, val3))

def cuadrado_default(x=3):
    return x**2

resultado_default = cuadrado_default()
print(f"El cuadrado por defecto (de 3) es: {resultado_default}")

val4, _, val5 = varios(2)
print("{} {}".format(val4, val5))
