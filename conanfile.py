#/*****************************************************************
# * Copyright (C) 2017 Robert Valler - All rights reserved.
# *
# * This file is part of the project: <insert project name here>
# *
# * This project can not be copied and/or distributed
# * without the express permission of the copyright holder
# *****************************************************************/

from conan import ConanFile
from conan.tools.cmake import cmake_layout
from conan.tools.files import copy
import os

class HMIStackRecipe(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeDeps", "CMakeToolchain"

    def requirements(self):
        self.requires("boost/1.88.0")
        self.requires("asio/1.36.0")        
        self.requires("gtest/1.17.0")
        self.requires("protobuf/6.32.1")
        self.requires("imgui/1.92.2b")
        self.requires("glfw/3.3.8")
        self.requires("glew/2.2.0")

    def layout(self):
        cmake_layout(self)

    def generate(self):
        # Copy ImGui backend files from the imgui package into your source tree so CMake can build them
        pkg = self.dependencies["imgui"].package_folder
        # the “res/bindings” folder in the ImGui package contains the backend .cpp/.h files
        copy(self,
             pattern="*glfw*",
             src=os.path.join(pkg, "res", "bindings"),
             dst=os.path.join(self.source_folder, "bindings"))
        copy(self,
             pattern="*opengl3*",
             src=os.path.join(pkg, "res", "bindings"),
             dst=os.path.join(self.source_folder, "bindings"))
