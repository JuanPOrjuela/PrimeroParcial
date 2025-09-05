# EXPLICACIÓN Y ANÁLISIS

## Explicación breve de cada programa

### PyImperativo.py
- Implemente un arreglo de estudiantes con `nombre` y `nota`.
- Ordena la lista **in-place** usando un algoritmo imperativo (por ejemplo selection sort o similar).
- Muestra la lista antes y después de ordenar.
- Maneja empates: si las notas son iguales, ordena los nombres alfabéticamente.
- Propósito: mostrar paso a paso cómo muta la estructura de datos y cómo se hacen swaps.

### HsDeclarativo.hs
- Define un tipo `Student` con campos `name` y `grade`.
- Usa `sortBy` y `comparing` para ordenar por `grade`o nota (descendente) y `name` (ascendente en empate).
- No muta la lista original: devuelve una lista nueva ordenada.
- Propósito: mostrar la intención (ordenar por claves) de forma compacta y clara.

### CalculoLambda.hs
- Define `promedio :: [Double] -> Double`.
- Lee una línea con números separados por espacios desde stdin.
- Calcula el promedio usando `promedio = realToFrac (sum xs) / genericLength xs`.
- Incluye la representación en notación lambda:

- Propósito: relacionar la implementación práctica con la notación matemática λ.

### GestionEstudiantes.c
- Define `struct Estudiante` con punteros dinámicos para `nombre`, `apellido` y un array dinámico para `notas`.
- Usa `malloc`, `realloc` y `free` para asignar y liberar memoria justo del tamaño necesario.
- Opcionalmente usa bitfields para campos pequeños (como la edad) si se busca micro-optimización.
- Incluye funciones: crear, imprimir, eliminar y compactar.
- Propósito: mostrar manejo de memoria y optimización básica en C.

---
## # Cómo correr los programas

A continuación, se muestran los pasos para ejecutar los 4 archivos en sus respectivos lenguajes.

### Python (Imperativo)
1. Archivo: `PyImperativo.py`  
2. PS C:\Users\usuario\carpeta> python PyImperativo.py

### Haskell (Declarativo)
1. Archivo: `HsDeclarativo.hs`
2. PS C:\Users\usuario\carpeta> ghci HsDeclarativo
3. ghci> main

### C (Gestion estudiantes)
1. Archivo: `GestionEStudiantes.c`
2. PS C:\Users\usuario\carpeta> gcc main.c -o main

### Haskell (CalculoLambda)
1. Archivo: `CalculoLambda.hs`
2. PS C:\Users\usuario\carpeta> ghci CalculoLambda
3. ghci> main
4. Agregamos los numeros que decidamos separados con un espacio

---

## Análisis comparativo: Imperativo (Python) vs Declarativo (Haskell)

### 1) Claridad y legibilidad
- **Imperativo (Python):**
- Ventaja: el flujo (bucles, swaps) es explícito; fácil de seguir paso a paso.
- Desventaja: el código crece con detalles de implementación; puede tener "ruido" si agregas mediciones u opciones.
- **Declarativo (Haskell):**
- Ventaja: la intención se expresa directamente ( `sortBy (comparing ...)`), menos código para el mismo propósito.
- Desventaja: la abstracción puede costar al principio.

### 2) Nivel de expresividad y abstracción
- **Haskell:** alto; puedes componer funciones y usar librerías que encapsulan algoritmos eficientes.
- **Python:** más bajo en este ejemplo (se implementa el algoritmo manualmente), pero Python tiene librerías (`sorted`) que también son expresivas.

### 3) Manejo de estructuras de datos (mutabilidad vs inmutabilidad)
- **Python (imperativo):** muta la lista in-place. Ahorra copias pero introduce efectos secundarios.
- **Haskell (declarativo):** inmutabilidad por defecto. Se crean nuevas estructuras; evita errores por estado compartido.

### 4) Manejo de estado
- **Imperativo:** el estado cambia durante la ejecución; hay que controlar transiciones y estados intermedios.
- **Declarativo:** el "estado" se pasa como valores; menos riesgo de inconsistencias.

### 5) Facilidad de mantenimiento y extensión
- **Haskell:** alta; cambiar la clave de orden o combinar criterios es simple y seguro.
- **Python:** puede ser más laborioso cambiar la lógica interna si el algoritmo está escrito a mano.

### 6) Eficiencia (algoritmo y lenguaje)
- **Algoritmo usado:**
- Si el Python usa selection sort que es mejor para listas pequeñas.
- `sortBy` en Haskell suele ser mejor para listas grandes.
- **Costo del lenguaje:**
- Python interpretado puede ser lento en bucles intensivos.
- Haskell compilado puede ser más rápido para operaciones en listas grandes si se escribe de forma eficiente.
- **Memoria:**
- Mutación in-place (Python) puede usar menos memoria temporal.
- Inmutabilidad (Haskell) puede usar más memoria temporal, pero permite optimizaciones del compilador y evita errores.

---

## Ventajas y desventajas resumidas 

### Imperativo (Python)
- **Ventajas:** fácil de entender para aprender algoritmos y nos deja controlar todo el proceso.
- **Desventajas:** código más largo, mayor riesgo de errores por mutación, generalmente menos eficiente para muchas entradas si se usan algoritmos.

### Declarativo/Funcional (Haskell)
- **Ventajas:** Código más corto y claro para la intención, uso de algoritmos eficientes menor probabilidad de errores por estado.
- **Desventajas:** Posible uso adicional de memoria por inmutabilidad (aunque el compilador puede optimizar).

---

