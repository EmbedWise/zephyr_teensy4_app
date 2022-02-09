#!/usr/bin/env python3

import subprocess
import os.path
import shutil
import sys

NUMBER_OF_DIRECTORIES_BACK_FOR_BUILD_DIR = 4
change_dir = "../" * NUMBER_OF_DIRECTORIES_BACK_FOR_BUILD_DIR

project_path = os.path.split(os.getcwd())[0]
project = os.path.basename(project_path)

# Go to the level of the build directory
os.chdir(change_dir)

isdir = os.path.isdir("build")
if not isdir:
    os.mkdir("build")

os.chdir('build')

isdir = os.path.isdir(f"{project}")
if isdir:
    shutil.rmtree(f"{project}")
    print("REMOVE BUILD DIR")

my_env = os.environ.copy()
my_env["BOARD"] = "teensy41"

subprocess.run(["west", "build", f"{project_path}", "-d", f"./{project}"], env=my_env)