#include <w64t/Dialogs.h>

#pragma comment(linker,"\"/manifestdependency:type='win32' \
name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

int main(int argc, char** argv)
{
    w64t::dialogs::MsgBox box;
    w64t::dialogs::MsgBox_CStr<char> box;
    box.Buttons << w64t::dialogs::DialogButton::Cancle << w64t::dialogs::DialogButton::Yes << w64t::dialogs::DialogButton::No;
    box.Icon = w64t::dialogs::DialogIcon::Error;
    box.Title << "My App " << "NAME";
    box.Text << "This is a nice " << 500 << " top plus MessageBox!";
    box.ShowDialog();

    MessageBoxA(NULL, "A", "B", MB_ICONERROR | MB_YESNOCANCEL);

    return 0;
}
