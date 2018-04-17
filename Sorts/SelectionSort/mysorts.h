#ifndef mysorts_H
#define mysorts_H
#define arr_size 20

class mysorts{
  public:
    void Sort(int    arr[]); // insertion Sort
    void Sort(double arr[]); // selection Sort
    void Sort(float  arr[]); // bubble Sort

  private:
    int i, j, key, min_index;
    double Temp_d;
    float Temp_f;
};