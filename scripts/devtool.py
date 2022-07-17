import sys
import os
import subprocess

def runscript(name):
    script_path = f"./scripts/{name}.py"
    if(os.path.exists(script_path)):
        print(f">> Running action \"{name}\"")
        script_argv = sys.argv[2::]
        subprocess.call(["py", script_path, *script_argv])
    else:
        print(f">> Action \"{name}\" not found")

if __name__ == "__main__":
    argument_count = len(sys.argv)
    if(argument_count < 2):
        print(f">> Usage: devtool <ACTION> [ARGS]")
    else:
        action = sys.argv[1].lower()
        runscript(action)
            
