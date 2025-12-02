def quicksort(lista):
    quicksort_aux(lista,0, len(lista)-1)
    return lista
def quicksort_aux(lista,inicio,fin):
    if inicio < fin:
        pivote = particion(lista,inicio,fin)

        quicksort_aux(lista, inicio, pivote-1)
        quicksort_aux(lista, pivote+1, fin)
def particion(lista, inicio, fin):
    pivote = lista[inicio]
    print("valor del pivote {}".format(pivote))
    izquierda = inicio+1
    derecha = fin
    print ("indice izquierdo {}".format(izquierda))
    print("indice derecho {}".format(derecha))

    bandera = False
    while not bandera:
        while izquierda <= derecha and lista[izquierda] <= pivote:
            izquierda = izquierda + 1
        while lista[derecha] >= pivote and derecha >=izquierda:
            derecha = derecha -1
        if derecha < izquierda:
            bandera= True
        else: 
            temp=lista[izquierda]
            lista[izquierda]=lista[derecha]
            lista [derecha]=temp
    print(lista)

    temp=lista[inicio]
    lista[inicio]=lista[derecha]
    lista[derecha]=temp
    return derecha

lista = [21, 10, 0, 11, 9, 24, 20, 14, 1]
print("lista desordenada: ", lista)
print("lista ordenada: ", quicksort(lista))
