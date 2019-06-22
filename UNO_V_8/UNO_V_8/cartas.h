#pragma once
#include "conio.h"
#include <iostream>

using namespace System;
using namespace std;
using namespace System::Drawing;

class cartas
{
protected:
	int n;
	int c;
	int t;
	int ancho = 110;
	int alto = 180;


public:
	cartas(int n, int c, int t)
	{
		this->n = n;
		this->c = c;
		this->t = t;
	}
	cartas()
	{
		n = 0; c = 0; t = 0;
	}
	~cartas() {}

	int GetNumero()
	{
		return n;
	}
	int GetColor()
	{
		return c;
	}
	int GetTipo()
	{
		return t;
	}
	void Setcartas(int numero, int color, int tipo)
	{
		n = numero; c = color; t = tipo;
	}

	void dibujar(BufferedGraphics^buffer, Bitmap^bmp)
	{
		System::Drawing::Rectangle porcion_a_usar = System::Drawing::Rectangle(n*ancho, c*alto, ancho, alto);
		buffer->Graphics->DrawImage(bmp, porcion_a_usar, porcion_a_usar, GraphicsUnit::Pixel);
	}


	Bitmap^ dibujar_cn(Bitmap^bmp)
	{
		Bitmap^ btmapcarta = gcnew Bitmap(110, 180);
		Graphics^btncarta_graphics = Graphics::FromImage(btmapcarta);


		double indiceX = n;
		double indiceY = c;
		int ancho = 110;
		int alto = 180;

		if (n == 14)
		{
			indiceX = 13;
			indiceY = 6;
		}
		if (n == 13)
		{
			indiceY = 3;
		}

		System::Drawing::Rectangle porcionAUsar = Drawing::Rectangle(indiceX*ancho, indiceY*alto, ancho, alto);
		System::Drawing::Rectangle reduccion = Drawing::Rectangle(indiceX*0.1, indiceY*0.01, ancho, alto);
		btncarta_graphics->DrawImage(bmp, reduccion, porcionAUsar, GraphicsUnit::Pixel);

		return btmapcarta;
	}

	Bitmap^ dibujar_cb(Bitmap^bmp, int _nombre, int _color)
	{
		Bitmap^ btmapcarta = gcnew Bitmap(110, 180);
		Graphics^btncarta_graphics = Graphics::FromImage(btmapcarta);


		double indiceX = _nombre;
		double indiceY = _color;
		int ancho = 110;
		int alto = 180;

		if (n == 15)
		{
			indiceX = 13;
			indiceY = 6;
		}


		System::Drawing::Rectangle porcionAUsar = Drawing::Rectangle(indiceX*ancho, indiceY*alto, ancho, alto);
		System::Drawing::Rectangle reduccion = Drawing::Rectangle(indiceX*0.1, indiceY*0.01, ancho, alto);
		btncarta_graphics->DrawImage(bmp, reduccion, porcionAUsar, GraphicsUnit::Pixel);

		return btmapcarta;
	}

	Bitmap^ dibujar_cc(Bitmap^bmp, int _numero)
	{
		Bitmap^ btmapcarta = gcnew Bitmap(110, 180);
		Graphics^btncarta_graphics = Graphics::FromImage(btmapcarta);


		double indiceX = 0;
		double indiceY = _numero + 4;
		int ancho = 110;
		int alto = 180;

		System::Drawing::Rectangle porcionAUsar = Drawing::Rectangle(indiceX*ancho, indiceY*alto, ancho, alto);
		System::Drawing::Rectangle reduccion = Drawing::Rectangle(indiceX*0.1, indiceY*0.01, ancho, alto);
		btncarta_graphics->DrawImage(bmp, reduccion, porcionAUsar, GraphicsUnit::Pixel);

		return btmapcarta;
	}

};