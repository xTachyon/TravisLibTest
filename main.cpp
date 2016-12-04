#include <iostream>
#include <boost/filesystem.hpp>
#include <boost/endian/conversion.hpp>

namespace fs = boost::filesystem;

int main(int argc, char** argv)
{
  fs::path path;
  if (argc == 2) path = argv[1];
  else
  {
    std::wstring str;
    std::getline(std::wcin, str);
    path = str;
  }

  if (!fs::exists(path) || !fs::is_directory(path))
  {
    std::wcerr << path.wstring() + L" does not exists or isn't a directory.";
    return 3;
  }

  for (const auto& index : fs::recursive_directory_iterator(path))
    std::wcout << index.path().wstring() << L'\n';

  int x = 5;
  for (int i = 0; i < sizeof(int); ++i)
    std::cout << static_cast<int>(reinterpret_cast<const std::uint8_t*>(&x)[i]) << ' ';
  std::cout << '\n';

  boost::endian::native_to_big_inplace(x);
  for (int i = 0; i < sizeof(int); ++i)
    std::cout << static_cast<int>(reinterpret_cast<const std::uint8_t*>(&x)[i]) << ' ';

  return 1;
}
