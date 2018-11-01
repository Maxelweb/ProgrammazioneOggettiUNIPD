
/**
   Template di esempio (pag 123)
*/


template <class T, int size>
T min( T(&a)[size] )
{
    T vmin = a[0];
    for(int i=0; i<size; i++)
        if(a[i] < vmin) vmin = a[i];
    return vmin;
}

