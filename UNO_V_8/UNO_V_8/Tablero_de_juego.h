#pragma once
#include <windows.h>
#include "conio.h"
#include "iostream"
#include "stdio.h"
#include <string>
#include "cartas.h"
#include "baraja_completa.h"
#include "CJugador.h"
#include <stdlib.h>
#include <time.h>
#include "Agregar_jugadores.h"
#include "Baraja_aux.h"
#include <Windows.h>
#include <direct.h> 
#include <fstream>
#include <vector>
#include <msclr\marshal_cppstd.h>
#include "Eleccion_color.h"


namespace UNO_V_8 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Tablero_de_juego
	/// </summary>
	public ref class Tablero_de_juego : public System::Windows::Forms::Form
	{
	public:
		int numero = 0, opcion=7, color = 0, tipo = 0, cantidad_repartidas = 0, persona_r, aux_jugador, aux_cartas;
		int cantidad_cartas;
		bool repartir_cartas = true;
		bool sentido_juego = true; //El juego empieza a la derecha

		int turno = 0;
		bool vez_por_turno = false;
		int ronda = 1;
		int carta_mesa = 0;
		int numero_carta_mesa;
		int color_carta_mesa;
		bool carta_mesa_inicial = true;
		bool carta_cambiada_comodin = false;
		bool jugada;
		bool sentido_de_juego = true; //empieza con el sentido de juego conforme a los instanciado

		baraja* objbaraja;
		baraja_aux* obj_baraja_aux = new baraja_aux();
		cartas* objcartas;
		jugador* objjugador;
		Bitmap^bmpCartas = gcnew Bitmap("UNO_cards_ReSize.png");


	private: System::Windows::Forms::HScrollBar^  Barra_de_cartas;
	public:
	private: System::Windows::Forms::PictureBox^  Box_carta_mesa;
	private: System::Windows::Forms::Label^  lbl_Ronda;
	private: System::Windows::Forms::Label^  lbl_Continuar;
	private: System::Windows::Forms::PictureBox^  Box_7;
	private: System::Windows::Forms::PictureBox^  Box_8;
	private: System::Windows::Forms::PictureBox^  Box_1;
	private: System::Windows::Forms::PictureBox^  Box_2;
	private: System::Windows::Forms::PictureBox^  Box_4;
	private: System::Windows::Forms::PictureBox^  Box_6;
	private: System::Windows::Forms::PictureBox^  Box_5;
	private: System::Windows::Forms::PictureBox^  Box_3;
	private: System::Windows::Forms::Label^  lbl_Jugador;
	private: System::Windows::Forms::Label^  lbl_jugador_actual;
	private: System::Windows::Forms::Label^  lbl_ganador;
	private: System::Windows::Forms::PictureBox^  Box_cojer_carta;


	public:

		void Get_cambio_de_color(int n)
		{
			numero_carta_mesa = n;
			carta_cambiada_comodin = true;
		}

		Arreglo_jugador* objarreglo_j;

		void settablero(Arreglo_jugador* dato)
		{
			objarreglo_j = dato;

		}

		void Setbaraja(baraja* dato)
		{
			objbaraja = dato;
		}

	public:
		int GetN_jugadores()
		{
			return objarreglo_j->GetnumeroJugadores();
		}


	public:
		Tablero_de_juego(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Tablero_de_juego()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Tablero_de_juego::typeid));
			this->Barra_de_cartas = (gcnew System::Windows::Forms::HScrollBar());
			this->Box_carta_mesa = (gcnew System::Windows::Forms::PictureBox());
			this->lbl_Ronda = (gcnew System::Windows::Forms::Label());
			this->lbl_Continuar = (gcnew System::Windows::Forms::Label());
			this->Box_7 = (gcnew System::Windows::Forms::PictureBox());
			this->Box_8 = (gcnew System::Windows::Forms::PictureBox());
			this->Box_1 = (gcnew System::Windows::Forms::PictureBox());
			this->Box_2 = (gcnew System::Windows::Forms::PictureBox());
			this->Box_4 = (gcnew System::Windows::Forms::PictureBox());
			this->Box_6 = (gcnew System::Windows::Forms::PictureBox());
			this->Box_5 = (gcnew System::Windows::Forms::PictureBox());
			this->Box_3 = (gcnew System::Windows::Forms::PictureBox());
			this->lbl_Jugador = (gcnew System::Windows::Forms::Label());
			this->Box_cojer_carta = (gcnew System::Windows::Forms::PictureBox());
			this->lbl_jugador_actual = (gcnew System::Windows::Forms::Label());
			this->lbl_ganador = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Box_carta_mesa))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Box_7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Box_8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Box_1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Box_2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Box_4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Box_6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Box_5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Box_3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Box_cojer_carta))->BeginInit();
			this->SuspendLayout();
			// 
			// Barra_de_cartas
			// 
			this->Barra_de_cartas->Location = System::Drawing::Point(155, 421);
			this->Barra_de_cartas->Minimum = 10;
			this->Barra_de_cartas->Name = L"Barra_de_cartas";
			this->Barra_de_cartas->Size = System::Drawing::Size(877, 21);
			this->Barra_de_cartas->TabIndex = 28;
			this->Barra_de_cartas->Value = 10;
			// 
			// Box_carta_mesa
			// 
			this->Box_carta_mesa->BackColor = System::Drawing::Color::Transparent;
			this->Box_carta_mesa->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Box_carta_mesa.BackgroundImage")));
			this->Box_carta_mesa->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Box_carta_mesa.InitialImage")));
			this->Box_carta_mesa->Location = System::Drawing::Point(530, 148);
			this->Box_carta_mesa->Name = L"Box_carta_mesa";
			this->Box_carta_mesa->Size = System::Drawing::Size(150, 250);
			this->Box_carta_mesa->TabIndex = 27;
			this->Box_carta_mesa->TabStop = false;
			// 
			// lbl_Ronda
			// 
			this->lbl_Ronda->AutoSize = true;
			this->lbl_Ronda->BackColor = System::Drawing::Color::Transparent;
			this->lbl_Ronda->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Ronda->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->lbl_Ronda->Location = System::Drawing::Point(1034, 18);
			this->lbl_Ronda->Name = L"lbl_Ronda";
			this->lbl_Ronda->Size = System::Drawing::Size(64, 17);
			this->lbl_Ronda->TabIndex = 26;
			this->lbl_Ronda->Text = L"Ronda :";
			// 
			// lbl_Continuar
			// 
			this->lbl_Continuar->AutoSize = true;
			this->lbl_Continuar->BackColor = System::Drawing::Color::Transparent;
			this->lbl_Continuar->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Continuar->ForeColor = System::Drawing::SystemColors::Control;
			this->lbl_Continuar->Location = System::Drawing::Point(436, 103);
			this->lbl_Continuar->Name = L"lbl_Continuar";
			this->lbl_Continuar->Size = System::Drawing::Size(294, 18);
			this->lbl_Continuar->TabIndex = 25;
			this->lbl_Continuar->Text = L"Click en la pantalla para continuar...";
			this->lbl_Continuar->Click += gcnew System::EventHandler(this, &Tablero_de_juego::lbl_Continuar_Click);
			// 
			// Box_7
			// 
			this->Box_7->BackColor = System::Drawing::Color::Transparent;
			this->Box_7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Box_7.BackgroundImage")));
			this->Box_7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Box_7.Image")));
			this->Box_7->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Box_7.InitialImage")));
			this->Box_7->Location = System::Drawing::Point(922, 464);
			this->Box_7->Name = L"Box_7";
			this->Box_7->Size = System::Drawing::Size(110, 180);
			this->Box_7->TabIndex = 24;
			this->Box_7->TabStop = false;
			this->Box_7->Click += gcnew System::EventHandler(this, &Tablero_de_juego::Box_7_Click);
			// 
			// Box_8
			// 
			this->Box_8->BackColor = System::Drawing::Color::Transparent;
			this->Box_8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Box_8.BackgroundImage")));
			this->Box_8->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Box_8.Image")));
			this->Box_8->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Box_8.InitialImage")));
			this->Box_8->Location = System::Drawing::Point(1062, 464);
			this->Box_8->Name = L"Box_8";
			this->Box_8->Size = System::Drawing::Size(110, 180);
			this->Box_8->TabIndex = 23;
			this->Box_8->TabStop = false;
			this->Box_8->Click += gcnew System::EventHandler(this, &Tablero_de_juego::Box_8_Click);
			// 
			// Box_1
			// 
			this->Box_1->BackColor = System::Drawing::Color::Transparent;
			this->Box_1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Box_1.Image")));
			this->Box_1->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Box_1.InitialImage")));
			this->Box_1->Location = System::Drawing::Point(12, 464);
			this->Box_1->Name = L"Box_1";
			this->Box_1->Size = System::Drawing::Size(110, 180);
			this->Box_1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->Box_1->TabIndex = 22;
			this->Box_1->TabStop = false;
			this->Box_1->Click += gcnew System::EventHandler(this, &Tablero_de_juego::Box_1_Click);
			// 
			// Box_2
			// 
			this->Box_2->BackColor = System::Drawing::Color::Transparent;
			this->Box_2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Box_2.Image")));
			this->Box_2->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Box_2.InitialImage")));
			this->Box_2->Location = System::Drawing::Point(155, 464);
			this->Box_2->Name = L"Box_2";
			this->Box_2->Size = System::Drawing::Size(110, 180);
			this->Box_2->TabIndex = 21;
			this->Box_2->TabStop = false;
			this->Box_2->Click += gcnew System::EventHandler(this, &Tablero_de_juego::Box_2_Click);
			// 
			// Box_4
			// 
			this->Box_4->BackColor = System::Drawing::Color::Transparent;
			this->Box_4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Box_4.Image")));
			this->Box_4->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Box_4.InitialImage")));
			this->Box_4->Location = System::Drawing::Point(466, 464);
			this->Box_4->Name = L"Box_4";
			this->Box_4->Size = System::Drawing::Size(110, 180);
			this->Box_4->TabIndex = 20;
			this->Box_4->TabStop = false;
			this->Box_4->Click += gcnew System::EventHandler(this, &Tablero_de_juego::Box_4_Click);
			// 
			// Box_6
			// 
			this->Box_6->BackColor = System::Drawing::Color::Transparent;
			this->Box_6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Box_6.BackgroundImage")));
			this->Box_6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Box_6.Image")));
			this->Box_6->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Box_6.InitialImage")));
			this->Box_6->Location = System::Drawing::Point(775, 464);
			this->Box_6->Name = L"Box_6";
			this->Box_6->Size = System::Drawing::Size(110, 180);
			this->Box_6->TabIndex = 19;
			this->Box_6->TabStop = false;
			this->Box_6->Click += gcnew System::EventHandler(this, &Tablero_de_juego::Box_6_Click);
			// 
			// Box_5
			// 
			this->Box_5->BackColor = System::Drawing::Color::Transparent;
			this->Box_5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Box_5.BackgroundImage")));
			this->Box_5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Box_5.Image")));
			this->Box_5->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Box_5.InitialImage")));
			this->Box_5->Location = System::Drawing::Point(620, 464);
			this->Box_5->Name = L"Box_5";
			this->Box_5->Size = System::Drawing::Size(110, 180);
			this->Box_5->TabIndex = 18;
			this->Box_5->TabStop = false;
			this->Box_5->Click += gcnew System::EventHandler(this, &Tablero_de_juego::Box_5_Click);
			// 
			// Box_3
			// 
			this->Box_3->BackColor = System::Drawing::Color::Transparent;
			this->Box_3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Box_3.Image")));
			this->Box_3->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Box_3.InitialImage")));
			this->Box_3->Location = System::Drawing::Point(311, 464);
			this->Box_3->Name = L"Box_3";
			this->Box_3->Size = System::Drawing::Size(110, 180);
			this->Box_3->TabIndex = 17;
			this->Box_3->TabStop = false;
			this->Box_3->Click += gcnew System::EventHandler(this, &Tablero_de_juego::Box_3_Click);
			// 
			// lbl_Jugador
			// 
			this->lbl_Jugador->AutoSize = true;
			this->lbl_Jugador->BackColor = System::Drawing::Color::Transparent;
			this->lbl_Jugador->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Jugador->ForeColor = System::Drawing::Color::LightGray;
			this->lbl_Jugador->Location = System::Drawing::Point(52, 17);
			this->lbl_Jugador->Name = L"lbl_Jugador";
			this->lbl_Jugador->Size = System::Drawing::Size(92, 18);
			this->lbl_Jugador->TabIndex = 16;
			this->lbl_Jugador->Text = L"Turno de : ";
			// 
			// Box_cojer_carta
			// 
			this->Box_cojer_carta->BackColor = System::Drawing::Color::Transparent;
			this->Box_cojer_carta->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Box_cojer_carta.BackgroundImage")));
			this->Box_cojer_carta->Location = System::Drawing::Point(52, 103);
			this->Box_cojer_carta->Name = L"Box_cojer_carta";
			this->Box_cojer_carta->Size = System::Drawing::Size(110, 180);
			this->Box_cojer_carta->TabIndex = 15;
			this->Box_cojer_carta->TabStop = false;
			this->Box_cojer_carta->Click += gcnew System::EventHandler(this, &Tablero_de_juego::Box_cojer_carta_Click);
			// 
			// lbl_jugador_actual
			// 
			this->lbl_jugador_actual->AutoSize = true;
			this->lbl_jugador_actual->BackColor = System::Drawing::Color::Transparent;
			this->lbl_jugador_actual->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lbl_jugador_actual->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->lbl_jugador_actual->Location = System::Drawing::Point(52, 39);
			this->lbl_jugador_actual->Name = L"lbl_jugador_actual";
			this->lbl_jugador_actual->Size = System::Drawing::Size(0, 18);
			this->lbl_jugador_actual->TabIndex = 29;
			// 
			// lbl_ganador
			// 
			this->lbl_ganador->AutoSize = true;
			this->lbl_ganador->BackColor = System::Drawing::Color::Transparent;
			this->lbl_ganador->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_ganador->Location = System::Drawing::Point(594, 39);
			this->lbl_ganador->Name = L"lbl_ganador";
			this->lbl_ganador->Size = System::Drawing::Size(0, 18);
			this->lbl_ganador->TabIndex = 30;
			// 
			// Tablero_de_juego
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1184, 661);
			this->Controls->Add(this->lbl_ganador);
			this->Controls->Add(this->lbl_jugador_actual);
			this->Controls->Add(this->Barra_de_cartas);
			this->Controls->Add(this->Box_carta_mesa);
			this->Controls->Add(this->lbl_Ronda);
			this->Controls->Add(this->lbl_Continuar);
			this->Controls->Add(this->Box_7);
			this->Controls->Add(this->Box_8);
			this->Controls->Add(this->Box_1);
			this->Controls->Add(this->Box_2);
			this->Controls->Add(this->Box_4);
			this->Controls->Add(this->Box_6);
			this->Controls->Add(this->Box_5);
			this->Controls->Add(this->Box_3);
			this->Controls->Add(this->lbl_Jugador);
			this->Controls->Add(this->Box_cojer_carta);
			this->Name = L"Tablero_de_juego";
			this->Text = L"Tablero_de_juego";
			this->Load += gcnew System::EventHandler(this, &Tablero_de_juego::Tablero_de_juego_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Box_carta_mesa))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Box_7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Box_8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Box_1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Box_2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Box_4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Box_6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Box_5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Box_3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Box_cojer_carta))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

     //Pasar una carta de la baraja al jugador
	private: System::Void Box_cojer_carta_Click(System::Object^  sender, System::EventArgs^  e) {	
		if (jugada == false)
		{
			int numero_de_cartas;
			objcartas = objbaraja->Get_cartas(0);
			MessageBox::Show("Se cogio una carta de la baraja");
			activar_desactivar_pictbox(false);
			cout << endl << endl << "La carta que se va a pasar al jugador es : " << objcartas->GetNumero() << ", " << objcartas->GetColor() << endl;
			objjugador->Agregar_cartas_jugador(objcartas);
			objbaraja->eliminar_cartas(0);
			numero_de_cartas = objjugador->Get_numero_decartas();
			cout << "La carta que paso al jugador es : " << objjugador->Getcartas(numero_de_cartas - 1)->GetNumero() << "," << objjugador->Getcartas(numero_de_cartas - 1)->GetColor() << endl;
			lbl_Continuar->Text = "presione tecla para continuar";
			activar_desactivar_pictbox(false);
		    jugada = true;

	    }
	else
	{
		MessageBox::Show("No puedes coger otra carta");
	}
	}
  private:System::Void Definir_bitmaps_cartas()
  {
	  Bitmap^ aux0 = gcnew Bitmap(110, 180);
	  Bitmap^ aux1 = gcnew Bitmap(110, 180);
	  Bitmap^ aux2 = gcnew Bitmap(110, 180);
	  Bitmap^ aux3 = gcnew Bitmap(110, 180);
	  Bitmap^ aux4 = gcnew Bitmap(110, 180);
	  Bitmap^ aux5 = gcnew Bitmap(110, 180);
	  Bitmap^ aux6 = gcnew Bitmap(110, 180);
	  Bitmap^ aux7 = gcnew Bitmap(110, 180);
	  Bitmap^ aux8 = gcnew Bitmap(110, 180);
  }

	private: System::Void Ocultar11()
	{
		Box_1->Image = Box_1->InitialImage;
		Box_2->Image = Box_2->InitialImage;
		Box_3->Image = Box_3->InitialImage;
		Box_4->Image = Box_4->InitialImage;
		Box_5->Image = Box_5->InitialImage;
		Box_6->Image = Box_6->InitialImage;
		Box_7->Image = Box_7->InitialImage;
		Box_8->Image = Box_8->InitialImage;
	}
     
  private:System::Void activar_desactivar_pictbox(bool opcion_cambio)
  {
	  if (opcion_cambio == false)
	  {
		  Box_1->Enabled = false;
		  Box_2->Enabled = false;
		  Box_3->Enabled = false;
		  Box_4->Enabled = false;
		  Box_5->Enabled = false;
		  Box_6->Enabled = false;
		  Box_7->Enabled = false;
		  Box_8->Enabled = false;

		  Box_1->Image = Box_1->InitialImage;
		  Box_2->Image = Box_2->InitialImage;
		  Box_3->Image = Box_3->InitialImage;
		  Box_4->Image = Box_4->InitialImage;
		  Box_5->Image = Box_5->InitialImage;
		  Box_6->Image = Box_6->InitialImage;
		  Box_7->Image = Box_7->InitialImage;
		  Box_8->Image = Box_8->InitialImage;
	  }
	  else
	  {
		  Box_1->Enabled = true;
		  Box_2->Enabled = true;
		  Box_3->Enabled = true;
		  Box_4->Enabled = true;
		  Box_5->Enabled = true;
		  Box_6->Enabled = true;
		  Box_7->Enabled = true;
		  Box_8->Enabled = true;
	  }
  }

	  private: System::Void UNO()
	  {
		  if (objjugador->Get_numero_decartas() == 1)
		  {
			  MessageBox::Show("UNO");
		  }
		  if (objjugador->Get_numero_decartas() == 0)
		  {
			  lbl_Continuar->Text = "Termino el juego";

			  string nombre_a_convertir = objjugador->GetNombre();

			  /*convertir nombre de jugador std string a String^*/
			  String^ nombre_jugador = " ";
			  nombre_jugador = gcnew String(nombre_a_convertir.c_str());

			  lbl_ganador->Text = "El ganador es : " + nombre_jugador;
		  }
	  }
      //pasar las cartas del jugador a la baraja
      private: System::Void Mostrar_cartas(int n)
	 {
	 objcartas = new cartas();
	 objcartas = objjugador->Getcartas(n);
	 cout<<"La carta eliminada es : "<< objjugador->Getcartas(n)->GetNumero()<<", "<< objjugador->Getcartas(n)->GetColor();
	 objbaraja->agregar_carta(objcartas);
	 objjugador->eliminar_carta_jugador(n);

     }

  private: System::Void Validacion_de_jugada(int n)
  {
	  //verifica si hay una carta en el picturebox
	  cout << endl << endl << "Informacion de la carta : " << endl;
	  if (objjugador->Get_numero_decartas() > n)
	  {
		  cout << "Numero de la carta : " << objjugador->Getcartas(n)->GetNumero(); cout << endl;
		  cout << "Color de la carta : " << objjugador->Getcartas(n)->GetColor(); cout << endl;

		  //si la carta de la mesa es comodin
		  if (numero_carta_mesa == 13 || numero_carta_mesa == 14)
		  {
			  color_carta_mesa == 5;
		  }
		  //si la carta de la mesa no es comodin
		
		  cout << endl << endl << "La carta de la mesa no es comodin" << endl;
		  //si la carta es comodin se puede tirar en cualquier momento
		  if (objjugador->Getcartas(n)->GetNumero() == 13 || objjugador->Getcartas(n)->GetNumero() == 14)
		  {
			  if (objjugador->Getcartas(n)->GetNumero() == 13)
			  {
				  if (jugada == false)
				  {
					  carta_cambiada_comodin = false;
					  cout << endl << "La carta elegida es comodin" << endl;
					  MessageBox::Show("Elige el color que desee cambiar");
					  Eleccion_color^ obj_eleccion_color = gcnew Eleccion_color();
					  obj_eleccion_color->ShowDialog();
					  opcion = obj_eleccion_color->opciones;
					  jugada = true;
					  Bitmap^ Eleccion = gcnew Bitmap(110, 180);

					  Eleccion = objcartas->dibujar_cc(bmpCartas, opcion);
					  Box_carta_mesa->Image = Eleccion;
					  Box_carta_mesa->SizeMode = PictureBoxSizeMode::StretchImage;
					  cout << "Paso";

					  cout << endl << "La carta mesa es de tipo : " << opcion;

					  cout << endl << "La carta que se tiro fue : " << objjugador->Getcartas(n)->GetNumero() << objjugador->Getcartas(n)->GetColor(); cout << endl;


					  carta_cambiada_comodin = true;
					  Mostrar_cartas(n);
					  lbl_Continuar->Text = "presione tecla para continuar";
					  activar_desactivar_pictbox(false);
				  }
			  }
			 
			  if (objjugador->Getcartas(n)->GetNumero() == 14)
			  {   
				  if (jugada == false)
				  {

				      int r;
					  srand(time(NULL));

					  MessageBox::Show("El siguiente gana 4 cartas");
					  if (turno >= objarreglo_j->GetnumeroJugadores())
					  {
						  objjugador = objarreglo_j->GetJugador(0);
					  }
					  else
					  {
						  objjugador = objarreglo_j->GetJugador(turno);
					  }

					  for (int w = 0; w < 4; w++)//reparte 4 cartas a todos los jugadores
					  {
						  objcartas = new cartas();
						  r = rand() % (objbaraja->GetTamaño());//elige un numero
						  objcartas = objbaraja->mostrar_carta(r);//elige la carta
						  cout << w << "\t\t\t" << objcartas->GetNumero() << "\t\t" << objcartas->GetColor() << "\t\t " << objcartas->GetTipo(); cout << endl;

						  objjugador->Agregar_cartas_jugador(objcartas);//mueve las cartas de la baraja al jugador
						  objbaraja->eliminar_cartas(r);
					  }
					  cout << endl << "El valor del turno es : " << turno;
					  cout << endl << "El jugador que gana cuatro cartas es : " << objjugador->GetNombre() << endl;

					  objjugador = objarreglo_j->GetJugador(turno - 1);
					  cout << endl << "El juego esta en el turno de : " << objjugador->GetNombre() << endl;

					  carta_cambiada_comodin = false;
					  cout << endl << "La carta elegida es comodin" << endl;
					  Eleccion_color^ obj_eleccion_color = gcnew Eleccion_color();
					  obj_eleccion_color->ShowDialog();
					  opcion = obj_eleccion_color->opciones;
					  jugada = true;
					  Bitmap^ Eleccion = gcnew Bitmap(110, 180);

					  Eleccion = objcartas->dibujar_cc(bmpCartas, opcion);
					  Box_carta_mesa->Image = Eleccion;
					  Box_carta_mesa->SizeMode = PictureBoxSizeMode::StretchImage;
					  cout << "Paso";

					  cout << endl << "La carta que se tiro fue : " << objjugador->Getcartas(n)->GetNumero() << objjugador->Getcartas(n)->GetColor(); cout << endl;

					  carta_cambiada_comodin = true;
					  Mostrar_cartas(n);
					  lbl_Continuar->Text = "presione tecla para continuar";
					  activar_desactivar_pictbox(false);

				  }
			  }

		  }

		  //  //si la carta no es comodin
		  else
		  {
			  if (objjugador->Getcartas(n)->GetNumero() == numero_carta_mesa || objjugador->Getcartas(n)->GetColor() == color_carta_mesa)
			  {
				  if (objjugador->Getcartas(n)->GetNumero() == 10)
				  {
					  if (jugada == false)
					  {
						  //en este momento turno es 3
						  MessageBox::Show("El siguiente jugador pierde 1 turno");
						  if (turno >= objarreglo_j->GetnumeroJugadores())
						  {
							  objjugador = objarreglo_j->GetJugador(0);
						  }
						  else
						  {
							  objjugador = objarreglo_j->GetJugador(turno);
						  }

						  objjugador->Set_pierde_t(true);
						  cout << endl << "El valor del turno es : " << turno;
						  cout << endl << "El jugador que pierde turno es : " << objjugador->GetNombre() << endl;

						  objjugador = objarreglo_j->GetJugador(turno - 1);
						  cout << endl << "El juego esta en el turno de : " << objjugador->GetNombre() << endl;

						  cout << endl << "La carta que se tiro fue : " << objjugador->Getcartas(n)->GetNumero() << objjugador->Getcartas(n)->GetColor(); cout << endl;


						  jugada = true;
						  Mostrar_cartas(n);
						  lbl_Continuar->Text = "presione tecla para continuar";
						  //cout << endl << "La carta no es comodin";
						  activar_desactivar_pictbox(false);
					  }
				  }

				  if (objjugador->Getcartas(n)->GetNumero() == 11)
				  {
					  if (jugada == false)
					  {
						  objarreglo_j->Cambiar_sentido_juego(sentido_de_juego);
						  MessageBox::Show("El orden de los turnos cambia");


						  cout << endl << "La carta que se tiro fue : " << objjugador->Getcartas(n)->GetNumero() << objjugador->Getcartas(n)->GetColor(); cout << endl;

						  jugada = true;
						  ronda++;
						  turno = 0;
						  Mostrar_cartas(n);
						  lbl_Continuar->Text = "presione tecla para continuar";
						  activar_desactivar_pictbox(false);

					  }
				  }

				  if (objjugador->Getcartas(n)->GetNumero() == 12)
				  {
					  if (jugada == false)
					  {

						  int r;
						  srand(time(NULL));

						  MessageBox::Show("El siguiente gana 2 cartas");
						  if (turno >= objarreglo_j->GetnumeroJugadores())
						  {
							  objjugador = objarreglo_j->GetJugador(0);
						  }
						  else
						  {
							  objjugador = objarreglo_j->GetJugador(turno);
						  }

						  for (int w = 0; w < 2; w++)//reparte 7 cartas a todos los jugadores
						  {
							  objcartas = new cartas();
							  r = rand() % (objbaraja->GetTamaño());//elige un numero
							  objcartas = objbaraja->mostrar_carta(r);//elige la carta
							  cout << w << "\t\t\t" << objcartas->GetNumero() << "\t\t" << objcartas->GetColor() << "\t\t " << objcartas->GetTipo(); cout << endl;

							  objjugador->Agregar_cartas_jugador(objcartas);//mueve las cartas de la baraja al jugador
							  objbaraja->eliminar_cartas(r);
						  }
						  cout << endl << "El valor del turno es : " << turno;
						  cout << endl << "El jugador que gana dos cartas es : " << objjugador->GetNombre() << endl;

						  objjugador = objarreglo_j->GetJugador(turno - 1);
						  cout << endl << "El juego esta en el turno de : " << objjugador->GetNombre() << endl;

						  cout << endl << "La carta que se tiro fue : " << objjugador->Getcartas(n)->GetNumero() << objjugador->Getcartas(n)->GetColor(); cout << endl;

						  jugada = true;
						  Mostrar_cartas(n);
						  lbl_Continuar->Text = "presione tecla para continuar";
						  //cout << endl << "La carta no es comodin";
						  activar_desactivar_pictbox(false);
					  }
				  }

				  else
				  {
					  if (jugada == false)
					  {
						  carta_cambiada_comodin = false;
						  cout << endl << "La carta elegida no es comodin" << endl;
						  cout << endl << "La carta es : " << objjugador->Getcartas(n)->GetNumero() << ", " << objjugador->Getcartas(n)->GetColor();
						  MessageBox::Show("Se presiono la carta ");

						  cout << endl << "La carta que se tiro fue : " << objjugador->Getcartas(n)->GetNumero() << objjugador->Getcartas(n)->GetColor(); cout << endl;

						  jugada = true;
						  Mostrar_cartas(n);
						  cout << endl << "Ingresa a la carta normal" << endl;
						  lbl_Continuar->Text = "presione tecla para continuar";
						  activar_desactivar_pictbox(false);
					  }
					  else
					  {

					  }
				  }
			  }
			  else
			  {
			  }
		  }
		  
	  }
  }


	private: System::Void lbl_Continuar_Click(System::Object^  sender, System::EventArgs^  e) {

		activar_desactivar_pictbox(true);
		Box_cojer_carta->Enabled = true;
		jugada = false;

		//Dibujar la carta de la mesa
		carta_mesa = objbaraja->GetTamaño();
		Bitmap^ auxmesa = gcnew Bitmap(110, 180);
		objcartas = new cartas();

		objcartas = objbaraja->mostrar_carta(carta_mesa - 1);

		cout << endl << "La carta de la mesa es : " << objcartas->GetNumero() << ", " << objcartas->GetColor(); cout << endl;

	if (carta_cambiada_comodin == true)
	{
		color_carta_mesa = opcion;
		numero_carta_mesa = 15;
		cout << endl << "entra al ciclo eleccion de color"<<endl;
	}
	else
	{
		numero_carta_mesa = objcartas->GetNumero();
		color_carta_mesa = objcartas->GetColor();
		cout << endl << endl << "Entra al ciclo de jugada normal" <<endl;
	}

	cout << "================================================================" << endl;
	cout << "Numero de la carta de la mesa es : " <<numero_carta_mesa; cout << endl;
	cout << "Color de la carta de la mesa es : " << color_carta_mesa ; cout << endl;
	cout <<  "================================================================" << endl;

	//g->DrawImage(btmapcarta, porcionAUsar, porcionAUsar, GraphicsUnit::Pixel);
	if (carta_cambiada_comodin == false)
	{
		cout << endl << "La carta comodin es true";
		//auxmesa = objcartas->dibujar_cb(bmpCartas, objcartas->GetNumero(), objcartas->GetColor());
		auxmesa = objcartas->dibujar_cb(bmpCartas, numero_carta_mesa, color_carta_mesa);
		Box_carta_mesa->Image = auxmesa;//imprime la carta de la mesa en el picturebox
		Box_carta_mesa->SizeMode = PictureBoxSizeMode::StretchImage;
	}
	
	if (turno == objarreglo_j->GetnumeroJugadores())
	{
		turno = 0;
		ronda++;
	}

	lbl_Ronda->Text = "Ronda : " + ronda;

	//si el jugador perdio un turno

	//colocar el nombre del jugador en el label
	for (int i = 0; i < objarreglo_j->GetnumeroJugadores(); i++)
	{
		objjugador = new jugador();
		objjugador = objarreglo_j->GetJugador(i);
		
		if (objjugador->Get_turno_jugador() == turno)
		{
			break;
			cout << endl << "Turno de : " << objjugador->GetNombre();
		}
	}

	//si el jugador perdio un turno

	string nombre_a_convertir = objjugador->GetNombre();
	cout << "Turno de : " << nombre_a_convertir << endl;
	cout << "Cantidad de cartas : " << objjugador->Get_numero_decartas() << endl;
	cout << "Cartas en baraja : " << objbaraja->GetTamaño() << endl;

	/*convertir nombre de jugador std string a String^*/
	String^ nombre_jugador = " ";
	nombre_jugador = gcnew String(nombre_a_convertir.c_str());

	lbl_Jugador->Text = "Turno de jugador : " + nombre_jugador;
	lbl_jugador_actual->Text = (turno+1) + " / " + objarreglo_j->GetnumeroJugadores();

			//si el jugador perdio un turno

	
			if (objjugador->Get_pierde_t() == false)
			{
				
				cout << endl << "El jugador no ha perdido el turno";
				turno++;

				lbl_Continuar->Text = " ";
				Bitmap^ btmapcarta = gcnew Bitmap("UNO_hide2.png");
				Graphics^g = this->CreateGraphics();
				Bitmap^ aux0 = gcnew Bitmap(110, 180);
				Bitmap^ aux1 = gcnew Bitmap(110, 180);
				Bitmap^ aux2 = gcnew Bitmap(110, 180);
				Bitmap^ aux3 = gcnew Bitmap(110, 180);
				Bitmap^ aux4 = gcnew Bitmap(110, 180);
				Bitmap^ aux5 = gcnew Bitmap(110, 180);
				Bitmap^ aux6 = gcnew Bitmap(110, 180);
				Bitmap^ aux7 = gcnew Bitmap(110, 180);
				Bitmap^ aux8 = gcnew Bitmap(110, 180);

				for (int i = 0; i < objjugador->Get_numero_decartas(); i++)
				{
					objcartas = objjugador->Getcartas(i);
					cout << endl << "Numero de la carta : " << objcartas->GetNumero() << ", " << objcartas->GetColor();
					switch (i)
					{
					case 0:objcartas = new cartas();
						objcartas = objjugador->Getcartas(i);
						aux0 = objcartas->dibujar_cn(bmpCartas);
						//g->DrawImage(btmapcarta, porcionAUsar, porcionAUsar, GraphicsUnit::Pixel);
						Box_1->Image = aux0;//imprime la carta en el picturebox
						break;

					case 1:objcartas = new cartas();
						objcartas = objjugador->Getcartas(i);
						aux1 = objcartas->dibujar_cn(bmpCartas);
						//g->DrawImage(btmapcarta, porcionAUsar, porcionAUsar, GraphicsUnit::Pixel);
						Box_2->Image = aux1;//imprime la carta en el picturebox
						break;

					case 2:objcartas = new cartas();
						objcartas = objjugador->Getcartas(i);
						aux2 = objcartas->dibujar_cn(bmpCartas);
						//g->DrawImage(btmapcarta, porcionAUsar, porcionAUsar, GraphicsUnit::Pixel);
						Box_3->Image = aux2;//imprime la carta en el picturebox
						break;

					case 3:objcartas = new cartas();
						objcartas = objjugador->Getcartas(i);
						aux3 = objcartas->dibujar_cn(bmpCartas);
						//g->DrawImage(btmapcarta, porcionAUsar, porcionAUsar, GraphicsUnit::Pixel);
						Box_4->Image = aux3;//imprime la carta en el picturebox
						break;

					case 4:objcartas = new cartas();
						objcartas = objjugador->Getcartas(i);
						aux4 = objcartas->dibujar_cn(bmpCartas);
						//g->DrawImage(btmapcarta, porcionAUsar, porcionAUsar, GraphicsUnit::Pixel);
						Box_5->Image = aux4;//imprime la carta en el picturebox
						break;

					case 5:objcartas = new cartas();
						objcartas = objjugador->Getcartas(i);
						aux5 = objcartas->dibujar_cn(bmpCartas);
						//g->DrawImage(btmapcarta, porcionAUsar, porcionAUsar, GraphicsUnit::Pixel);
						Box_6->Image = aux5;//imprime la carta en el picturebox
						break;

					case 6:objcartas = new cartas();
						objcartas = objjugador->Getcartas(i);
						aux6 = objcartas->dibujar_cn(bmpCartas);
						//g->DrawImage(btmapcarta, porcionAUsar, porcionAUsar, GraphicsUnit::Pixel);
						Box_7->Image = aux6;//imprime la carta en el picturebox
						break;

					case 7:objcartas = new cartas();
						objcartas = objjugador->Getcartas(i);
						aux7 = objcartas->dibujar_cn(bmpCartas);
						//g->DrawImage(btmapcarta, porcionAUsar, porcionAUsar, GraphicsUnit::Pixel);
						Box_8->Image = aux7;//imprime la carta en el picturebox
						break;
					}
				}
			}
			else
			{
				MessageBox::Show("El jugador pierde un turno");
				objjugador->Set_pierde_t(false);
				activar_desactivar_pictbox(false);
				Box_cojer_carta->Enabled = false;
				turno++;
			}		
}


private: System::Void Tablero_de_juego_Load(System::Object^  sender, System::EventArgs^  e) {
	Console::Clear();

	int cantidad_jugadores = objarreglo_j->GetnumeroJugadores();
	cout << "INICIO DEL JUEGO";

	cout << endl << endl << "Cantidad de jugadores : " << cantidad_jugadores;
	for (int i = 0; i < objarreglo_j->GetnumeroJugadores(); i++)
	{
		objjugador = objarreglo_j->GetJugador(i);
		cout << endl << i<<")" << " Jugador : " << objjugador->GetNombre() << endl;
	}
	cout << endl << "Cada jugador tiene 7 cartas";
	cout << endl << "Cartas en la baraja : " << objbaraja->GetTamaño();

	lbl_Ronda->Text = "Ronda : " + ronda;
	activar_desactivar_pictbox(false);
	Box_cojer_carta->Enabled = false;
}
private: System::Void Box_1_Click(System::Object^  sender, System::EventArgs^  e) {
	Validacion_de_jugada(0);
	UNO();

}
private: System::Void Box_2_Click(System::Object^  sender, System::EventArgs^  e) {
	Validacion_de_jugada(1);
	UNO();
}
private: System::Void Box_3_Click(System::Object^  sender, System::EventArgs^  e) {
	Validacion_de_jugada(2);
	UNO();
}
private: System::Void Box_4_Click(System::Object^  sender, System::EventArgs^  e) {
	Validacion_de_jugada(3);
	UNO();
}
private: System::Void Box_5_Click(System::Object^  sender, System::EventArgs^  e) {
	Validacion_de_jugada(4);
	UNO();
}
private: System::Void Box_6_Click(System::Object^  sender, System::EventArgs^  e) {

	Validacion_de_jugada(5);
	UNO();
}
private: System::Void Box_7_Click(System::Object^  sender, System::EventArgs^  e) {


	Validacion_de_jugada(6);
	UNO();
}
private: System::Void Box_8_Click(System::Object^  sender, System::EventArgs^  e) {


	Validacion_de_jugada(7);
	UNO();
}
};
}
