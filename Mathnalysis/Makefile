all: Mathnalysis

Mathnalysis: Mathnalysis.o EcuacionesUnaVariable/PuntoFijo.o EcuacionesUnaVariable/raices_multiples.o EcuacionesUnaVariable/biseccion.o EcuacionesUnaVariable/busqueda_incrementa.o EcuacionesUnaVariable/newton.o EcuacionesUnaVariable/reglaFalsa.o EcuacionesUnaVariable/secante.o VariasVariables/gaussSeidel.o VariasVariables/crout.o
			g++ -o $@ $^

Mathnalysis.o: Mathnalysis.cpp Mathnalysis.h exceptions.h EcuacionesUnaVariable/PuntoFijo.h EcuacionesUnaVariable/raices_multiples.h EcuacionesUnaVariable/biseccion.h EcuacionesUnaVariable/busqueda_incrementa.h EcuacionesUnaVariable/newton.h EcuacionesUnaVariable/reglaFalsa.h EcuacionesUnaVariable/secante.h VariasVariables/gaussSeidel.h VariasVariables/crout.h

EcuacionesUnaVariable/PuntoFijo.o:  EcuacionesUnaVariable/PuntoFijo.cpp EcuacionesUnaVariable/PuntoFijo.h

EcuacionesUnaVariable/raices_multiples.o: EcuacionesUnaVariable/raices_multiples.cpp EcuacionesUnaVariable/raices_multiples.h

EcuacionesUnaVariable/biseccion.o: EcuacionesUnaVariable/biseccion.cpp EcuacionesUnaVariable/biseccion.h

EcuacionesUnaVariable/busqueda_incrementa.o: EcuacionesUnaVariable/busqueda_incrementa.cpp EcuacionesUnaVariable/busqueda_incrementa.h

EcuacionesUnaVariable/newton.o: EcuacionesUnaVariable/newton.cpp EcuacionesUnaVariable/newton.h

EcuacionesUnaVariable/reglaFalsa.o: EcuacionesUnaVariable/reglaFalsa.cpp EcuacionesUnaVariable/reglaFalsa.h

EcuacionesUnaVariable/secante.o: EcuacionesUnaVariable/secante.cpp EcuacionesUnaVariable/secante.h

VariasVariables/gaussSeidel.o: VariasVariables/gaussSeidel.cpp VariasVariables/gaussSeidel.h

VariasVariables/crout.o: VariasVariables/crout.cpp VariasVariables/crout.h

clean:
		rm -f *.o
		rm -f *.*~
		rm -f Mathnalysis
