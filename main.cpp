#include <iostream>
//#include <boost/endian/conversions.hpp>
#include <boost/filesystem.hpp>

namespace fs = boost::filesystem;

int main(int argc, char** argv)
{
  if (argc != 2)
  {
    std::cerr << "Usage: <folder>";
    return 1;
  }
  
  fs::path path(argv[1]);
  if (!fs::exists(path) || !fs::is_directory(path))
  {
    std::wcerr << path.wstring() + L" does not exists or isn't a directory.";
    return 2;
  }

  return 0;
}
