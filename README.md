# Task #PC2: Practica Calificada 2  
**course:** Programación III  
**unit:** 2 ,3 y 4  
**cmake project:** prog3_pc2_TEO4_v2024_1
## Instructions
- El tiempo límite para la evaluación es 100 minutos.
- Cada pregunta deberá ser respondida en un archivo cabecera (`.h`):
    - `sort_except.h`
    - `tokenize_concurrently.h`
- Adicionalmente, la **pregunta #2** podrá ser elaborada en el mismo archivo de la **pregunta #1**.
- Deberás subir estos archivos directamente a [www.gradescope.com](https://www.gradescope.com) o se puede crear un `.zip` que contenga todos ellos y subirlo.


## Question #1 - Ordenar con Exclusión (7 points)

Diseñar y desarrollar dos templates de función que permitan ordenar elementos de un contenedor, excluyendo ciertos elementos de la operación de ordenación. Los elementos excluidos deben permanecer en sus posiciones originales.

Los template de función son los siguientes:  
1. **`sort_except`**: Esta función ordena los elementos de un contenedor, excluyendo un valor específico.
2. **`sort_except_if`**: Esta función ordena los elementos de un contenedor, excluyendo aquellos que cumplen con un predicado dado.

Ambas funciones deben recibir dos iteradores (inicio y fin) que definen el rango del contenedor a ordenar.
- **`sort_except`** debe recibir adicionalmente un valor fijo que define los elementos a excluir de la ordenación.
- **`sort_except_if`** debe recibir adicionalmente un predicado que define la condición para excluir elementos de la ordenación.
- Los elementos excluidos deben permanecer en sus posiciones originales dentro del contenedor.

## Caso de Uso: Exclusión de un Valor Fijo
```cpp
  vector<int> vec = {5, 3, 8, 6, 2, 6, 7, 4, 1};
  int exclude_value = 6;
  sort_except(vec.begin(), vec.end(), exclude_value);
  for(const auto& item: vec) {
    cout << item << " ";
  }
  cout << endl;
  return 0;
```
#### Caso de uso #1
Entrada:
```
6
5 3 8 6 2 6 7 4 1
```
Salida:
```
1 2 3 6 4 6 5 7 8
```

#### Caso de uso #2
Entrada:
```
|
pp | mm | aa | ee | ff | yy | gg | vv | dd
```
Salida:
```
aa | dd | ee | ff | gg | mm | pp | vv | yy
```

## Caso de Uso: Exclusión Basada en un Predicado
```cpp
  vector<int> vec = {5, 3, 8, 6, 2, 7, 4, 1};
  auto exclude_pred = [](int x) { return x % 2 == 0; };
  sort_except_if(vec.begin(), vec.end(), exclude_pred);
  for(const auto& item: vec) {
    cout << item << " ";
  }
  cout << endl;
```

#### Caso de uso #3
Entrada:
```
5 3 8 6 2 7 4 1
```
Predicado:
```cpp
  [](int x) { return x % 2 == 0; }
```
Salida:
```
1 3 8 6 2 5 4 7
```  

#### Caso de uso #4
Entrada:
```
platano a manzana b uva c durazno d
```
Predicado:
```cpp
  [](auto a) { return a.size() == 1; }
```
Salida:
```
durazno a manzana b platano c uva d
```
## Question #2 - Complejidad Algoritmica (6 points)
Determinar la función de tiempo y el Big O de la siguiente función:

```cpp
    int funcion(int n) {

        srand(time(0));
        vector<vector<int>> matriz(n, vector<int>(n));
        
        // Llenar la matriz con números aleatorios
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                matriz[i][j] = rand() % 100 + 1;
            }
        }
    
        int resultado = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                vector<int> sorted_row = matriz[i];  // Copiar la fila
                sort(sorted_row.begin(), sorted_row.end());  // Ordenar la fila
                resultado += sorted_row[j];
            }
        }
    
        return resultado;
    }
```

## Question #3 - Tokenización Concurrente de Texto (7 points)

Diseñar y desarrollar un template de función que divida un texto en tokens (palabras), eliminando los caracteres de puntuación y utilizando hilos para mejorar el rendimiento. La función debe procesar el texto en partes usando múltiples hilos y luego combinar los resultados.

- La función debe recibir una cadena de texto como entrada y dividirlo en palabras (tokens), eliminando todos los caracteres de puntuación.
- La función debe utilizar múltiples hilos para procesar diferentes partes del texto en paralelo. Los resultados de cada hilo deben combinarse para formar el resultado final. 
- La función debe manejar adecuadamente los bordes entre las partes procesadas por diferentes hilos para evitar cortar palabras.
- Debe contemplarse que existen diferentes tipos de texto: `const char*`, `std::string`, `std::wstring` por lo que la función debe ser un template. 
 
**NOTA:** Para identificar los caracteres de puntuación utilizar la función: `std::ispunct` o `std::iswpunct`  
(ver: https://en.cppreference.com/w/cpp/string/byte/ispunct)    

#### Caso de Uso: string
```cpp
    std::string text = "Hello, world! This is a test. Let's tokenize this text: efficiently.";
    std::vector<std::string> tokens = tokenize_concurrently(text);

    for (const auto& token : tokens) {
        std::cout << token << "|";
    }
    std::cout << std::endl;
```

#### Caso de Uso: wstring
```cpp
    std::wstring text = L"Hello, world! This is a test. Let's tokenize this text: efficiently.";
    std::vector<std::wstring> tokens = tokenize_concurrently(text);

    for (const auto& token : tokens) {
        std::wcout << token << "|";
    }
    std::cout << std::endl;
```

#### Caso de Uso: const char*
```cpp
    const char* text = "Hello, world! This is a test. Let's tokenize this text: efficiently.";
    std::vector<std::string> tokens = tokenize_concurrently(text);

    for (const auto& token : tokens) {
        std::cout << token << "|";
    }
    std::cout << std::endl;
```

#### Caso de uso #1
Entrada:  
```
Hello, world! This is a test. Let's tokenize this text: efficiently.
```

Salida:
```
Hello|world|This|is|a|test|Lets|tokenize|this|text|efficiently|
```
