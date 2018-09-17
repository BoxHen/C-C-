#ifndef mysorts_H
#define mysorts_H
#define arr_size 20

class mysorts{
  public:
    static void Sort(int    (&arr)[arr_size]); // insertion Sort
    static void Sort(double (&arr)[arr_size]); // selection Sort
    static void Sort(float  (&arr)[arr_size]); // bubble Sort

};

#endif // mysorts_H
