import os
# import re
# import codecs


class Formatter:
    def __init__(self) -> None:
        self.base_dir = os.path.dirname(os.path.dirname(os.path.realpath(__file__)))
        self.__files_to_be_formatted = []

    def _search_cpp_files(self, dir: str) -> None:
        if os.path.isfile(dir) and (dir.endswith(".cpp") or dir.endswith(".h")):
            self.__files_to_be_formatted.append(dir)
        elif os.path.isdir(dir):
            for d in os.listdir(dir):
                self._search_cpp_files(os.path.join(dir, d))

    def __format(self, f: str) -> None:
        try:
            with open(f, mode="r", encoding="utf-8-sig") as file:
                data = file.read()
            with open(f, mode="w+", encoding="utf-8") as file:
                file.write(data)
            print("SUCCESS: utf-8-sig-->utf-8 ", f)
            return
        except UnicodeDecodeError:
            print("FAIL: utf-8-sig-->utf-8 ", f)
        try:
            with open(f, mode="r", encoding="gb2312") as file:
                data = file.read()
            with open(f, mode="w+", encoding="utf-8") as file:
                file.write(data)
            print("SUCCESS: gb2312-->utf-8 ", f)
        except UnicodeDecodeError:
            print("FAIL: gb2312-->utf-8 ", f)

    def run(self) -> None:
        self._search_cpp_files(self.base_dir)
        for file in self.__files_to_be_formatted:
            self.__format(file)


if __name__ == "__main__":
    fmt = Formatter()
    fmt.run()
