/* Sequential bucket sort of n integers in range [0, n] */
#include <stdlib.h>  
#include <math.h>

#define n 2000 
#define m 100  
#define b_n 10 

int D1[n+1], D2[n+1]; 
int bucket[b_n][n+1]; 
int i, j;

/* sort c[1:m] */
void sort(int c[]) {
  int m = c[0]; /* m integers in c[1:m] to be sorted */
  int j, k, maximum, maximum_index, temp;
  for (j = m; j > 1; j--) {
    maximum = c[j];
	  maximum_index = j;
    for (k = 1; k < j; k++) {
      if (c[k] > maximum) {
	    maximum = c[k];
		maximum_index = k;
	  }
	}
	temp = c[j];
	c[j] = maximum;
	c[maximum_index] = temp;
  }

  return;
}

main() {
  /* generate n random integers in [0, m-1] to be sorted */	
  /* for better speed-up of its parallel version, read Appendic C to exclude running time for such sequential code not essential for sorting */
  for (i = 1; i <= n; i++) 
	  D1[i] = rand() % m;

  forall i = 1 to n do {
    int v = D1[i];
	  int b_i = v/10; /* bucket-i = the 10th digit */
	  int i = ++bucket[b_i][0]; /* find i of first unused box for v; */
	  bucket[b_i][i] = v;
  }

  forall i = 0 to 9 do {
    sort(bucket[i]);
  }
  
  int k = 1;
  for (i = 0; i <= 9; i++){ 
    for (j = 1; j < bucket[i][0]; j++) { 
      D2[k++] = bucket[i][j];
    }
  }

  k--;
  for (i = 1; i <= k; i++)
	  cout << "c[" << i << "]=" << D2[i] <<  endl;  
	    
	   
}