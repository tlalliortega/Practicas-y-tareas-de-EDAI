#declaracion de una Tupla
tupla_diasDelMes=(31,28,31,30,31,30,31,31,30,31,30,31)
print(tupla_diasDelMes) #Imprime la tupla completa
print(tupla_diasDelMes[0]) #Imprime el elemento 1
print(tupla_diasDelMes[3]) #Imprime el elemento 4
print(tupla_diasDelMes[1]) #Imprime el elemento 2 
 #Declaracion de tuplas anidadas
tupla_numeros=(('cero', 0),('uno',1, 'UNO'), ('dos', 2), ('tres', 3), ('cuatro', 4), ('X', 5))
print(tupla_numeros) #Imprimir tupla completa
print(tupla_numeros[0])
print(tupla_numeros[1])
print(tupla_numeros[2][0])
print(tupla_numeros[2][1])
print(tupla_numeros[1][0])
print(tupla_numeros[1][1])
print(tupla_numeros[1][2])
#Probando la mutalidad de las listas vz la mutalidad de las tuplas
print("valor actual {}".format(lista_diasDelMes[0]))
lista_diasDelMes[0] = 50 
print("valor cambiando {}".format(lista_diasDelMes[0]))
tupla_diasDelMes[0] = 50 #Esta asignacion manda error, ya que no se pueden cambiar los valores