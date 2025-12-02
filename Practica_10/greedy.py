import itertools
import time

def fuerza_bruta(password, longitud):
    inicio = time.time()
    intentos = 0
    
    
    for combinacion in itertools.product("0123456789", repeat=longitud):
        intentos += 1
        intento = "".join(combinacion)
        
        
        if intento == password:
            fin = time.time()
            print(f"contraseña encontrada: {intento}")
            print(f"numero de intentos: {intentos}")
            print(f"tiempo de ejecucion: {fin - inicio:.4f} segundos\n")
            return intento
    
    print("no se encontro la contraseña.")
    return None



print("Contraseña de 4 dígitos")
fuerza_bruta("1234", 4)

print("Contraseña de 8 dígitos")
fuerza_bruta("87654321", 8)

print("Contraseña de 10 dígitos")
fuerza_bruta("1029384756", 10)