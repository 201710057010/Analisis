#include <exception>

/**
* Excepsion para cuando se supere el numero total de iteraciones
*/

struct TooMuchIterException : public std::exception {
	const char* what() const noexcept override {
		return "No se pudo Encontrar la raiz con la cantidad de iteraciones pedido";
	}
};

/**
* Excepsion para cuando el intervalo no sea valido
*/

struct BadIntervalException : public std::exception {

	const char* what() const noexcept  override{
		return "Intervalo invalido, por favor inserte otro";
	}
};

/**
* Excepsion para cuando la derivada es 0
*/

struct Derived0Exception : public std::exception {

	const char* what() const noexcept override {
		return "Derivada igual a 0";
	}
};

/**
* Excepsion para cuando se intenta dividir por 0
*/

struct div0Exception : public std::exception {

	const char* what() const noexcept override{
		return "Se intento divir por 0";
	}
};