#include <iostream>
#include <boost/filesystem.hpp>
#include <boost/endian/conversion.hpp>
#include <json.hpp>
#include <openssl/bio.h>
#include <openssl/buffer.h>
#include <openssl/evp.h>

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

  for (const auto& index : fs::recursive_directory_iterator(path))
    std::wcout << index.path().wstring() << L'\n';
  
  const void* p;
  BIO* bio = BIO_new_mem_buf(p, -1);

  return -2;
}
