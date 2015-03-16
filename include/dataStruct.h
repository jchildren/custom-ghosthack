#ifndef DATASTRUCT_H;
#define DATASTRUCT_H;

#include <string>
#include <ifstream>
#include <Eigen/Core>

struct data{
  MatrixXd inputs;
  MatrixXi outputs;
  unsigned classes;
  unsigned count;
  double bias;

}

struct dataSet{
  unsigned inputCount;
  unsigned outputCount;
  data trainingSet;
  data validationSet;
  data testSet;
}

class inputData {
public:

private:
  const char m_filePath;
  const std::string m_fileNames;
  std::ifstream m_myFile

}




#endif
