
#ifndef GUI_HNDL_DEARIMGUI__H
#define GUI_HNDL_DEARIMGUI__H

#include "base_types.h"

#include "i_gui_hndl.h"

#include <string>
#include <thread>
#include <atomic>
#include <mutex>


class CGuiHndlDearImGui : public IGuiHndl
{
public:
    CGuiHndlDearImGui(const SCmdLineParm& parm) : mParm(parm){};
    ~CGuiHndlDearImGui() override =default;
    void Start() override;
    void Stop() override;
    void Update(std::string gui_operator, std::string gui_operand) override;
    void SetCommand(const std::string& gui_operator, const std::string& gui_operand) override;
    void GetCommand(std::string& gui_operator, std::string& gui_operand) override;

private:
    SCmdLineParm mParm;
    std::atomic<bool> mIsExistRequest{false};
    std::thread mtGuiHandler;
    void ThreadFuncServer();

    std::string mCommandGUIoperator;
    std::string mCommandGUIoperand;
    std::mutex mCommandAccessMutex;

    std::string mUpdateGUIoperator;
    std::string mUpdateGUIoperand;
    std::mutex mUpdateAccessMutex;

    std::atomic<bool> mCommandChange{false};
};

#endif // GUI_HNDL_DEARIMGUI__H
