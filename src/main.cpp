//main.cpp

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <Eigen/Core>

matrixXd weightInitialisation(double maxWeight, int width, int height){

  matrixXd weights(width, height);

  for (unsigned i=1; i <= width; ++i){
    for (unsigned j=1; j <= height; ++j){
      double f = (double)rand() / RAND_MAX;
      weights(i, j) = f * (2 * maxWeight) - maxWeight;
    }
  }

  return weights;
}

void feedForward(MatrixXd inputMatrix, MatrixXd weightMatrix,
                VectorXd biasMatrix, MatrixXd &outputMatrix,
                MatrixXd &netMatrix){

  MatrixXd concatenatedInput(inputMatrix.rows(), inputMatrix.cols() + 1);
  concatenatedInput << inputMatrix, biasMatrix;

  //net = mul(weights, horcat(inputs, bias))
  //output = activate(net)

  netMatrix = weightMatrix * concatenatedInput;
  outputMatrix = activate(netMatrix);



}

void networkError(MatrixXd inputMatrix, MatrixXd weightMatrix,
                VectorXd biasMatrix, MatrixXd targetOutputMatrix,
                VectorXi targetClassVector, double error, double classError){

  feedForward(inputMatrix weightMatrix, biasMatrix,
    MatrixXd outputMatrix, Matrix netMatrix);

  error = sum((targetOutputMatrix - outputMatrix)^2.0)
    / (sample_count * output_count);

  outputToClass(int n, outputMatrix, &classVector);

  c = sum_all_components(classVector != targetClassVector)/sample_count;

}

matrixXd backPropogration(MatrixXd inputMatrix, MatrixXd weightMatrix,
  double eta, VectorXd biasMatrix){

  //currently dummy function
  return weightMatrix;

}

void trainingFunction(){
  
}

double activationFunction(double x){
  return (tanh(x) + 1.0)/2.0;
}

double activationFunctionDerivative(double x){
  return (1.0 - (tanh(x)^2.0))/2.0;
}

void checkColumns(MatrixXi &Matrix, VectorXi &Vector){
  if (Matrix.cols() /= Vector.rows()){
      std::cout << "Mismatch between output matrix columns and class vector rows" << std::endl;
      exit (EXIT_FAILURE);
  }
}

void outputToClass(int n, MatrixXi outputMatrix, VectorXi &classVector){

  checkColumns(outputMatrix, classVector);

  for (unsigned i=1; i <= n; ++i){
    for (unsigned j=1; j <= 3; ++j){
      if (outputMatrix(i, j) == 1){
        classVector(i) = j;
      }
    }
  }
}

void outputToMatrix(int n, MatrixXi &outputMatrix, VectorXi classVector){

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
