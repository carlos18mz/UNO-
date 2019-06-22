#pragma once

#include <windows.h>
#include "conio.h"
#include "iostream"
#include "stdio.h"
#include <string>
#include "cartas.h"
#include <stdlib.h>


using namespace System;
using namespace std;

class baraja_aux
{
private:
	vector <cartas*> baraja_auxiliar;
public:
	baraja_aux() { baraja_auxiliar = vector<cartas*>(); }
	~baraja_aux() {}
	void agregar_cartas(cartas* dato)
	{
		baraja_auxiliar.push_back(dato);
	}
};