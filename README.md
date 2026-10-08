# Practica de GDB

Seis programas C para depurar errores intencionados con GDB. Los ejercicios
corresponden a nombres presentes en
[exam_rank_02](https://github.com/Univers42/Examen42/tree/main/exam_rank_02);
los `main` incluidos solo sirven para probar cada funcion de forma aislada.

Empieza por [GUIA_GDB.md](GUIA_GDB.md). Compila cada practica desde este
directorio, por ejemplo:

```sh
gcc -Wall -Wextra -g -O0 ejercicios/level_1/ft_swap.c -o /tmp/ft_swap
gdb /tmp/ft_swap
```

No se incluyen binarios ni soluciones. Cada programa imprime un caso de prueba
para que puedas comparar el resultado observado con el esperado descrito en la
guia.
