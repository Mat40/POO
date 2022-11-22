#include "MainForm.h"


using namespace System;
using namespace System::Windows::Forms;


[STAThreadAttribute]
int __clrcall main(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    MAIN1::MainForm IHM;
    Application::Run(% IHM);
}