#pragma once
#include <msclr\marshal_cppstd.h>//se debe poner siempre encima de todo
#include "vector"
#include "Tablero_de_juego.h"
#include "CJugador.h"
#include <vector>
#include "baraja_completa.h"
#include "Agregar_jugadores.h"

namespace UNO_V_8 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Registro_jugadores
	/// </summary>
	public ref class Registro_jugadores : public System::Windows::Forms::Form
	{
	public:
		Registro_jugadores(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}
	public:
		int turno = 0;
		baraja* objbaraja = new baraja();
		jugador* objjugador;
		cartas* objcartas;
		Arreglo_jugador* obj_arreglo_jugador;
		Arreglo_jugador* objarreglo_j = new Arreglo_jugador();
		Arreglo_jugador* objarreglo_aux = new Arreglo_jugador();
		Tablero_de_juego^ obj_tablero = gcnew Tablero_de_juego();


	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Registro_jugadores()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btn_iniciar;
	protected:
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  btn_Registrar;
	private: System::Windows::Forms::TextBox^  text_Nombre;
	private: System::Windows::Forms::Label^  label1;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Registro_jugadores::typeid));
			this->btn_iniciar = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->btn_Registrar = (gcnew System::Windows::Forms::Button());
			this->text_Nombre = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// btn_iniciar
			// 
			this->btn_iniciar->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_iniciar->Location = System::Drawing::Point(563, 421);
			this->btn_iniciar->Name = L"btn_iniciar";
			this->btn_iniciar->Size = System::Drawing::Size(90, 36);
			this->btn_iniciar->TabIndex = 9;
			this->btn_iniciar->Text = L"Iniciar";
			this->btn_iniciar->UseVisualStyleBackColor = true;
			this->btn_iniciar->Click += gcnew System::EventHandler(this, &Registro_jugadores::btn_iniciar_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::Black;
			this->label2->Location = System::Drawing::Point(436, 366);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(312, 36);
			this->label2->TabIndex = 8;
			this->label2->Text = L"Numero de jugadores registrados : 0/4\r\n\r\n";
			this->label2->Click += gcnew System::EventHandler(this, &Registro_jugadores::label2_Click);
			// 
			// btn_Registrar
			// 
			this->btn_Registrar->BackColor = System::Drawing::Color::White;
			this->btn_Registrar->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_Registrar->ForeColor = System::Drawing::Color::Black;
			this->btn_Registrar->Location = System::Drawing::Point(553, 297);
			this->btn_Registrar->Name = L"btn_Registrar";
			this->btn_Registrar->Size = System::Drawing::Size(106, 34);
			this->btn_Registrar->TabIndex = 7;
			this->btn_Registrar->Text = L"Registrar";
			this->btn_Registrar->UseVisualStyleBackColor = false;
			this->btn_Registrar->Click += gcnew System::EventHandler(this, &Registro_jugadores::btn_Registrar_Click);
			// 
			// text_Nombre
			// 
			this->text_Nombre->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->text_Nombre->Location = System::Drawing::Point(553, 247);
			this->text_Nombre->Name = L"text_Nombre";
			this->text_Nombre->Size = System::Drawing::Size(100, 20);
			this->text_Nombre->TabIndex = 6;
			this->text_Nombre->TextChanged += gcnew System::EventHandler(this, &Registro_jugadores::text_Nombre_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(484, 203);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(241, 18);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Ingrese el numero de jugador";
			this->label1->Click += gcnew System::EventHandler(this, &Registro_jugadores::label1_Click);
			// 
			// Registro_jugadores
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1184, 661);
			this->Controls->Add(this->btn_iniciar);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->btn_Registrar);
			this->Controls->Add(this->text_Nombre);
			this->Controls->Add(this->label1);
			this->Name = L"Registro_jugadores";
			this->Text = L"Registro_jugadores";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void btn_iniciar_Click(System::Object^  sender, System::EventArgs^  e) {
		cout << objarreglo_j->GetnumeroJugadores() << endl;
		if (objarreglo_j->GetnumeroJugadores() > 1)
		{
			for (int i = 0; i < objarreglo_j->GetnumeroJugadores(); i++)//para jugadores
			{
				objjugador = objarreglo_j->GetJugador(i);
				cout << endl << objjugador->GetNombre() << endl;
				for (int c = 0; c < objjugador->Get_numero_decartas(); c++)
				{
					objcartas = objjugador->Getcartas(c);
					cout << objcartas->GetNumero() << endl;
				}

			}

			cout << endl << endl << "Numero de jugadores registrados : " << objarreglo_j->GetnumeroJugadores();

			Tablero_de_juego^ obj_tablero = gcnew Tablero_de_juego();
			obj_tablero->settablero(objarreglo_j);
			obj_tablero->Setbaraja(objbaraja);
			Visible = false;
			obj_tablero->ShowDialog();

			//Visible = false;
			//cout << objarreglo_j->GetnumeroJugadores();

		}
		else
		{
			MessageBox::Show("No hay suficientes jugadores para iniciar una partida");
		}
	}
private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void btn_Registrar_Click(System::Object^  sender, System::EventArgs^  e) {
	Tablero_de_juego^ obj_tablero = gcnew Tablero_de_juego();
	msclr::interop::marshal_context context;
	string nombre = context.marshal_as<string>(text_Nombre->Text);
	bool n_repetidas = false;
	int r;
	srand(time(NULL));

	if (objarreglo_j->GetnumeroJugadores() == 0)
	{
		objjugador = new jugador();
		objjugador->SetNombre(nombre);//poner nombre al jugador
		objjugador->Set_turno_jugador(turno);
		objarreglo_j->AgregarJugador(objjugador);//agregar el jugador al arreglo
		cout << endl << endl << "Registrado jugador : " << objjugador->GetNombre() << endl;
		cout << endl << endl << "Turno del jugador : " << objjugador->Get_turno_jugador() << endl;
		cout << endl << "Mostrando cartas..." << endl << endl;
		cout << "\nCarta N° \t\tNumero\t\tcolor\t\t tipo" << endl << endl;

		for (int w = 0; w < 7; w++)//reparte 7 cartas a todos los jugadores
		{
			objcartas = new cartas();
			r = rand() % (objbaraja->GetTamaño());//elige un numero
			objcartas = objbaraja->mostrar_carta(r);//elige la carta
			cout << w << "\t\t\t" << objcartas->GetNumero() << "\t\t" << objcartas->GetColor() << "\t\t " << objcartas->GetTipo(); cout << endl;
			objjugador->Agregar_cartas_jugador(objcartas);//mueve las cartas de la baraja al jugador
			objbaraja->eliminar_cartas(r);
		}
		turno++;
		MessageBox::Show("El jugador fue registrado");
		label2->Text = "Numero de jugadores registrados : " + objarreglo_j->GetnumeroJugadores() + "/4";
		cout << endl << "Numero de cartas en baraja " << objbaraja->GetTamaño() << endl;
		text_Nombre->Clear();
	}
	else
	{
		for (int p = 0; p < objarreglo_j->GetnumeroJugadores(); p++)
		{
			objjugador = new jugador();
			objjugador = objarreglo_j->GetJugador(p);
			if (nombre == objjugador->GetNombre())
			{
				n_repetidas = true;
			}
		}
		if (n_repetidas == false)
		{
			int r;
			srand(time(NULL));

			objjugador = new jugador();
			objjugador->SetNombre(nombre);//poner nombre al jugador
			objjugador->Set_turno_jugador(turno);
			objarreglo_j->AgregarJugador(objjugador);//crear al jugador en el arreglo de jugadores
			cout << endl << endl << "Registrando jugador : " << objjugador->GetNombre() << endl;
			cout << endl << "Turno del jugador : " << objjugador->Get_turno_jugador() << endl;
			cout << endl << "Mostrando cartas..." << endl << endl;
			cout << "\nCarta N° \t\tNumero\t\tcolor\t\t tipo" << endl << endl;

			for (int w = 0; w < 7; w++)//reparte 7 cartas a todos los jugadores
			{
				objcartas = new cartas();
				r = rand() % (objbaraja->GetTamaño());//elige un numero
				objcartas = objbaraja->mostrar_carta(r);//elige la carta
				cout << w << "\t\t\t" << objcartas->GetNumero() << "\t\t" << objcartas->GetColor() << "\t\t " << objcartas->GetTipo(); cout << endl;

				objjugador->Agregar_cartas_jugador(objcartas);//mueve las cartas de la baraja al jugador
				objbaraja->eliminar_cartas(r);
			}
			turno++;
			MessageBox::Show("El jugador fue registrado");
			label2->Text = "Numero de jugadores registrados : " + objarreglo_j->GetnumeroJugadores() + "/4";
			text_Nombre->Clear();
		}
		if (n_repetidas == true)
		{
			MessageBox::Show("Ya existe un jugador con ese nombre");
		}
	}
	
	}
private: System::Void text_Nombre_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
};
}
