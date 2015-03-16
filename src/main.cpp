//main.cpp

#include <iostream>
#include <ifstream>
#include <string>
#include <cmath>
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

void readDataFiles(){
  dataSet irisData;

  const char filePath[20] = "../data/";

  const std::string fileNames[3] =
    {"iris_training.dat",
    "iris_test.dat",
    "iris_validation.dat"};

  std::ifstream myFile;

  for (unsigned f=1; f <= 3; ++f){

    myFile.open (filePath + fileNames[f].c_str());

    for (unsigned i=1; myFile.good(); ++i){
      for (unsigned j=1; j <= 4; ++j){
        myFile >> irisData.trainingSet.inputs(j, i)
      }
      for (unsigned j=1; j <= 3; ++j){
        myFile >> irisData.trainingSet.inputs(j, i)
      }
    }

    myFile.close();
  }

}


double activationFunction(double x){
  return (tanh(x) + 1)/2;
}

double activationFunctionDerivative(double x){
  return (1 - (tanh(x)**2))/2;
}

void checkColumns(MatrixXi &Matrix, VectorXi &Vector){
  if (Matrix.cols() /= Vector.rows()){
      std::cout << "Mismatch between output matrix columns and class vector rows" << std::endl;
      exit (EXIT_FAILURE);
  }
}

void outputToClass(int n, MatrixXi &outputMatrix, VectorXi &classVector){

  checkColumns(outputMatrix, classVector);

  for (unsigned i=1; i <= n; ++i){
    for (unsigned j=1; j <= 3; ++j){
      if (outputMatrix(i, j) == 1){
        classVector(i) = j;
      }
    }
  }
}

void outputToMatrix(int n, MatrixXi &outputMatrix, VectorXi &classVector){

  checkColumns(outputMatrix, classVector);

  for (unsigned i=1; i <= n; ++i){
    for (unsigned j=1; j <= 3; ++j){
      if (classVector(i) == j){
        outputMatrix(i, j) = 1;
      }
      else {
        outputMatrix(i, j) = 0;
      }
    }
  }
}


int main (){


  return 0;
}
