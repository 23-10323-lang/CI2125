# Ejercicios de algebra relacional


## Esquema


FUENTE_SODA(<u>Cod_FS</u>,NombreFS)\
BEBEDOR(<u>CI</u>,Nombre)\
FRECUENTA(<u>CI</u>,<u>Cod_FS</u>)\
BEBIDA(<u>Cod_B</u>,NombreBeb)\
GUSTA(<u>CI</u>,<u>Cod_Beb</u>)\
VENDE(<u>Cod_FS</u>,<u>Cod_Beb</u>,precio)


GUSTA(26986341,CA2555)\
GUSTA(26986341,CF2632)


## Ejercicio 1

La suma de los precios de las bebidas que le gustan a Juan perez en la Fuente de Soda CA2555.


$$
\begin{align*}
juanPerez &:= filter(BEBEDOR,Nombre="Juan\ Perez")\\
bebidasGustanJP &:= juanPerez \ltimes_{CI} GUSTA\\
fs &:= filter(VENDE,Cod\_FS="CA2555")\\
x &:= bebidasGustanJP \ltimes_{Cod\_Beb} fs\\
suma &:= SUMA(x,precio)
\end{align*}
$$


## Ejercicio 2

Cuales son las fuentes de soda que son mas frecuentadas.


FUENTE SODA(CA2555,"hsdjhfd")

FUENTE SODA(CF2632,"sdfhsdf")

FRECUENTA(26986341,CA2555)

FRECUENTA(34567890,CA2555)

FRECUENTA(12345678,CF2632)

FUENTE SODA(CA2555,"hsdjhfd") ->  FRECUENTA(26986341,CA2555), FRECUENTA(34567890,CA2555)


FUENTE SODA(CF2632,"sdfhsdf") -> FRECUENTA(12345678,CF2632)



FUENTE SODA(CA2555,"hsdjhfd",2)


FUENTE SODA(CF2632,"sdfhsdf",1)


$$
\begin{align*}
fsE & := WITH(FUENTE\_SODA, COUNT(filter(FRECUENTA,Cod\_FS = fs.Cod\_FS) ))\\
top & := order\_desc(fsE)
\end{align*}
$$

## Ejercicio 3

Precio promedio de las bebidas que NO le gustan a Juan Perez.

pr(Tabla, columnas)

$T_1 \times T_2$

filter(Tabla,pred)

$T_1 \ltimes_{k} T_2$

SUMA,COUNT,...

ORDENAR,TOP(n), BOTTOM(n)


$$
\begin{align*}
jp &:= filter(BEBEDOR, Nombre="Juan \ Perez")\\
bgjp &:=  jp \ltimes_{CI} GUSTA\\
bngjp &:= filter(BEBIDAS, COD\_FS \ NOT\ IN\  bgjp)\\
res &:= AVG(bngjp \ltimes_{COD\_BEB} VENDE,PRECIO)
\end{align*}
$$

# Ejercicio 4

Los bebedores que frecuentan fuentes de soda que venden AL MENOS 1 bebida que les gusta.

juan perez FRECUENTA las fs CA2555 (vende Frescolita), CF2666 (Pepsi), CG2798 (Pepsi Malta).

juan perez GUSTA Cocola.

[]

$$
\begin{align*}
\end{align*}
$$



$$
\begin{align*}
\end{align*}
$$
