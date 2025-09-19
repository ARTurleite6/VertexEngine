set_languages("cxx23")

add_requires("spdlog", "glfw", "glm", "glad")
set_warnings("allextra", "pedantic", "error")

target("Sidekick")
add_files("src/**.cpp")
add_includedirs("src")
add_packages("spdlog", "glfw", "glm", "glad")

set_pcxxheader("src/vepch.h")
