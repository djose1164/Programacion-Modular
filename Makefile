cc = GCC

program: compra.c contabilidad.c inventario.c venta.c main.c
	cc compra.c contabilidad.c inventario.c venta.c main.c -o main -Wall

clean:
	$RM (program)