
memoria = {1: 0, 2: 1}

def fibonacci_top_down(numero):
    
    if numero in memoria:
        return memoria[numero]
    
    
    f = fibonacci_top_down(numero - 1) + fibonacci_top_down(numero - 2)
    
    
    memoria[numero] = f
    return f


print("Fibonacci_top_down(12) --> salida:", fibonacci_top_down(12)) 
print("Fibonacci_top_down(7)  --> salida:", fibonacci_top_down(7))   