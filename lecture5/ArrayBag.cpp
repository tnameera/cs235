#include "ArrayBag.hpp"

//create an array of type T with capacity 10.
//data member array is called items.
template<class T>
ArrayBag<T>::ArrayBag()
{
    capacity = 20;
    items = new T[capacity];
    size = 0; //number of elements residing in array items is 0
}

template<class T>
ArrayBag<T>::ArrayBag(int arr[], int newSize)
{
    capacity = newSize;
    items = new T[capacity];
    size = 0; //number of elements residing in array items is 0

    for(int i=0; i < newSize; i++)
    {
        add(arr[i])
    }
}

template<class T>
ArrayBag<T>::~ArrayBag()
{
    delete[] items; //since items in application
    //items = new T[capacity];
    //items is pointing to several elements of type T.
    //[] after delete means to release that memory.

    //To avoid dangling pointer problem,
    //which means an address whose space is no longer available,
    //set that address to be invalid (ie, nullptr)
    items = nullptr; //c++11
    //in C++98, items = 0; since nullptr is not available
    //until C++11.
    //example if item = 123 address 
    //now its demolished there i sno building at that address
    //  'item' adress poiting to a block then I released that space for the block.
    //item address becomes non -calid address

}

template<class T>
int ArrayBag<T>::getCurrentSize() const
{
    return size;
    // initial size = 0; 
    //addign 1 size increases
    //the size tell you how many elements of this arrays have been occupied
}

template<class T>
bool ArrayBag<T>::replace(const T& piece,const T& new_piece)
{
    bool x = remove(piece);
    if (x) 
    {
        bool y = add(new_piece);
        return (y);
    }  
    return false;
}    

//template<class T>
//bool ArrayBag<T>::replace(const T& piece1,const T& piece2)
//for (i = 0; i < size; i++)
    //if (item[i] == piece1)
    //{
        //item[i] == piece2
        //return true;
    //}
    //return false;
//}
            
template<class T>
bool ArrayBag<T>::add(const T& piece)

{        
    if (size < capacity)
    {
        //size is the index of the next available space 
        //in array items.
        //items[size] = piece; is to put piece into element
        //items[size].
        //since items[size] is occupied now,
        //the next available space's index is size+1.
        items[size] = piece; 
        //size++; is to increase size by 1,
        //which tells two things:
        //1. Now we have (size+1) elements -- one more item
        //   from previous value size -- in array items.
        //2. The next available index for this array items
        //   is (size +1).
        size++;

        //return true; means add operation is successful.
        return true;
    }
    else return false; //cannot squeeze the item piece
    //into array items since the capacity is reached.
}

template<class T>
bool ArrayBag<T>::addNoDuplicates(const T& piece)
{   
    for (int i = 0; i < size; i++)
    {
        if (items[i] == piece)
            return false;
    }        
    if (size < capacity)
    {
        //size is the index of the next available space 
        //in array items.
        //items[size] = piece; is to put piece into element
        //items[size].
        //since items[size] is occupied now,
        //the next available space's index is size+1.
        items[size] = piece; 
        //size++; is to increase size by 1,
        //which tells two things:
        //1. Now we have (size+1) elements -- one more item
        //   from previous value size -- in array items.
        //2. The next available index for this array items
        //   is (size +1).
        size++;

        //return true; means add operation is successful.
        return true;
    }
    else return false; //cannot squeeze the item piece
    //into array items since the capacity is reached.
}

template<class T>
bool ArrayBag<T>::add2(const T& piece)
{
    bool m = contains(piece);
    if (!m) 
    {
        bool n = add(piece);
        return (n);
    }
    return false; //cannot squeeze the item piece
    //into array items since the capacity is reached.
}

template<class T>
bool ArrayBag<T>::remove(const T& piece)
{
    for (int i = 0; i < size; i++)
    {
        if (items[i] == piece)
        {
           //Sarika's idea
           //since data in a bag is unordered.
           //swap items[i] with items[size-1].
           //size--;
           //return true;
           //T temp = items[i];
           //items[i] = items[size-1];
           //items[size-1] = temp;
           //size--;
           //return true;


            //input: delete 5
            //+---------+-----------+------------+--------
            // 2          5           4           1

            //+---------+-----------+------------+--------
            //0          1           2           3
            
            //Output
            //+---------+-----------+------------+--------
            //2          1          4            1

            //+---------+-----------+------------+--------
            //0          1           2           3

           //Oscar's idea
           //even though data in a bag is unordered,
           //but I want to be picky,
           //want to make sure the items are properly ordered.
           for (int j = i; j < size-1; j++)
               items[j] = items[j+1];


                //input delete 5
               //+---------+-----------+------------+--------
               // 2          5           4           1

               //+---------+-----------+------------+--------
                //0          1           2           3
                //Output
                //+---------+-----------+------------+--------
                //2          4          1            1

               //+---------+-----------+------------+--------
               //0           1           2           3
           size--;
           return true;
        }
    }
    return false;
}


template<class T>
bool ArrayBag<T>::removeRandom()
{

    int x = rand() % size;
    piece = items[x]
    remove(piece);
    return true;

} 


template<class T>
bool ArrayBag<T>::contains(const T& piece) const
{
    for (int i = 0; i < size; i++)
       if (items[i] == piece)
           return true;

    return false;

    //return getFrequencyOf(piece) > 0;
}

template<class T>
int ArrayBag<T>::getFrequencyOf(const T& piece) const
{
    int count = 0;
    for (int i = 0; i < size; i++)
	if (items[i] == piece)
	   count++;

    return count;
}

template<class T>
std::vector<T> ArrayBag<T>::toVector() const
{
    std::vector<T> results; //empty vector of type T
    for (int i = 0; i < size; i++)
        results.push_back(items[i]);

    return results;
}

//parametarized 
//template<class T>
//std::vector<T> ArrayBag<T>::toVector() const
