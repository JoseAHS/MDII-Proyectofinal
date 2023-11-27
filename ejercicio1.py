import random

# Función para simular productos
def simulacion_productos(num_positivos, num_negativos, intentos):
    productos = []

    for _ in range(intentos):
        # Seleccionar 4 números al azar
        seleccionados = random.sample(num_positivos + num_negativos, 4)
        # Calcular el producto de los números seleccionados
        producto = 1
        for numero in seleccionados:
            producto *= numero
        productos.append(producto)

    return productos

# Números positivos y negativos
num_positivos = [1, 2, 3, 4, 5, 6, 0]
num_negativos = [-1, -2, -3, -4, -5, -6, -7, -8]

# Número de simulaciones (10 intentos)
intentos_simulacion = 10

# Realizar la simulación
resultados = simulacion_productos(num_positivos, num_negativos, intentos_simulacion)

# Analizar resultados
positivos = sum(1 for producto in resultados if producto > 0)
nulos = sum(1 for producto in resultados if producto == 0)

# Calcular probabilidades empíricas
probabilidad_positivos = positivos / intentos_simulacion
probabilidad_nulos = nulos / intentos_simulacion

# Mostrar resultados
print(f"En {intentos_simulacion} simulaciones:")
print(f"a) El producto fue positivo en {positivos} casos, con una probabilidad empírica de {probabilidad_positivos:.2%}.")
print(f"b) El producto fue nulo en {nulos} casos, con una probabilidad empírica de {probabilidad_nulos:.2%}.")
