import subprocess
import platform

if __name__ == "__main__":
    # Validate windows
    if platform.system().lower() == "windows":
        print(f"Generating project...")
        subprocess.call(["./bin/vendor/premake5", "vs2022"])
    else:
        print(f"Win64Tools only support windows compilation")
