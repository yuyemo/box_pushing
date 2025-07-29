void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;   // 左子数组长度
    int n2 = right - mid;      // 右子数组长度

    // 创建临时数组
    int *L = (int*)malloc(n1 * sizeof(int));
    int *R = (int*)malloc(n2 * sizeof(int));

    // 复制数据到临时数组
    for (i = 0; i < n1; i++) L[i] = arr[left + i];
    for (j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    // 合并临时数组回原数组
    i = 0; j = 0; k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    // 复制剩余元素
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    // 释放临时数组内存
    free(L);
    free(R);
}

// 归并排序主函数
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;  // 防止溢出的中间值计算

        // 递归排序左右子数组
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // 合并已排序的子数组
        merge(arr, left, mid, right);
    }
}
int findLeastNumOfUniqueInts(int* arr, int arrSize, int k) {
    int b[1000][1000]={{0}};
    int p[1000][1000]={{0}};
    int m[1000]={0};
    for(int u=0;u<arrSize;u++){
        int q=arr[u]%1000;
        p[q][m[q]]=arr[u];
        m[q]++;
    }
    for(int g=0;g<1000;g++){
        int l=m[g];
    for(int r=0;r<l;r++){
        for(int j=0;j<l;j++){
            if(p[g][r]==p[g][j]){
                b[g][j]+=1;
                break;
            }
        }
    }
    }
    int f[arrSize];
    int v=0;
    for(int c=0;c<1000;c++){
        int j=m[c];
        for(int e=0;e<j;e++){
            if(b[c][e]!=0){
                f[v]=b[c][e];
                v++;
            }
        }
    }
    mergeSort(f,0,v-1);
    int z=0;
    while(z<v&&f[z]==0){
        z++;
    }
    while(k>0&&z<v){
        k-=f[z];
        z++; 
    }
    if(k==0){
        return v-z;
    }
    return v-z+1;
}