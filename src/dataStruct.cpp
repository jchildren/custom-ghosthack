//dataStruct.cpp

#include "dataStruct.h"


void inputData::inputData(){
  dataSet irisData;

  m_filePath[20] = "../data/";

  m_fileNames[3] =
    {"iris_training.dat",
    "iris_test.dat",
    "iris_validation.dat"};

  //issues here

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
