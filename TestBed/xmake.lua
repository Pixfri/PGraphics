target("TestBed")
  set_kind("binary")

  add_files("Source/**.c")
  
  for _, ext in ipairs({".h", ".inl"}) do
    add_headerfiles("Include/**" .. ext)
  end
  
  add_rpathdirs("$ORIGIN")

  add_deps("PGraphics")