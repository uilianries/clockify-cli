from conans import ConanFile, CMake


class ClockifyConsumerConan(ConanFile):
    name = "clockify_consumer"
    version = "0.1"
    license = "MIT"
    author = "Uilian Ries <uilianries@gmail.com>"
    url = "https://github.com/uilianries/clockify-cli"
    description = "Clockify library consumer"
    topics = ("clockify", "timetracker", "clock")
    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False], "fPIC": [True, False]}
    default_options = {"shared": False, "fPIC": True}
    exports_sources = ["clockify_consumer.hpp", "clockify_consumer.cpp", "CMakeLists.txt"]
    generators = "cmake", "cmake_find_package_multi"
    requires = ["nlohmann_json/3.9.1", "cpr/1.5.2"]
    _cmake = None

    def config_options(self):
        if self.settings.os == "Windows":
            del self.options.fPIC

    def validate(self):
        if self.options.shared:
            del self.options.fPIC

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
        self.cpp_info.libs = [self.name]

