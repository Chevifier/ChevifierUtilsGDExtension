env = SConscript('godot-cpp/SConstruct')

env.Append(CPPPATH="src/")

src = Glob("src/*.cpp")


if env['platform'] == 'linux':
    libpath = '../bin/ChevifierUtils{}{}'.format( env['suffix'], env['SHLIBSUFFIX'] )
    sharedlib = env.SharedLibrary(libpath,src)
    Default(sharedlib)
elif env['platform'] == 'windows':
    libpath = '../bin/ChevifierUtils{}{}'.format( env['suffix'], env['SHLIBSUFFIX'] )
    sharedlib = env.SharedLibrary(libpath,src)
    Default(sharedlib)
    pass
elif env['platform'] == 'android':
    pass
