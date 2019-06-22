#pragma once //terminado
#include <windows.h>
#include "conio.h"
#include "iostream"
#include "stdio.h"
#include <string>
#include "conio.h"
#include <iostream>
#include <vector>
#include "cartas.h"

class jugador
{
protected:
	string nombre;
	vector<cartas*> baraja_jugador;
	bool pierde_turno;
	int numero_turno_jugador;

public:
	jugador(string _nombre) { nombre = _nombre; baraja_jugador = vector<cartas*>(); }

	jugador() { nombre = " "; pierde_turno = false; numero_turno_jugador = 0; }
	~jugador() {}
	void SetNombre(string _nombre)
	{
		nombre = _nombre;
	}
	string GetNombre()
	{
		return nombre;
	}

	void Set_pierde_t(bool opcion)
	{
		if (opcion == true)
		{
			pierde_turno = true;
		}
		if (opcion == false)
		{
			pierde_turno = false;
		}
	}

	void Set_turno_jugador(int num)
	{
		numero_turno_jugador = num;
	}

	int Get_turno_jugador()
	{
		return numero_turno_jugador;
	}

	bool Get_pierde_t()
	{
		return pierde_turno;
	}

	void Agregar_cartas_jugador(cartas* dato) { baraja_jugador.push_back(dato); }
	cartas* Getcartas(int dato) { return baraja_jugador.at(dato);}

	int Get_numero_decartas() { return baraja_jugador.size(); }

	void eliminar_carta_jugador(int n) { 
		cout << endl << "La carta a eliminar (desde la clase jugador) es :" << Getcartas(n)->GetNumero() << ", " << Getcartas(n)->GetColor();
		baraja_jugador.erase(baraja_jugador.begin() + (n)); }
	///////////////////////////////////////////rwfsegf

};