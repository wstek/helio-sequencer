import os


def fast_scandir(dirname):
    subfolders = [f.path for f in os.scandir(dirname) if f.is_dir()]
    for dirname in subfolders:
        subfolders.extend(fast_scandir(dirname))
    return subfolders


def print_result(subfolders):
    print("${CMAKE_CURRENT_LIST_DIR}")
    for subfolder in subfolders:
        print("${CMAKE_CURRENT_LIST_DIR}" + subfolder.replace("\\", "/")[1:])


if __name__ == "__main__":
    print_result(fast_scandir("./"))
