#include <fstream>
#include <iostream>

int main(int argc, char *argv[]) {
  // make sure we have enough arguments
  if (argc < 2) {
    return 1;
  }

  std::ofstream fout(argv[1], std::ios_base::out);
  const bool fileOpen = fout.is_open();
  if (fileOpen) {
    fout << "#include <iostream>" << std::endl << std::endl;
    fout << "void sayHello() {" << std::endl;
    fout << "  std::cout << \"Hello, World!\" << std::endl;" << std::endl;
    fout << "};" << std::endl;
    fout.close();
  }
  return fileOpen ? 0 : 1; // return 0 if wrote the file
}
