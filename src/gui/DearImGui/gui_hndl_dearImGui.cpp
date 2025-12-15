/*****************************************************************
 * Copyright (C) 2025 Robert Valler - All rights reserved.
 *
 * This file is part of the project: <insert project name here>
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#include "gui_hndl_dearImGui.h"

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <GLFW/glfw3.h>

#include <iostream>

void CGuiHndlDearImGui::Start() {

    mtGuiHandler = std::thread(&CGuiHndlDearImGui::ThreadFuncServer, this);
}

void CGuiHndlDearImGui::Stop() {

    mtGuiHandler.join();
}

void CGuiHndlDearImGui::Update(std::string gui_operator, std::string gui_operand) {

    const std::lock_guard<std::mutex> lock(mUpdateAccessMutex);
    mUpdateGUIoperator = gui_operator;
    mUpdateGUIoperand = gui_operand;
}

void CGuiHndlDearImGui::SetCommand(const std::string& gui_operator, const std::string& gui_operand) {

    const std::lock_guard<std::mutex> lock(mCommandAccessMutex);
    mCommandGUIoperator = gui_operator;
    mCommandGUIoperand = gui_operand;
    mCommandChange = true;
}

void CGuiHndlDearImGui::GetCommand(std::string& gui_operator, std::string& gui_operand) {

    const std::lock_guard<std::mutex> lock(mCommandAccessMutex);
    if(mCommandChange) {
        gui_operator = mCommandGUIoperator;
        gui_operand = mCommandGUIoperand;
        mCommandChange = false;
    }
}

void CGuiHndlDearImGui::ThreadFuncServer() {

    if (!glfwInit()) {
        std::cerr << "Failed to init GLFW\n";
        return;
    }
    const char* glsl_version = "#version 330";
    GLFWwindow* window = glfwCreateWindow(800, 600, "My ImGui App", nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        return;
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);  // vsync

    // Setup ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    (void)io;

    // Initialize ImGui backends
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);

    // variables
    std::string local_test_string;

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // get app events
        mUpdateAccessMutex.lock();
        local_test_string = "Test data: operator = " + mUpdateGUIoperator + ", operand = " + mUpdateGUIoperand;
        mUpdateAccessMutex.unlock();

// ############ HMI START ############
        // ## Create the app screen ##

        // set the global parameters
        ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(0,0,0,255));
        ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.9f, 0.9f, 0.9f, 1.0f));

        // create the veiwing window
        ImGui::Begin( "Welcome Adventurer!!",
            NULL,
            ImGuiWindowFlags_NoTitleBar |
            ImGuiWindowFlags_NoResize |
            ImGuiWindowFlags_NoMove );

        ImGui::SetWindowSize(ImGui::GetIO().DisplaySize);   // set the window size
        ImGui::SetWindowPos(ImVec2(0, 0));  // make sure the window starts at the top left
        ImGui::SetWindowFontScale(1.05); // set the global font scale

        // ## Add the GUI elements ##
        // text box
        ImGui::SetCursorPos(ImVec2(250,400));
        ImGui::Text("%s", local_test_string.c_str());

        // Button: test cmd message
        ImGui::SetCursorPos(ImVec2(20,40));
        if( ImGui::Button("Test button", ImVec2(110, 80)) ) {
            SetCommand("test_send", "x");
        }

        // Button: send file
        ImGui::SetCursorPos(ImVec2(20,130));
        if( ImGui::Button("File Button", ImVec2(110, 80)) ) {
            SetCommand("file_transfer", "this_is_a_test_file_name_and_wont_work.txt");
        }

        // ## end ##
        ImGui::End();

        ImGui::PopStyleColor();
        ImGui::PopStyleColor();
// ############ HMI STOP ############



        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(0.45f, 0.55f, 0.6f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
    }

    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwDestroyWindow(window);
    glfwTerminate();

    // send the program stop command
    SetCommand("program_status", "stop");

}
