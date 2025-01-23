![VTable list](https://github.com/user-attachments/assets/a7ff4e27-4c39-4ec5-b237-09327f82abf5)
# 🔀 classinformer-gcc

Class Informer plugin is designed to search for virtual tables in executables compiled with GCC/Clang. This tool may help in reverse engineering class structures and vtable addresses, making the analysis of C++ binaries more efficient.

# 🛠️ building 
To build the plugin follow the steps:
```
git clone https://github.com/sgp729/classinformer-gcc.git
cd class-informer
```
Then, obtain `SDK for IDA Pro` archive from the Hex-Rays [download center](https://my.hex-rays.com/dashboard/download-center/downloads) <br>
Decompress the archive and put your arch SDK into `classinformer-gcc/idasdk9` <br>
```
make
```
Copy the resulting binary `class_informer_gcc.so` into `IDA Pro 9/plugins` 

# 🙋 contribution
For any issues or contributions, please refer to the issues section. Good luck in analysis!
