<div align="center">
  <img src="https://raw.githubusercontent.com/15Galan/42_project-readmes/refs/heads/master/banners/cursus/projects/get_next_line-light.png" />
  <img src="https://img.shields.io/badge/status-finished-darkgreen" />
  <img src="https://img.shields.io/badge/score-125-darkblue" /><br/> 
   <a href="/README-en.md">English<a> · <b>Español</b>
</div> 

---

# Introducción

El proyecto **get_next_line** consiste en implementar una función en C capaz de leer y devolver una línea completa de un archivo, manejando la lectura de manera eficiente. Este proyecto es parte del programa de 42 School y es fundamental para desarrollar habilidades en la manipulación de archivos y el manejo de memoria dinámica.

Este es el [subject](es.subject.pdf) del proyecto.

---

## 📋 Tabla de Contenidos

- 📖 [Descripción](#descripción)
- ⚙️ [Requisitos](#requisitos)
- 🛠️ [Instalación](#instalación)
- 🚀 [Uso](#uso)
- 📚 [Especificaciones del Proyecto](#especificaciones-del-proyecto)
- ✅ [Tests](#tests)
- 🌐 [Recursos](#recursos)
- 📜 [Licencia](#licencia)

---

## 📖 Descripción

La función `get_next_line` permite leer un archivo línea por línea, sin importar el tamaño de las líneas o el archivo. Para lograr esto, el proyecto utiliza un búfer que puede ajustarse según las necesidades del usuario.

El principal desafío del proyecto es manejar eficientemente la lectura de archivos, la memoria dinámica y los escenarios especiales, como archivos vacíos, líneas largas o múltiples llamadas a la función.

---

## ⚙️ Requisitos

- **Lenguaje:** C  
- **Normas:** La función debe cumplir con la Norminette (estilo de código de 42).  
- **Compilador:** `gcc` con las flags `-Wall -Wextra -Werror`.  
- **Headers:** Se debe usar únicamente la biblioteca estándar de C (`unistd.h`, `stdlib.h`, `fcntl.h`).  

---

## 🛠️ Instalación

1. Clona este repositorio en tu máquina local:
   ```bash
   git clone https://github.com/tu_usuario/get_next_line.git
   cd get_next_line
   ```

2. Compila los archivos de la función:
   ```bash
   gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o gnl
   ```

3. Cambia el valor de `BUFFER_SIZE` según tus necesidades:
   - Este define el tamaño del búfer utilizado para leer del archivo.

---

## 🚀 Uso

Puedes incluir la función en cualquier proyecto o probarla con un archivo de texto:

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd = open("archivo.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
```

Compila y ejecuta tu programa:
```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c -o gnl
./gnl
```

---

## 📚 Especificaciones del Proyecto

- La función debe devolver una línea completa, incluido el salto de línea (`\n`), excepto si se alcanza el final del archivo.
- **Prototipo de la función:**
  ```c
  char *get_next_line(int fd);
  ```
- **Parámetros:**
  - `fd`: Descriptor del archivo a leer.
- **Comportamiento esperado:**
  - Devuelve una línea del archivo especificado por `fd`.
  - Si se alcanza el final del archivo, devuelve `NULL`.

### Archivos del Proyecto:
1. `get_next_line.c` - Implementación principal de la función.
2. `get_next_line_utils.c` - Funciones auxiliares necesarias para la implementación.
3. `get_next_line.h` - Archivo de cabecera con los prototipos y macros.

---

## ✅ Tests

Para probar tu implementación, puedes usar testers comunitarios o crear tus propios casos de prueba.

### Testers recomendados:
- [42Testers-GNL](https://github.com/Mazoise/42TESTERS-GNL)  
- [gnl-war-machine](https://github.com/Tripouille/gnl-war-machine)  
- [gnlkiller](https://github.com/DontBreakAlex/gnlkiller)  

### Casos de prueba básicos:
1. Archivo con múltiples líneas.
2. Archivo vacío.
3. Archivo con una única línea muy larga.
4. Llamadas consecutivas a `get_next_line` con el mismo descriptor.

---

## 🌐 Recursos

- [Man page de read()](https://man7.org/linux/man-pages/man2/read.2.html)  
- [Guía de manejo de archivos en C](https://www.gnu.org/software/libc/manual/html_node/I_002fO-on-Streams.html)  
- [Explicación de memoria dinámica en C](https://www.geeksforgeeks.org/dynamic-memory-allocation-in-c-using-malloc-calloc-free-and-realloc/)  
