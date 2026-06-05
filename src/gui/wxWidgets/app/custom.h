

#include <wx/wx.h>

#include <string>

class CTextTransparent : public wxStaticText {
public:
    CTextTransparent(wxWindow* parent, std::string label, int x, int y);

private:
    void OnPaint(wxPaintEvent&);
    std::string mLabel{""};
};
