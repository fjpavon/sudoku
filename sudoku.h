//fichero de libreria
#include <iostream>


class celda{
	int valor=0;
	int candidatos[9]={1,2,3,4,5,6,7,8,9};
	
	public:
		int getValor(void);
		void setValor(int);
		void eliminaCandidato(int);
		int* getCandidatos(void);
		int getTamano(void);
};

int celda::getValor(void){
	//método que devuelve el valor de la celda
	return celda::valor;
}

void celda::setValor(int numero){
	//método que asigna un valor a la celda
	celda::valor=numero;
}

void celda::eliminaCandidato(int numero){
	//método que elimina el numero de la lista de candidatos de la celda
	if (numero<1 || numero>9)
		std::cout << "Se ha intentado eliminar un candidato con valor no válido" << std::endl;
	else {
		if (celda::candidatos[numero-1]!=0)
			celda::candidatos[numero-1]=0;
	}
}

int* celda::getCandidatos(void){
	//funcion que devuelve la lista de valores candidatos de la celda
	return celda::candidatos;
}

int celda::getTamano(void){
	//funcion que devulve el tamaño de la lisa de candidatos
	int contador=0;
	for (int i=0;i<9;i++){
		if (celda::candidatos[i]!=0)
			contador++;
	}
	return contador;
}
			
