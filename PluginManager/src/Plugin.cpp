#include "Plugin.h"

Plugin::Plugin(std::string patch): IPlugin(patch) {
}

Plugin::~Plugin() {
    //dtor
}

void * Plugin::ExecProcedure(std::string name) {
    auto proc = (LOADPPLUGIN)GetProcAddress(_lib, name.c_str());
    return proc();
}

bool Plugin::Unload() {
    ///надо знать не использует ли кто нибудь еще обьект из библиотеки
    return FreeLibrary(_lib);
}

bool Plugin::Load() {
    _lib = LoadLibrary("plugin/libPlugin.dll");
    if (_lib == NULL) {
        return false;
    }
    return true;
}
