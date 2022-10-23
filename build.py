import subprocess
import os

current_dir = os.getcwd()

cmd = "cmake --build "+\
      current_dir+\
      "/build --config Release --target ALL_BUILD -j 14 --"

subprocess.run(cmd, shell=True)

# for i in range(5):
#     subprocess.run("./build/Release/Main.exe")