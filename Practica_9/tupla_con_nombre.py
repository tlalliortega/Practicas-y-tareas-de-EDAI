#Se debe importar la libreria para hacer uso de namedtuple
from collections import namedtuple
#Se crea la tupla con nombre
#El primer argumento es el nombre de la tupla, mientras que el segundo argumento son los campos
#p es la referencia de la tupla
planeta = namedtuple('planeta', ['nombre', 'numero'])
# se crea el planeta 1 y se sgrega a la tupla los valores correspondientes a los campos
planeta1 = planeta('Mercurio', 1)
print(planeta1)
#Se crea el planeta 2 
planeta2 = planeta('Venus', 2)
#Se imprimen los valores de los campos
print(planeta1.nombre, planeta1.numero)
print(planeta2[0], planeta2[1])
print('Campos de la tupla: {}'.format(planeta1._fields))
