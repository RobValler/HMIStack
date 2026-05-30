

#include <wx/wx.h>

#include <string>

class MyText : public wxStaticText {
public:
    MyText(wxWindow* parent, std::string label, int x, int y);

private:
    void OnPaint(wxPaintEvent&);
    std::string mLabel{""};
};
