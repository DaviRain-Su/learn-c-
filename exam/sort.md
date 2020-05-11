# sort 

    void selectSort(vector<int> &vec)
    {
        int len = vec.size();
        for(int i = 0; i < len; i++){
            int k = i;
            for(int j = i; j <= n; j++){
                if(vec[j] < vec[k]){
                    k = j;
                }
            }
            swap(vec[i], vec[k]);
        }
    }