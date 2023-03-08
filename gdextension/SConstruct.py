env = SConscript('godot-cpp/SConstruct')

# tweak this if you want to use different folders, or more folders, to store your source code in.
env.Append(CPPPATH="src/")
src = Glob("src/*.cpp")


if env['platform'] == 'macos':
    libpath = '../bin/ChevifierUtils.{}.{}.framework/ChevifierUtils.{}.{}'.format( env['platform'], env['target'],env['platform'], env['target'] )
    library = env.SharedLibrary(libpath,src)

else:
    libpath = '../bin/ChevifierUtils{}{}'.format( env['suffix'], env['SHLIBSUFFIX'] )
    library = env.SharedLibrary(libpath,src)

Default(library)

