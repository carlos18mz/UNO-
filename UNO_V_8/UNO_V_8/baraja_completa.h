#pragma once
#include <stdlib.h>
#include "conio.h"
#include "time.h"
#include "iostream"
#include "cartas.h"
#include "vector"
#include "Baraja_aux.h"

using namespace System;
using namespace std;

class baraja
{
public:
	int carta_mesa_eleccion;
	unsigned int b, b1;
private:

	vector <cartas*> baraja_cartas; //primera creacion de la baraja
	vector <cartas*> baraja_cartas_final;//el arreglo con el que incia y juega 
	vector <cartas*> baraja_auxiliar;//para barajear el juego de cartas
	cartas* objcarta;
	baraja* obj_baraja;
	bool nb = true;

public:
	baraja()
	{
		if (nb == true)
		{
			baraja_cartas = vector <cartas*>();
			for (int n = 0; n <= 14; n++)
			{
				for (int c = 0; c <= 3; c++)
				{
					if (n == 10)//numero 10
					{
						objcarta = new cartas;
						objcarta->Setcartas(n, c, 1);
						baraja_cartas.push_back(objcarta);
						objcarta->Setcartas(n, c, 1);
						baraja_cartas.push_back(objcarta);
					}

					if (n == 11)//numero 11
					{
						objcarta = new cartas;
						objcarta->Setcartas(n, c, 2);
						baraja_cartas.push_back(objcarta);
						objcarta->Setcartas(n, c, 2);
						baraja_cartas.push_back(objcarta);
					}
					if (n == 12)//numero 12
					{
						objcarta = new cartas;
						objcarta->Setcartas(n, c, 3);
						baraja_cartas.push_back(objcarta);
						objcarta->Setcartas(n, c, 3);
						baraja_cartas.push_back(objcarta);
					}
					if (n == 13)//numero 13
					{
						objcarta = new cartas;
						objcarta->Setcartas(n, 5, 1);
						baraja_cartas.push_back(objcarta);
					}
					if (n == 14)//numero 14
					{
						objcarta = new cartas;
						objcarta->Setcartas(n, 5, 1);
						baraja_cartas.push_back(objcarta);
					}


					if (n != 10 && n != 11 && n != 12 && n != 13 && n != 14)
					{
						objcarta = new cartas;
						objcarta->Setcartas(n, c, 0);
						baraja_cartas.push_back(objcarta);
						if (n != 0)
						{
							objcarta = new cartas;
							objcarta->Setcartas(n, c, 0);
							baraja_cartas.push_back(objcarta);
						}
					}


				}

			}
			nb = false;
		}

		for (int i = 0; i < 108; i++)
		{
			b = rand() % (baraja_cartas.size());
			b1 = rand() % (baraja_cartas.size());
			swap(baraja_cartas[b], baraja_cartas[b1]);
		}

	}
	~baraja() {}

	cartas* mostrar_carta(int indice)
	{
		return baraja_cartas.at(indice);
	}
	void agregar_carta(cartas*dato)
	{
		baraja_cartas.push_back(dato);
	}
	int GetTamaño()
	{
		return baraja_cartas.size();
	}
	void eliminar_carta(int i)
	{
		baraja_cartas.erase(baraja_cartas.begin() + (i - 1));
	}

	cartas* carta_a_mesa()
	{
		return baraja_cartas.at(0);
	}

	void eliminar_cartas(int i)
	{
		baraja_cartas.erase(baraja_cartas.begin() + (i));
	}

	void barajear_cartas()
	{
		baraja_auxiliar = vector <cartas*>();
		int r, tamaño = 0, tamaño2 = 0;
		srand(time(NULL));
		int num;
		num = rand();
		tamaño = GetTamaño();
		tamaño2 = GetTamaño();

		//cout << endl << "El arreglo auxiliar " << baraja_auxiliar.size() << endl;
		//cout << endl << "El arreglo es de tamaño" << baraja_cartas.size() << endl; _getch();

		for (int i = 0; i < tamaño; i++)
		{
			objcarta = new cartas();
			num = 0;
			num = rand() % (tamaño2);//obtener numero aleatorios
			objcarta = mostrar_carta(num);//obtener la carta del numero elegido
										  /*cout << "La carta es : " << endl;
										  cout << i << "Numero :" << objcarta->GetNumero() << " " << objcarta->GetColor() << " " << objcarta->GetTipo(); cout << endl;*/
			baraja_auxiliar.push_back(objcarta);
			eliminar_cartas(num);
			tamaño2--;
		}
		_getch();
		//cout << endl << "El arreglo auxiliar " << baraja_auxiliar.size()<<endl;
		//cout << endl << "El arreglo es de tamaño" << baraja_cartas.size() << endl; _getch();
		for (int j = 0; j < tamaño; j++)
		{
			objcarta = baraja_auxiliar.at(j);
			baraja_cartas.push_back(objcarta);
		}
	}

	void Set_Color_carta_mesa_eleccion(int n)
	{
		carta_mesa_eleccion = n;
	}

	int Get_color_carta_mesa_eleccion()
	{
		return carta_mesa_eleccion;
	}

	cartas* Get_cartas(int n)
	{
		return baraja_cartas.at(n);
	}
};
