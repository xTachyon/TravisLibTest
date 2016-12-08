set -x
sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-6 100 --slave /usr/bin/g++ g++ /usr/bin/g++-6

if [ ! -f "boost_1_62_0/b2" ]; then
  wget http://kent.dl.sourceforge.net/project/boost/boost/1.62.0/boost_1_62_0.tar.bz2
  tar -xjf boost_1_62_0.tar.bz2
  cd boost_1_62_0/
  sudo ./bootstrap.sh --prefix=libs/boost/
  sudo ./b2 install -j 8
  cd ..
fi

ls boost_1_62_0/
ls libs/boost/
cmake -DBoost_INCLUDE_DIRS=libs/boost/include/ -DBOOST_LIBRARYDIR=/libs/boost/lib
make
