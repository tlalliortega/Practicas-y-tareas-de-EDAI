memoria = {1:0, 2:1, 3:1}
def fibonacci_memo(numero):
    if numero in memoria:
        return memoria[numero]
    memoria[numero] = fibonacci_memo(numero-1) + fibonacci_memo(numero-2)
    return memoria[numero]
posiciones = [7, 21, 40, 71, 94]
print("numeros en la secuencia de fibonacci (memoizacion): ")
for p in posiciones:
    print(f"posicion{p}: {fibonacci_memo(p)}")
    
