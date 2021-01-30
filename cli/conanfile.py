from conans import ConanFile, CMake
import os


class ClockifyCli(ConanFile):
    name = "clockify_cli"
    version = "0.1"
    license = "MIT"
    author = "Uilian Ries <uilianries@gmail.com>"
    url = "https://github.com/uilianries/clockify-cli"
    description = "Clockify CLI App"
    topics = ("clockify", "timetracker", "clock")
    settings = "os", "arch"
    exports_sources = ["clockify_cli.hpp", "clockify_cli.cpp", "main.cpp", "CMakeLists.txt"]
    generators = "cmake"
    _cmake = None

    def requirements(self):
        self.requires("clockify_consumer/0.1@uilianries/testing")
        self.requires("lyra/1.5.1")

    def _configure_cmake(self):
        if not self._cmake:
            self._cmake = CMake(self)
            self._cmake.configure()
        return self._cmake

    def build(self):
        cmake = self._configure_cmake()
        cmake.build()

    def package(self):
        cmake = self._configure_cmake()
        cmake.install()

    def package_info(self):
        bin_path = os.path.join(self.package_folder, "bin")
        self.env_info.PATH.append(bin_path)
