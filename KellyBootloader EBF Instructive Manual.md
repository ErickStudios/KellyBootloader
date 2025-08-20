# Manual de implementacion de ErickBinaryFormat y de ErickAssembly desde un punto de vista entendible

en este md (o pdf si logre hacerlo como queria) veremos como implementar tu propio ErickBinaryFormat , sin copiar el .h

## lenguaje

usen la libreria `gnu-efi` para su implementacion, usen C sin C++ y compatible con `gnu-efi`

## RAM

la ram en ErickBinaryFormat por dentro no es mas que un array de tipo `short` con 2000000 items (lo que equivale a 4 megas de ram), a este en el documento lo llamaremos `MemoryAccess`

fuera de eso hay otra variable con el tipo `long long` el cual es usado para manejar punteros mas grandes que el limite de 16 bits que tiene cada slot individual, a este `long long` en el documento lo llamaremos `CukysCukysPtr`

(cabe aclarar que en su codigo le puden poner cualquier nombre, mientras entiendan como funciona, ponganle el nombre que quieran)

### Variables

esto se hace solo, solo necesitas manejar un slot

### Pools (o arrays)

esto ya es un poco compilacado

primero , los pools estan conformados por una variable principal y varias variables que les siguen, la variable principal contiene el tamaño del pool (cuantos slots de memoria mide) y las otras variables contienen la informacion

supongamos que un pool esta ubicado en la pocision 40000 y tiene 5 elementos [ 1, 5, 2, 7, 3 ] en el editor de memoria se veria asi
```console
HexMemoryEditor for ErickBinaryFromat

0000 0000 0000 0000 0000 0000 0000 0000
0000 0000 0000 0000 0000 0000 0000 0000
0000 0000 0000 0000 0000 0000 0000 0000
0000 0000 0000 0000 0000 0000 0000 0000
0000 0000 0000 0000 0000 0000 0000 0000
0000 0000 0000 0000 0000 0000 0000 0000
0000 0000 0000 0000 0000 0000 0000 0000
0000 0000 0000 0000 0000 0000 0000 0000
0000 0000 0000 0000 0000 0000 0000 0000
0000 0000 0000 0000 0000 0000 0000 0000
0000 0000 0000 0000 0000 0000 0000 0000
0000 0000 0000 0000 0000 0000 0000 0000
0000 0000 0000 0000 0000 0000 0000 0000
0000 0000 0000 0000 0000 0000 0000 0000
0000 0000 0000 0000 0000 0000 0000 0000
0000 0000 0000 0000 0000 0000 0000 0000
0000 0000 0000 0000 0000 0000 0000 0000
0000 0000 0000 0000 0000 0000 0000 0000
0000 0000 0000 0000 0000 0000 0000 0000
0005 0001 0005 0002 0007 0003 0000 0000
ps: 39848, sc: 4981, reg: 249
G=go Arrows=P^Pv=Pag <]=Sel
```

cada funcion que cree un pool debera retornar la direccion de la variable primaria (la que esta antes del primer elemento que contiene la longitud)

tambien tiene que haber una funcion que libere el pool y sobreescriba todos sus datos con 0 para que al crear uno nuevo se sobreescriba bien y no quede ningun pool suelto

aparte no pueden existir pools que empiezen antes de el slot 2001 ni despues de el slot 4999 de `MemoryAccess`

## parte logica

para la parte de instrucciones logicas la tabla de los opcodes es algo asi

algunas instrucciones no estan por que estan en desuso pero aun asi manten los opcodes exactos en esta tabla para que sea compatible tu implementacion

| instruccion | Codigo de operacion | Resumen |
|:--------|------:|:--------:|
| mover | 1   | mueve un valor literal a una variable |
| sumar | 2   | le suma a una variable el valor de otra variable |
| restar | 3   | le resta a una variable el valor de otra variable |
| dividir | 4   | divide una variable con valor de otra variable |
| multiplicar | 5   | multiplica el valor de una variable con valor de otra variable |
| incrementar | 6   | incrementa el valor de una variable en 1 |
| decrementar | 7   | decrementa el valor de una variable en 1 |
| saltar | 8   | salta a una funcion conservando el program counter , para usarlo en una instruccion de retorno |
| regresar | 9   | regresa a un punto anterior despues de un salto |
| declarar funcion | 10   | no tiene utilidad real ni hace nada interesante, solo le indica a una instruccion de salto que ahi hay una funcion y si coincide el numero de la funcion salta a esa funcion |
| llamada de ayuda | 11   | hace una accion del sistema, la tabla de lo que hace cada accion se mencionara luego en otra seccion del documento |
| saltar si son iguales | 12 | hace lo mismo que el salto pero solo salta si el slot `256` de memoria tiene como valor 1
| saltar no son iguales | 15 | hace lo mismo que el salto pero solo salta si el slot `256` de memoria tiene como valor 0
| asignar una variable con el valor de otra variable | 18 | hace eso
| trabajar con punteros | 19 | cuando una instruccion detecta que la instruccion anterior la instruccion 19 entonces fuerza al valor 1 a que en vez de ser un valor literal el valor 1 cuando se pasa una instruccion con el parametro 1 tendra que ser forzada a que en vez de por ejemplo utilizar como valor `43` usar el valor de el slot `43` del array de memoria,`MemoryAccess`

todo lo que no sea instrucciones al caracter original se le suma 22 (por ejemplo , si un parametro de una instruccion es 65 en tiempo de compilacion se convierte a 87) y al tiempo de ejecucion se le resta a los parametros 22 asi `87` se restaura a `65`

al ejecutar un programa EBF tiene que empezar con los dos caracteres del magic (`EA` o `MP`) y el caracter 3 debe ser el caracter ascii con el codigo 3 para que se considere un binario de ErickBinaryFormat, el encabezado despues de comprobarlo se debe saltar y pasar con lo que sigue (las instrucciones del programa)

## tabla de colores esperada

negro
numero: 1

negro claro
numero: 2

gris oscuro
numero: 3

gris
numero: 4

gris claro
numero: 5

blanco
numero: 6

rojo oscuro
numero: 7

rojo
numero: 8

rojo brillante
numero: 9

naranja oscuro
numero: 10

naranja
numero: 11

naranja brillante
numero: 12

amarillo oscuro
numero: 13

amarillo
numero: 14

amarillo brillante
numero: 15

verde oscuro
numero: 16

verde
numero: 17

verde brillante
numero: 18

cian oscuro
numero: 19

cian
numero: 20

cian brillante
numero: 21

teal oscuro
numero: 22

teal
numero: 23

teal brillante
numero: 24

azul oscuro
numero: 25

azul
numero: 26

azul brillante
numero: 27

cualquier otra entrada invalida de color se le asigna el color gris

## llamadas al sistema

todas las llamadas tienen reservado el `param 1` para el numero de la llamada y el `param 2` lo usan algunas llamadas para hacer cosas mas interesantes y dinamicas

| Nombre de la llamada | Numero de representacion | Resumen |
|:--------|------:|:--------:|
| Imprimir caracter | 1   | Imprime el valor del slot de `MemoryAccess` al que apunta el `param 2` de la instruccion como un caracter unicod |
| Limpiar pantalla | 2   | Limpia la pantalla |
| cambiar el fg | 3   | cambia el color de texto de la consola con la tabla de colores esperados |
| cambiar el bg | 4   | cambia el color del fondo de la consola con la tabla de colores esperados |
| ajustar posicion x | 5 | cambia el valor de la posicion del cursor de la consola en x con el valor del slot de `MemoryAccess` al que apunta el `param 2` de la instruccion |
| ajustar posicion y | 7 | cambia el valor de la posicion del cursor de la consola en y con el valor del slot de `MemoryAccess` al que apunta el `param 2` de la instruccion |
| Imprimir caracter sin actualizar la pantalla | 8   | Imprime el valor del slot de `MemoryAccess` al que apunta el `param 2` de la instruccion como un caracter unicode pero sin actualizar la pantalla |
| dibujar la pantalla manualmente | 9 | dibuja la pantalla manualmente |
| esperar | 10 | espera una cantidad de microsegundos, esa cantidad es el valor del slot de `MemoryAccess` al que apunta el `param 2` de la instruccion |
| esperar hasta que se presione una tecla | 11 | espera hasta que se presione una tecla |
| leer una tecla | 12 | redirije el codigo de escaneo de la tecla a la variable a la que apunta el `param 2` de la instruccion y el caracter unicode lo guarda en la direccion de memoria a la que apunta el `param 2` sumada por 1 |
| obtener la fecha | 13 | direccion `param 2` = segundo, direccion `param 2`+1 = minuto, direccion `param 2`+2 = hora, direccion `param 2`+3 = dia, direccion `param 2`+4 = semana, direccion `param 2`+5 = mes, direccion `param 2`+6 = año |
| crear un pool | 14 | toma la direccion a la que apunta `param 2`+1 como el tamaño y retorna la posicion del pool creado en la variable a la que apunta `param 2` |
| editar un valor de un pool | 16 | direccion `param 2` = el pool, direccion `param 2`+1 el item que se quiere editar (el primer item es 0), direccion `param 2`+3 = el nuevo valor|
| obtener un valor de un pool | 17 | direccion `param 2` = el pool, direccion `param 2`+1 el item que se quiere editar (el primer item es 0), direccion `param 2`+3 = donde el valor se retornara|
| Imprimir numero sin actualizar la pantalla | 18   | Imprime el valor del slot de `MemoryAccess` al que apunta el `param 2` de la instruccion como un numero pero sin actualizar la pantalla |
| Imprimir numero hexadecimal sin actualizar la pantalla | 19   | Imprime el valor del slot de `MemoryAccess` al que apunta el `param 2` de la instruccion como un numero hexadecimal pero sin actualizar la pantalla |
| liberar pool | 20 | libera un pool, el pool se supone que esta en la direccion a la que apunta el valor de la variable al que apunta el `param 2` de la instruccion |
| imprimir pool | 22 | imprime un pool, el pool se supone que esta en la direccion a la que apunta el valor de la variable al que apunta el `param 2` de la instruccion |
| leer linea | 23 | le pide al usuario ingresar cualquier texto y despues el texto se localiza en un pool y la direccion del pool es retornada a la variable a la que apunta el `param 2` de la instruccion |
| comparar pools | 24 | compara el pool 1 con el pool 2, el pool 1 se supone que esta en la direccion a la que apunta el valor de la variable al que apunta el `param 2` de la instruccion , el pool 2 se supone que esta en la direccion a la que apunta el valor de la variable al que apunta el `param 2`+1 de la instruccion, la llamada retorna 1 si es igual y 0 si no lo son en el slot `256` de `MemoryAccess` |
| apagar | 27 | apaga la pc |
| reiniciar | 28 | reinicia la pc |
| cambiar fg personalizado | 29 | cambia el fg con un color personalizado, direccion `param 2` = red, direccion `param 2`+1 = green, direccion `param 2`+2 = blue |

hay otras llamadas pero te recomiendo ver el codigo de ErickBinaryFormat.h en el repositorio de github de KellyBootloader por que estoy muy cansado de nombrar todas

