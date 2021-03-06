/*
*           Win64Tools (c) Copyright 2022 by Ludwig F?chsl
*
*
* Boost Software License - Version 1.0 - August 17th, 2003
*
* Permission is hereby granted, free of charge, to any person or organization
* obtaining a copy of the software and accompanying documentation covered by
* this license (the "Software") to use, reproduce, display, distribute,
* execute, and transmit the Software, and to prepare derivative works of the
* Software, and to permit third-parties to whom the Software is furnished to
* do so, all subject to the following:
*
* The copyright notices in the Software and this entire statement, including
* the above license grant, this restriction and the following disclaimer,
* must be included in all copies of the Software, in whole or in part, and
* all derivative works of the Software, unless such copies or derivative
* works are solely in the form of machine-executable object code generated by
* a source language processor.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
* SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
* FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
* ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
* DEALINGS IN THE SOFTWARE.
*/
#pragma once

#include "../WinInclude.h"

#include <initializer_list>

namespace w64t::dialogs
{
    // Result of dialog invocation
    enum class DialogResult
    {
        OK,
        Yes,
        No,
        Cancle,
        Abort,
        Retry,
        TryAgain,
        Ignore,
        Continue,
    };

    // Icon of the dialog
    enum class DialogIcon
    {
        None,
        Exclamation,
        Warning,
        Information,
        Asterisk,
        Question,
        Stop,
        Error,
        Hand,
    };

    // Dialog buttons
    enum class DialogButton
    {
        None,
        OK,
        Yes,
        No,
        Cancle,
        Abort,
        Retry,
        TryAgain,
        Ignore,
        Continue,
    };

    // Set of buttons
    class DialogButtons
    {
        public:
            // Default behavior
            DialogButtons() = default;
            DialogButtons(const DialogButtons&) = default;
            DialogButtons& operator=(const DialogButtons&) = default;
            
            // Construct with buttons
            DialogButtons(const std::initializer_list<DialogButton>& btns);

            // Add/Remove buttons
            bool Add(const DialogButton& btn) noexcept;
            void Remove(const DialogButton& btn) noexcept;

            // Clear list
            inline void Clear() noexcept
            {
                m_ButtonCount = 0;
            }

            // Check for existence
            bool Check(const DialogButton& btn) const noexcept;
            bool Check(const DialogButtons& subset) const noexcept;

            // Size and get
            inline unsigned int Size() const noexcept
            {
                return m_ButtonCount;
            }
            inline DialogButton Get(unsigned int index) const noexcept
            {
                return index < m_ButtonCount ? m_Buttons[index] : DialogButton::None;
            }

            // Operator access
            DialogButton operator[](unsigned int index) const noexcept
            {
                return Get(index);
            }

            // Check if equal / exists
            bool operator==(const DialogButtons& other) const noexcept;
            bool operator==(const std::initializer_list<DialogButton>& btns) const noexcept;
            inline bool operator==(const DialogButton& btn) const noexcept
            {
                return m_ButtonCount == 1 && m_Buttons[0] == btn;
            }

            // Fancy add
            template<typename... T>
            void Add(const DialogButton& btn, T... args)
            {
                Add(btn);
                Add(args...);
            }
            template<typename T>
            void Add(const DialogButton& btn, T arg)
            {
                Add(btn);
                Add(arg);
            }
            // Fancy remove
            template<typename... T>
            void Remove(const DialogButton& btn, T... args)
            {
                Remove(btn);
                Remove(args...);
            }
            template<typename T>
            void Remove(const DialogButton& btn, T arg)
            {
                Remove(btn);
                Remove(arg);
            }

            // operator add
            inline DialogButtons& operator+=(const DialogButton& btn) noexcept
            {
                Add(btn);
                return *this;
            }
            inline DialogButtons& operator<<(const DialogButton& btn) noexcept
            {
                Add(btn);
                return *this;
            }

            // operator remove
            inline DialogButtons& operator-=(const DialogButton& btn) noexcept
            {
                Remove(btn);
                return *this;
            }
            inline DialogButtons& operator>>(const DialogButton& btn) noexcept
            {
                Remove(btn);
                return *this;
            }

        private:
            // Button set
            DialogButton m_Buttons[8];
            unsigned int m_ButtonCount = 0;
    };

    // Base dialog implementation
    class DialogBase
    {
        public:
            // Displays the dialog to the user (THIS IS A BLOCKING CALL!)
            virtual DialogResult ShowDialog() = 0;

        public:
            // Result of the dialog (read/write)
            DialogResult Result = DialogResult::OK;
            // Icon that should be displayed in the dialog
            DialogIcon Icon = DialogIcon::None;
            // Buttons of the dialog (Not all Dialogs will support any combination!)
            DialogButtons Buttons;
    };
}


