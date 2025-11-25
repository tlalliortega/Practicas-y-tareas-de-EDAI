def fibonacci_recursivo(numero):
    if numero == 1:
        return 0
    if numero == 2 or numero == 3:
        return 1
    return fibonacci_recursivo(numero -1) + fibonacci_recursivo(numero-2)
posiciones = [7, 21, 40, 71, 94]
print("numeros en la secuencia de fibonacci (recursivo): ")
for p in posiciones:
    print(f"posicion {p}: {fibonacci_recursivo(p)}")
    #Este programa es muy ineficiente para numeros grandes como el 71 y 94 