#include <w64t/Dialogs.h>

class xd : public w64t::dialogs::DialogBase
{

public:
    w64t::dialogs::DialogResult ShowDialog() override
    {
        return w64t::dialogs::DialogResult::OK;
    }

};

int main(int argc, char** argv)
{
    xd diag;
    diag.Buttons << w64t::dialogs::DialogButton::OK
                 << w64t::dialogs::DialogButton::Yes
                 << w64t::dialogs::DialogButton::No
    ;

    return 0;
}
