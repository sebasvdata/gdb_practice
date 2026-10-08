# Practica de GDB

## Antes de empezar

Las practicas estan basadas en ejercicios que aparecen en
[exam_rank_02](https://github.com/Univers42/Examen42/tree/main/exam_rank_02).
Los fuentes de este directorio son implementaciones independientes con errores
intencionados; no son copias de los fuentes del repositorio. Cada una incluye un
`main` para poder compilarla y depurarla por separado.

Compila con informacion de depuracion y sin optimizaciones:

```sh
gcc -Wall -Wextra -g -O0 ejercicios/level_1/ft_swap.c -o /tmp/ft_swap
gcc -Wall -Wextra -g -O0 ejercicios/level_1/ft_strcpy.c -o /tmp/ft_strcpy
gcc -Wall -Wextra -g -O0 ejercicios/level_2/ft_strrev.c -o /tmp/ft_strrev
gcc -Wall -Wextra -g -O0 ejercicios/level_2/last_word.c -o /tmp/last_word
gcc -Wall -Wextra -g -O0 ejercicios/level_2/max.c -o /tmp/max
gcc -Wall -Wextra -g -O0 ejercicios/level_3/lcm.c -o /tmp/lcm
```

`-g` anade simbolos que GDB usa para mostrar codigo y variables. `-O0` evita
optimizaciones que pueden complicar el seguimiento paso a paso.

## Flujo basico

```sh
gdb /tmp/ft_swap
```

Dentro de GDB:

```text
(gdb) run
(gdb) bt
(gdb) quit
```

`run` inicia (o reinicia) el programa. Si el programa espera argumentos, pasalos
despues de `run`, por ejemplo `run "hola mundo"`. `bt` muestra la pila de
llamadas, util cuando el programa se detiene por un fallo. `quit` sale de GDB.

## TUI: Terminal User Interface (interfaz de texto)

Activa la interfaz TUI dentro de GDB:

```text
(gdb) tui enable
```

Tambien puedes alternar la TUI con `Ctrl+x` y despues `a`.
Con `Ctrl+x` y despues `o` cambias el panel activo. `Ctrl+l` redibuja la
pantalla si se desordena.

## Breakpoints

Un breakpoint detiene el programa antes de ejecutar una linea o al entrar en
una funcion:

```text
(gdb) b 5
(gdb) break main
(gdb) break ft_swap
(gdb) break ejercicios/level_1/ft_swap.c:5
(gdb) info breakpoints
(gdb) run
```

Cuando el programa se detiene:

- `next` ejecuta la siguiente linea sin entrar en funciones.
- `step` ejecuta la siguiente linea y entra en la funcion llamada.
- `continue` continua hasta el siguiente breakpoint o el final.
- `finish` continua hasta salir de la funcion actual.
- `delete 1` elimina el breakpoint numero 1; `disable 1` lo desactiva sin
  eliminarlo.
- `break archivo.c:linea if condicion` crea un breakpoint condicional.

## Inspeccionar valores: `print` y `display`

`print` evalua una expresion una vez, en el punto actual:

```text
(gdb) print i
(gdb) print *a
(gdb) print &valor
(gdb) print arreglo[2]
```

`display` vuelve a mostrar la expresion cada vez que GDB se detiene:

```text
(gdb) display i
(gdb) display arreglo[i]
(gdb) info display
(gdb) undisplay 1
```

Las expresiones se evaluan respecto al estado del programa detenido. Si una
variable sale del ambito, GDB ya no podra mostrarla.

## Cambiar valores: `set`

Para probar que pasaria con otro valor sin recompilar, detente dentro de una
funcion y cambia una variable del programa:

```text
(gdb) set var i = 0
(gdb) print i
```

Esto modifica el estado del proceso depurado y puede alterar su resultado. Para
guardar un calculo temporal de GDB sin modificar una variable del programa,
usa una variable de conveniencia:

```text
(gdb) set $anterior = i
(gdb) print $anterior
```

`set` tambien cambia opciones del depurador, por ejemplo
`set print pretty on`; eso no modifica las variables del programa.

## Ejercicios

En cada caso, compila el fuente con el comando de la seccion inicial, inicia
GDB, coloca breakpoints y usa `print`/`display` para encontrar el error antes
de cambiar el codigo. Intenta describir la causa antes de editar.

### Nivel 1: `ft_swap`

Fuente: [ft_swap.c](ejercicios/level_1/ft_swap.c). La funcion debe intercambiar
dos enteros. El caso de prueba empieza con `a = 3` y `b = 7`; el resultado
esperado es `a = 7`, `b = 3`.

Prueba `break ft_swap`, `run`, `print *a`, `print *b` y avanza con `next`.
Observa los valores despues de cada asignacion.

### Nivel 1: `ft_strcpy`

Fuente: [ft_strcpy.c](ejercicios/level_1/ft_strcpy.c). La funcion debe copiar la
cadena de origen completa, incluido el terminador nulo. El destino se inicializa
con puntos para que puedas ver que bytes no se copiaron.

Prueba `break ft_strcpy`, `run`, `display i`, `print src[i]` y avanza hasta
llegar al final de la cadena.

### Nivel 2: `ft_strrev`

Fuente: [ft_strrev.c](ejercicios/level_2/ft_strrev.c). La funcion debe invertir
la cadena en el mismo buffer. El caso de prueba tiene longitud par para que se
pueda observar el comportamiento de los indices de los extremos.

Prueba `break ft_strrev`, `run`, `display left`, `display right` y
`print text[left]`.

### Nivel 2: `last_word`

Fuente: [last_word.c](ejercicios/level_2/last_word.c). El programa recibe una
cadena y debe imprimir su ultima palabra seguida de un salto de linea. Pruebalo
con:

```sh
/tmp/last_word "hola mundo"
/tmp/last_word "hola mundo   "
```

En GDB puedes iniciar la segunda prueba con `run "hola mundo   "`. Inspecciona
los indices que marcan el inicio y el final de la palabra, y sigue el bucle que
imprime sus caracteres.

### Nivel 2: `max`

Fuente: [max.c](ejercicios/level_2/max.c). La funcion debe devolver el mayor
elemento del array, tambien cuando todos los elementos son negativos. Pon un
breakpoint en `max`, inspecciona `best`, `i` y `tab[i]`, y sigue la condicion
del bucle.

### Nivel 3: `lcm`

Fuente: [lcm.c](ejercicios/level_3/lcm.c). El programa debe calcular el minimo
comun multiplo de 12 y 18; el resultado esperado es 36. Pon breakpoints en
`gcd` y `lcm`, y observa los valores de sus parametros y variables locales con
`display`.

## Rutina sugerida

1. Compila una sola practica y arranca GDB.
2. Activa TUI, coloca un breakpoint en la funcion y ejecuta el caso de prueba.
3. Usa `display` para vigilar indices/valores; usa `next` o `step` para seguir
   el flujo.
4. Usa `print` para comprobar una expresion puntual y `set var` para probar una
   hipotesis.
5. Anota la linea y la razon del error. Corrige el fuente y vuelve a compilar
   para confirmar el resultado esperado.
