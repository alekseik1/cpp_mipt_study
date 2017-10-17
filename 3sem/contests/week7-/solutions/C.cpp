//
// Created by aleksei on 17.10.17.
//

void SortArray(int array[], const int& size) {
    for (int i=size-1; i>=0; i--)
    {
        for (int j=0; j<i; j++)
        {
            if (array[j] > array[j+1])
            {
                int tmp = array[j];
                array[j] = array[j+1];
                array[j+1] = tmp;
            }
        }
    }
}