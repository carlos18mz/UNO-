#pragma once
#include "Conio.h"
#include "iostream"
#include <windows.h>
#include "conio.h"
#include "iostream"
#include "stdio.h"
#include <string>
#include "baraja_completa.h"

namespace UNO_V_8 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Eleccion_color
	/// </summary>
	public ref class Eleccion_color : public System::Windows::Forms::Form
	{
	public: 
		int opciones;

	public:
		Eleccion_color(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}
	public:

		int Set_eleccion_color()
		{
			return opciones;
			cout << "se selecciono restablecer";
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Eleccion_color()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btn_Amarillo;
	protected:
	private: System::Windows::Forms::Button^  btn_Verde;
	private: System::Windows::Forms::Button^  btn_Azul;
	private: System::Windows::Forms::Button^  btn_Rojo;
	private: System::Windows::Forms::Label^  lbl_Mensaje;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Eleccion_color::typeid));
			this->btn_Amarillo = (gcnew System::Windows::Forms::Button());
			this->btn_Verde = (gcnew System::Windows::Forms::Button());
			this->btn_Azul = (gcnew System::Windows::Forms::Button());
			this->btn_Rojo = (gcnew System::Windows::Forms::Button());
			this->lbl_Mensaje = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// btn_Amarillo
			// 
			this->btn_Amarillo->BackColor = System::Drawing::Color::Gold;
			this->btn_Amarillo->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_Amarillo->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_Amarillo->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->btn_Amarillo->Location = System::Drawing::Point(360, 132);
			this->btn_Amarillo->Name = L"btn_Amarillo";
			this->btn_Amarillo->Size = System::Drawing::Size(87, 30);
			this->btn_Amarillo->TabIndex = 9;
			this->btn_Amarillo->Text = L"Amarillo";
			this->btn_Amarillo->UseVisualStyleBackColor = false;
			this->btn_Amarillo->Click += gcnew System::EventHandler(this, &Eleccion_color::btn_Amarillo_Click);
			// 
			// btn_Verde
			// 
			this->btn_Verde->BackColor = System::Drawing::Color::LimeGreen;
			this->btn_Verde->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_Verde->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_Verde->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->btn_Verde->Location = System::Drawing::Point(270, 132);
			this->btn_Verde->Name = L"btn_Verde";
			this->btn_Verde->Size = System::Drawing::Size(84, 30);
			this->btn_Verde->TabIndex = 8;
			this->btn_Verde->Text = L"Verde";
			this->btn_Verde->UseVisualStyleBackColor = false;
			this->btn_Verde->Click += gcnew System::EventHandler(this, &Eleccion_color::btn_Verde_Click);
			// 
			// btn_Azul
			// 
			this->btn_Azul->BackColor = System::Drawing::Color::RoyalBlue;
			this->btn_Azul->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_Azul->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_Azul->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->btn_Azul->Location = System::Drawing::Point(172, 132);
			this->btn_Azul->Name = L"btn_Azul";
			this->btn_Azul->Size = System::Drawing::Size(92, 30);
			this->btn_Azul->TabIndex = 7;
			this->btn_Azul->Text = L"Azul";
			this->btn_Azul->UseVisualStyleBackColor = false;
			this->btn_Azul->Click += gcnew System::EventHandler(this, &Eleccion_color::btn_Azul_Click_1);
			// 
			// btn_Rojo
			// 
			this->btn_Rojo->BackColor = System::Drawing::Color::Firebrick;
			this->btn_Rojo->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_Rojo->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_Rojo->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->btn_Rojo->Location = System::Drawing::Point(71, 132);
			this->btn_Rojo->Name = L"btn_Rojo";
			this->btn_Rojo->Size = System::Drawing::Size(95, 30);
			this->btn_Rojo->TabIndex = 6;
			this->btn_Rojo->Text = L"Rojo";
			this->btn_Rojo->UseVisualStyleBackColor = false;
			this->btn_Rojo->Click += gcnew System::EventHandler(this, &Eleccion_color::btn_Rojo_Click);
			// 
			// lbl_Mensaje
			// 
			this->lbl_Mensaje->AutoSize = true;
			this->lbl_Mensaje->BackColor = System::Drawing::Color::Transparent;
			this->lbl_Mensaje->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Mensaje->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->lbl_Mensaje->Location = System::Drawing::Point(155, 53);
			this->lbl_Mensaje->Name = L"lbl_Mensaje";
			this->lbl_Mensaje->Size = System::Drawing::Size(199, 18);
			this->lbl_Mensaje->TabIndex = 5;
			this->lbl_Mensaje->Text = L"Elige el color de la mesa";
			// 
			// Eleccion_color
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(518, 215);
			this->Controls->Add(this->btn_Amarillo);
			this->Controls->Add(this->btn_Verde);
			this->Controls->Add(this->btn_Azul);
			this->Controls->Add(this->btn_Rojo);
			this->Controls->Add(this->lbl_Mensaje);
			this->ForeColor = System::Drawing::SystemColors::ControlDark;
			this->Name = L"Eleccion_color";
			this->Text = L"Eleccion_color";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		

private: System::Void btn_Azul_Click_1(System::Object^  sender, System::EventArgs^  e) {
	opciones = 3;

	cout << endl << endl << "=====================Se cambio el color de la baraja a azul====================="<<endl<<endl;
	Close();
}
private: System::Void btn_Rojo_Click(System::Object^  sender, System::EventArgs^  e) {
	opciones = 0;
	cout << endl << endl << "=====================Se cambio el color de la baraja a rojo=====================" << endl << endl;
	Close();
}
private: System::Void btn_Verde_Click(System::Object^  sender, System::EventArgs^  e) {
	opciones = 2;
	cout << endl << endl << "=====================Se cambio el color de la baraja a verde =====================" << endl << endl;
	Close();
}
private: System::Void btn_Amarillo_Click(System::Object^  sender, System::EventArgs^  e) {
	opciones = 1;
	cout << endl << endl << "=====================Se cambio el color de la baraja a amarillo=====================" << endl << endl;
	Close();
}
};
}
