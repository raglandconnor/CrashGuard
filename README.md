# COP3530 Project 3 - CrashGuard
Our project explores the performance of hashmaps and heaps by comparing how effectively each data structure can retrieve the top k elements. 
- Language: C++ 20
- Compiler: GCC 13.2

Group Report: [link](https://drive.google.com/file/d/1D6bEjlnPTLO0aULwlZJOSo67gKgW0Rw_/view?usp=sharing)

## Project Directory:
- `resources`
  - `US_Accidents_March23.csv`: contains the dataset from [Kaggle](https://www.kaggle.com/datasets/sobhanmoosavi/us-accidents?resource=download)
- `src`
  - `AttributeData.h`: contains a struct that is used by both data structures
  - `DataNode.h`: contains a struct that is used to contain a single crash and all its data when parsing
  - `HashMap.cpp`
  - `HashMap.h`
  - `Heap.cpp`
  - `Heap.h`
  - `main.cpp`

## Instructions for Running:

### Clone Repository
```
cd [where you want to download]
git clone https://github.com/raglandconnor/CrashGuard
```

### Place Dataset in Directory
1. Download [US vehicle crash dataset](https://www.kaggle.com/datasets/sobhanmoosavi/us-accidents?resource=download)
2. Place inside `resources` folder

### Create Compiled Program
```
g++ -std=c++17 -c src/main.cpp -o main.o && g++ -std=c++17 -c src/HashMap.cpp -o HashMap.o && g++ -std=c++17 -c src/Heap.cpp -o Heap.o && g++ -std=c++17 main.o HashMap.o Heap.o -o CrashGuard
```

### Execute
```
./CrashGuard
```


#### References:
[US Accidents (2016 - 2023) Dataset](https://www.kaggle.com/datasets/sobhanmoosavi/us-accidents?resource=download)
- Moosavi, Sobhan, Mohammad Hossein Samavatian, Srinivasan Parthasarathy, and Rajiv Ramnath. “A Countrywide Traffic Accident Dataset.”, 2019.
- Moosavi, Sobhan, Mohammad Hossein Samavatian, Srinivasan Parthasarathy, Radu Teodorescu, and Rajiv Ramnath. "Accident Risk Prediction based on Heterogeneous Sparse Data: New Dataset and Insights." In proceedings of the 27th ACM SIGSPATIAL International Conference on Advances in Geographic Information Systems, ACM, 2019.
