import subprocess
import os

current_dir = os.getcwd()

try:
      cmd = "cmake --no-warn-unused-cli "+\
            "-DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE"+\
            " -S"+current_dir+\
            " -B"+current_dir+\
            "/build -G \"Visual Studio 16 2019\" -T host=x86 -A x64"
      subprocess.run(cmd, shell=True)  
      cmd = "cmake --build "+\
      current_dir+\
      "/build --config Release --target ALL_BUILD -j 14 --"
      subprocess.run(cmd, shell=True)      
      subprocess.run("./build/Release/main.exe") # required libtorch/release/lib/*.dll files
except:
      print("find linux...")
      cmd = "/usr/bin/cmake --no-warn-unused-cli "+\
            "-DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE "+\
            "-DCMAKE_BUILD_TYPE:STRING=Release "+\
            "-DCMAKE_C_COMPILER:FILEPATH=/usr/bin/clang "+\
            "-DCMAKE_CXX_COMPILER:FILEPATH=/usr/bin/clang++ "+\
            "-S"+\
            current_dir+\
            " -B"+current_dir+"/build"\
            " -G Ninja"
      print(cmd)
      subprocess.run(cmd, shell=True)
      cmd = "/usr/bin/cmake --build "+\
            current_dir+\
            "/build --config Release --target main --"
      subprocess.run(cmd, shell=True)
      subprocess.run("./build/main", shell=True)
finally:
      print("finished.")