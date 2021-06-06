In your command line enter:

$ conan profile update settings.compiler.libcxx=libstdc++11 default

$ conan install ..
$ cmake ..
$ make

and you are ready to go!
