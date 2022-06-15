#include<vector>
#include<iostream>
#include<cmath>
/*
void stoogesort(array L, i = 0, j = length(L)-1){
     if (L[i] > L[j]){        // Compara si el elemento más a la izquierda es más grande que el más a la derecha
         L[i] ↔ L[j]            // Intercambiar el elemento más a la izquierda con el más a la derecha
         }         
     if (j - i + 1) > 2 {       // Si hay al menos tres elementos en el arreglo
         t = floor((j - i + 1) / 3)
         stoogesort(L, i  , j-t)  // Ordenar los primeros 2/3 del arreglo
         stoogesort(L, i+t, j)    // Ordenar los últimos 2/3 del arreglo
         stoogesort(L, i  , j-t)  // Ordenar los primeros 2/3 del arreglo denuevo
         }
 }

 procedure slowsort(A[], i, j)          // Sort array range A[i ... j] in-place.
    if i ≥ j then
        return
    m := floor( (i+j)/2 )
    slowsort(A, i, m)                  // (1.1)
    slowsort(A, m+1, j)                // (1.2)
    if A[j] < A[m] then
        swap A[j] , A[m]               // (1.3)
    slowsort(A, i, j-1)                // (2)

*/
/*
float Q_rsqrt( float number )
{
	long i;
	float x2, y;
	const float threehalfs = 1.5F;

	x2 = number * 0.5F;
	y  = number;
	i  = * ( long * ) &y;                       // evil floating point bit level hacking
	i  = 0x5f3759df - ( i >> 1 );               // what the fuck? 
	y  = * ( float * ) &i;
	y  = y * ( threehalfs - ( x2 * y * y ) );   // 1st iteration
//	y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed

	return y;
}
*/