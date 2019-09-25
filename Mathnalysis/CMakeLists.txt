# CMakeList.txt: proyecto de CMake para Mathnalysis, incluya el origen y defina
# la lógica específica del proyecto aquí.
#
cmake_minimum_required (VERSION 3.8)

# Agregue un origen al ejecutable de este proyecto.
add_executable (Mathnalysis "PuntoFijo.cpp" "PuntoFijo.h" "biseccion.cpp" "busqueda_incrementa.cpp" "secante.cpp" "reglaFalsa.cpp" "raices_multiples.cpp" "raices_multiples.h" "Mathnalysis.cpp" "Mathnalysis.h" )

# TODO: Agregue pruebas y destinos de instalación si es necesario.
