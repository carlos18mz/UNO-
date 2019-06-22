#pragma once
#include "conio.h"
#include "iostream"
#include "CJugador.h"
#include <vector>

class Arreglo_jugador
{
private:
	vector<jugador*> grupo_jugadores;
	int b1, b2;
	jugador* obj_jugador;
public:
	Arreglo_jugador() { grupo_jugadores = vector<jugador*>(); obj_jugador = new jugador(); }
	~Arreglo_jugador(){}
	void AgregarJugador(jugador* dato)
	{
		grupo_jugadores.push_back(dato);
	}
	void Cambiar_sentido_juego(bool sentido)
	{
		if (sentido == true)
		{
			for (int i = 0; i < GetnumeroJugadores(); i++)
			{
				for (int j = 0; j < GetnumeroJugadores(); j++)
				{

					if (grupo_jugadores.at(j)->Get_turno_jugador() < grupo_jugadores.at(i)->Get_turno_jugador())
					{
						swap(grupo_jugadores.at(i), grupo_jugadores.at(j));

					}
				}
			}
			
			cout << endl << "Los jugadores ordenados son : " << endl;
			int numero_orden=0;
			for (int r = 0; r < GetnumeroJugadores(); r++)
			{
				grupo_jugadores.at(r)->Set_turno_jugador(numero_orden);
				cout << endl << grupo_jugadores.at(r)->GetNombre() << ", " << grupo_jugadores.at(r)->Get_turno_jugador();
				numero_orden++;
			}
			cout << endl << "entro a sentido=true"<<endl;
		}
		
		cout << endl << "Se cambio el sentido del juego"<<endl;
		for (int m = 0; m < GetnumeroJugadores(); m++)
		{
			obj_jugador = grupo_jugadores.at(m);
			cout << "Jugador " << m  << " : " << obj_jugador->GetNombre() << " " << obj_jugador->Get_turno_jugador();cout<< endl;
		}
	}
	jugador* GetJugador(int n)
	{
		return grupo_jugadores.at(n);
	}
	int GetnumeroJugadores()
	{
		return grupo_jugadores.size();
	}

};