set_xmakever("2.9.3")

set_project("PGraphics")

add_rules("mode.debug", "mode.release")
set_languages("clatest")

option("override_runtime", {description = "Override VS runtime to MD in release and MDd in debug.", default = true})
option("static", {description = "Link the library statically.", default = false})

add_includedirs("Include")

add_rules("plugin.vsxmake.autoupdate")

if is_mode("release") then
  set_fpmodels("fast")
  set_optimize("fastest")
  set_symbols("debug", "hidden")
else
  add_defines("PG_DEBUG")
end

set_encodings("utf-8")
set_languages("clatest")
set_rundir("./bin/$(plat)_$(arch)_$(mode)")
set_targetdir("./bin/$(plat)_$(arch)_$(mode)")
set_warnings("allextra")

if is_plat("windows") then
  if has_config("override_runtime") then
    set_runtimes(is_mode("debug") and "MDd" or "MD")
  end
end

if is_plat("windows") then 
  add_defines("FL_PLATFORM_WINDOWS")
elseif is_plat("linux") then
  add_defines("FL_PLATFORM_LINUX")
elseif is_plat("android") then
  add_defines("FL_PLATFORM_LINUX", "FL_PLATFORM_ANDROID")
elseif is_plat("iphoneos") then
  add_defines("FL_PLATFORM_IOS", "FL_PLATFORM_APPLE")
elseif is_plat("macosx") then
  add_defines("FL_PLATFORM_MACOS", "FL_PLATFORM_APPLE")
end

add_cxflags("-Wno-missing-field-initializers -Werror=vla", {tools = {"clang", "gcc"}})

target("PGraphics")
  if has_config("static") then
    add_defines("PG_STATIC")
    set_kind("static")
  else
    set_kind("shared")
  end

  add_defines("PG_BUILD")

  add_files("Source/**.c")
  
  for _, ext in ipairs({".h", ".inl"}) do
    add_headerfiles("Include/**" .. ext)
  end
  
  add_rpathdirs("$ORIGIN")

includes("xmake/**.lua")
includes("TestBed/xmake.lua")