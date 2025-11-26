def max_recursivo(lista, inicio, fin):
    if inicio == fin:
        return lista[inicio]
    else:
        medio = (inicio + fin) // 2
        max_izquierdo = max_recursivo(lista, inicio, medio)
        max_derecho =   max_recursivo(lista, medio + 1, fin)
        return max(max_izquierdo, max_derecho)
    
n = int (input("¿cual sera el tamaño de su lista: ?"))
lista = []
print("por favor escribe los elementos: ")
for _ in range(n):
    elemento = int(input())
    lista.append(elemento)
resultado = max_recursivo(lista, 0, n-1)
print("El valor maximo del arreglo es: ", resultado)