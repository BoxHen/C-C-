#ifndef mysorts_H
#define mysorts_H
#define arr_size 20

class mysorts{
  public:
    void static Sort(int    arr[]); // insertion Sort
    void static Sort(double arr[]); // selection Sort
    void static Sort(float  arr[]); // bubble Sort

  private:
    int i, j, key, min_index;
};

#endif // mysorts_H
