import itertools
import time

def insertion_sort(lista):

    for i in range(1, len(lista)):
        clave = lista[i]
        j = i - 1
        while j >= 0 and lista[j] > clave:
            lista[j + 1] = lista[j]
            j -= 1
        lista[j + 1] = clave
    return lista


def fuerza_bruta(password, longitud):
    
    inicio = time.time()
    intentos = 0
    
    
    combinaciones = ["".join(c) for c in itertools.product("0123456789", repeat=longitud)]
    
    
    combinaciones = insertion_sort(combinaciones)
    
    
    for intento in combinaciones:
        intentos += 1
        if intento == password:
            fin = time.time()
            print(f"contraseña encontrada: {intento}")
            print(f"intentos realizados: {intentos}")
            print(f"tiempo de ejecucion: {fin - inicio:.4f} segundos\n")
            return intento
    
    print("no se encontro la contraseña.")
    return None



print("contraseña de 4 digitos")
fuerza_bruta("1234", 4)

print("contraseña de 8 digitos")
fuerza_bruta("87654321", 8)

print("contraseña de 10 digitos")
fuerza_bruta("1029384756", 10)