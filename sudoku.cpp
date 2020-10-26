/*
 * sudoku.cpp
 * 
 * Copyright 2020 fjp <fjp@fjp-virtualbox>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <iostream>
#include "sudoku.h"


void imprime(celda datos[9][9]);
bool compruebaFila(int fila, int columna, celda datos[9][9]);
bool compruebaColumna(int fila, int columna, celda datos[9][9]);
bool compruebaCuadrado(int fila, int columna, celda datos[9][9]);
void compruebaCandidato(celda datos[9][9]);
bool esSolucion(celda datos[9][9]);

int main()
{
	int datos[9][9]={{0,7,0,0,0,0,4,8,0},
					 {0,0,8,0,5,0,0,0,3},
					 {0,3,0,7,8,0,0,0,0},
					 {9,0,0,0,0,7,0,4,2},
					 {5,0,0,1,0,6,0,0,7},
					 {8,4,0,5,0,0,0,0,1},
					 {0,0,0,0,1,4,0,6,0},
					 {3,0,0,0,6,0,2,0,0},
					 {0,8,6,0,0,0,0,1,0}};
	celda sudoku[9][9];
	bool cambio=false;  //variable para comprobar si en cada iteración de resolución se ha conseguido al menos solucionar una casilla
	bool solucion=false;
	//inicializamos la matriz de celdas
	for (int i=0;i<9;i++){
		for (int j=0;j<9;j++){
			if (datos[i][j]!=0){
				sudoku[i][j].setValor(datos[i][j]);
				for (int k=1;k<=9; k++){
					if (k!=datos[i][j])
						sudoku[i][j].eliminaCandidato(k);
					}
				}
		}
	}
//mientras haya alguna celda que cambie su valor o el sudoku no esta resuelto
	while ( cambio || !esSolucion(sudoku){   
		for (int i=0;i<9;i++){
			for (int j=0;j<9;j++){
				//aplicacion de las reglas basicas
				cambio=false;
				cambio=compruebaFila(i,j,sudoku);
				compruebaCandidato(sudoku);
				cambio=compruebaColumna(i,j,sudoku);
				compruebaCandidato(sudoku);
				cambio=compruebaCuadrado(i,j,sudoku);
				compruebaCandidato(sudoku);
			}
		imprime(sudoku);
		return 0;
		}
	}
}	


void imprime(celda datos[9][9]){
	//funcion para imprimir el estado de un sudoku
	for (int i=0;i<9;i++){
			for (int j=0;j<9;j++){
				std::cout << datos[i][j].getValor() << " -> candidatos: ";
				for(int k=0;k<9;k++){
					if (datos[i][j].getCandidatos()[k] != 0)
						std::cout << datos[i][j].getCandidatos()[k] << " " ;
					}
					std::cout << std::endl;
				}
			}
}


bool compruebaFila(int fila, int col, celda datos[9][9]){
	//funcion que comprueba los valores en la fila y elimina los números de la lista de candidatos
	bool testigo=false;
	for (int j=0;j<9;j++){
		if (col!=j){
			//no comprobamos la misma celda
			if (datos[fila][j].getValor() != 0)
				if (datos[fila][col].getCandidatos()[datos[fila][j].getValor()]!=0){ //si ese valor está en la lista de candidatos
						datos[fila][col].eliminaCandidato(datos[fila][j].getValor());  //lo eliminamos de la lista de candidatos
						testigo=true;
					}
			}
			
	}
	return testigo;
}
bool compruebaColumna(int fila, int col, celda datos[9][9]){
	//funcion que comprueba los valores en la columna y elimina los números de la lista de candidatos
	bool testigo=false;
	for (int i=0;i<9;i++){
		if (fila!=i){
			//no comprobamos la misma celda
			if (datos[i][col].getValor() != 0)
				if (datos[fila][col].getCandidatos()[datos[i][col].getValor()]!=0){ //si ese valor está en la lista de candidatos
						datos[fila][col].eliminaCandidato(datos[i][col].getValor());  //lo eliminamos de la lista de candidatos
						testigo=true;
					}
			}
			
	}
	return testigo;
}

bool compruebaCuadrado(int fila, int col, celda datos[9][9]){
	//funcion que comprueba los valores del cuadrado al que pertenece una celda
}

void compruebaCandidato(celda datos[9][9]){
	//comprueba si las celdas que tienen un unico candidato no tienen el valor 0
	for (int i=0;i<9;i++{
		for (int j=0;j<9;j++){
			if (datos[i][j].getValor()==0){
				int lista[9]=datos.getCandidatos();
				int k=0, contador=0;
				while(contador < 1 || k <9){
					if (k==9 && contador
		}
	}
}

bool esSolucion(celda datos[9][9]){
	//funcion que comprueba si el sudoku está resuelto
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			if datos[i][j].getValor()==0
				return False;
			}
		}
	return True;
}

