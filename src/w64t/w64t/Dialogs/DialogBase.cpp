#include "DialogBase.h"

w64t::dialogs::DialogButtons::DialogButtons(const std::initializer_list<DialogButton>& btns)
{
    // Add all buttons
    for (auto& btn : btns)
    {
        Add(btn);
    }
}

bool w64t::dialogs::DialogButtons::Add(const DialogButton& btn) noexcept
{
    bool canAdd = m_ButtonCount != 8;
    for (unsigned int i = 0; i < m_ButtonCount && canAdd; i++)
    {
        if (m_Buttons[i] == btn)
        {
            canAdd = false;
        }
    }
    if (canAdd)
    {
        m_Buttons[m_ButtonCount++] = btn;
    }

    return canAdd;
}

void w64t::dialogs::DialogButtons::Remove(const DialogButton& btn) noexcept
{
    // Find button
    for (unsigned int i = 0; i < m_ButtonCount; i++)
    {
        if (btn == m_Buttons[i])
        {
            // Bring back other buttons
            for (unsigned int j = i; j < m_ButtonCount - 1; j++)
            {
                m_Buttons[j] = m_Buttons[j + 1];
            }

            // Stop search
            m_ButtonCount--;
            break;
        }
    }
}

bool w64t::dialogs::DialogButtons::Check(const DialogButton& btn) const noexcept
{
    // Find button
    bool found = false;
    for (unsigned int i = 0; i < m_ButtonCount && !found; i++)
    {
        if (m_Buttons[i] == btn)
        {
            found = true;
        }
    }

    return found;
}

bool w64t::dialogs::DialogButtons::Check(const DialogButtons& subset) const noexcept
{
    bool isSuperset = true;
    for (unsigned int i = 0; i < subset.m_ButtonCount && isSuperset; i++)
    {
        if (!Check(subset.m_Buttons[i]))
        {
            isSuperset = false;
        }
    }

    return isSuperset;
}

bool w64t::dialogs::DialogButtons::operator==(const DialogButtons& other) const noexcept
{
    // Check all buttons
    bool equal = other.m_ButtonCount == m_ButtonCount;
    for (unsigned int i = 0; i < m_ButtonCount && equal; i++)
    {
        if (!other.Check(m_Buttons[i]))
        {
            equal = false;
        }
    }

    return equal;
}

bool w64t::dialogs::DialogButtons::operator==(const std::initializer_list<DialogButton>& btns) const noexcept
{
    bool equal = true;
    for (auto& btn : btns)
    {
        if (!Check(btn))
        {
            equal = false;
        }
    }
    
    return true;
}
