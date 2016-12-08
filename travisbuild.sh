sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-6 100 --slave /usr/bin/g++ g++ /usr/bin/g++-6
g++ -v
cmake --version

if [ ! -d "/boost_1_62_0/bin.v2/" ];
  wget http://kent.dl.sourceforge.net/project/boost/boost/1.62.0/boost_1_62_0.tar.bz2
  tar -xjf boost_1_62_0.tar.bz2
  cd boost_1_62_0/
  sudo ./bootstrap.sh
  sudo ./b2 install -j 8
  cd ..
  cmake -DBOOST_ROOT=/boost_1_62_0/ . && make
fi
