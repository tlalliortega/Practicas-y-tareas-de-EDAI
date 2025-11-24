vg = 'Global'

def funcion_v1():
    print("funcion_v1:", vg)

def funcion_v2():
    print("funcion_v2:", vg)

def funcion_v3():
    vg = "Local"
    print("funcion_v3:", vg)

def funcion_v4():
    global vg
    print("funcion_v4 antes:", vg)
    vg = "Local"
    print("funcion_v4 después:", vg)


funcion_v1()   
funcion_v2()   
funcion_v3()   
funcion_v4()   
print("Valor final de vg:", vg)