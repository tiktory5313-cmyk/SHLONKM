# Shirazi Tools

# Description
Shirazi's tools are simple to program but highly productive, written in C++. Their primary purpose is to facilitate and expedite the handling of all types of encryption protocols. Our tools may be used illegally, and we are certainly not responsible for such actions.

# Install version 1.1
## debian and ubuntu
Install the necessary files and run the tool V 1.1
~~~ bash
sudo apt update
sudo apt install build-essential libssl-dev libboost-all-dev

git clone https://github.com/tiktory5313-cmyk/SHLONKM.git
cd SHLONKM/'Shirazi tools'

g++ -std=c++17 Shirazi_V_1.1.cpp -o shirazi_tool_V1 -lssl -lcrypto
./shirazi_tool_V1
~~~

## fedora linux and RHEL
 ~~~ bash
sudo dnf install gcc-c++ openssl-devel boost-devel

git clone https://github.com/tiktory5313-cmyk/SHLONKM.git
cd SHLONKM/'Shirazi tools'

g++ -std=c++17 Shirazi_V_1.1.cpp -o shirazi_tool_V1 -lssl -lcrypto
./shirazi_tool_V1
~~~

## Arch Linux
~~~ bash
sudo pacman -S base-devel openssl boost

git clone https://github.com/tiktory5313-cmyk/SHLONKM.git
cd SHLONKM/'Shirazi tools'

g++ -std=c++17 Shirazi_V_1.1.cpp -o shirazi_tool_V1 -lssl -lcrypto
./shirazi_tool_V1
~~~

# Install version 2.2
## debian and ubuntu
Install the necessary files and run the tool V 2.2
~~~ bash
sudo apt update
sudo apt install build-essential libssl-dev libboost-all-dev figlet lolcat

git clone https://github.com/tiktory5313-cmyk/SHLONKM.git
cd SHLONKM/'Shirazi tools'

g++ -std=c++17 Shirazi_V_2.2.cpp -o shirazi_tool_V2 -lssl -lcrypto
./shirazi_tool_V2
~~~

## fedora linux and RHEL
~~~ bash
sudo dnf install gcc-c++ openssl-devel boost-devel figlet
sudo gem install lolcat

git clone https://github.com/tiktory5313-cmyk/SHLONKM.git
cd SHLONKM/'Shirazi tools'

g++ -std=c++17 Shirazi_V_2.2.cpp -o shirazi_tool_V2 -lssl -lcrypto
./shirazi_tool_V2
~~~

## Arch Linux
~~~ bash
sudo pacman -Syu base-devel openssl boost figlet lolcat

git clone https://github.com/tiktory5313-cmyk/SHLONKM.git
cd SHLONKM/'Shirazi tools'

g++ -std=c++17 Shirazi_V_2.2.cpp -o shirazi_tool_V2 -lssl -lcrypto
./shirazi_tool_V2
~~~
