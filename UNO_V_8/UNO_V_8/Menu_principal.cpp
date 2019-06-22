#include "Menu_principal.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	UNO_V_8::Menu_principal form;
	Application::Run(%form);
	return(0);
}