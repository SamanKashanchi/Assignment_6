#include "SortAlgos.cpp"
#include <iostream>
#include <string>
#include <fstream>
#include <istream>
using namespace std;

 int main(int argc,char* argv[]) {
//error check for file
  if (argc > 1) {
    cout << "You Have entered: " << argv[1] <<". Preparing output file. " <<endl;
      }
  else {
    cout << "No file name entered."<< "\n";
    return -1;
      }
  ifstream txtF(argv[1]);
  int spot = 0;
  double* array1;
  double* array2;
  double* array3;
  double* array4;
  double* array5;
  string line;
  int lineCounter = 0;
  int size;
  if (txtF.is_open())
    {
      cout<< "File is Opened" << endl;
        while(getline(txtF, line))
        {
            if (lineCounter == 0)
            {
//Creating 5 copies of the array
                size = stoi(line);
                cout << "size: " << size << endl;
                array1 = (double*)malloc(size*sizeof(double));
                array2 = (double*)malloc(size*sizeof(double));
                array3 = (double*)malloc(size*sizeof(double));
                array4 = (double*)malloc(size*sizeof(double));
                array5 = (double*)malloc(size*sizeof(double));
            }
            else
            {
                array1[spot] = stod(line);
                array2[spot] = stod(line);
                array3[spot] = stod(line);
                array4[spot] = stod(line);
                array5[spot] = stod(line);
                spot++;
            }
          lineCounter++;
        }
        txtF.close();
    }
      time_t StrTime;
      time_t endTime;
//Interface for priting each alogorithm and its proccesing times
      StrTime = time(NULL);
      bubbleSort(array3, size);
      endTime = time(NULL);
      cout << "BubbleSort" << endl << "Start Time : " << StrTime  << "\n End Time : " << endTime << endl << "Difference: "<< endTime-StrTime<<endl;

      StrTime = time(NULL);
      SelectionSort(array1,size);
      endTime = time(NULL);
      cout << "SelectionSort" << endl << "Start Time : " << StrTime  << "\n End Time : " << endTime << endl << "Difference: "<< endTime-StrTime<<endl;

      StrTime = time(NULL);
      InsertionSort(array2,size);
      endTime = time(NULL);
      cout << "InsertionSort" << endl << "Start Time : " << StrTime  << "\n End Time : " << endTime << endl << "Difference: "<< endTime-StrTime<<endl;

      StrTime = time(NULL);
      quicksort(array4,0,size-1);
      endTime = time(NULL);
      cout << "QuickSort" << endl << "Start Time : " << StrTime  << "\n End Time : " << endTime << endl << "Difference: "<< endTime-StrTime<<endl;

      StrTime = time(NULL);
      mergeSort(array5,0,size-1);
      endTime = time(NULL);
      cout << "MergeSort" << endl << "Start Time : " << StrTime  << "\n End Time : " << endTime << endl << "Difference: "<< endTime-StrTime<<endl;
 }
