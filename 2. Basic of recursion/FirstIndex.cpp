int help(int input[],int size,int x,int i){
    
    if(size==0)
        return -1;
    if(input[0]==x)
        return i;
    
    help(input+1,size-1,x,i+1);
}
int firstIndex(int input[], int size, int x) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return output and don't print it.
     Taking input and printing output is handled automatically.
  */
	 int i=0;
    int ans=help(input, size, x, i);
    return ans;
}
