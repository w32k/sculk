target("sculk")
    set_kind("static")
    add_includedirs("includes")
    add_files("src/sculk/renderer/ogl11.c", "src/sculk/window/rgfw.c", "src/extern/glad.c")



target("sculktest")
    set_kind("binary")
    add_deps("sculk")
    set_targetdir(".")
    add_includedirs("includes")
    add_files("src/main.c")
