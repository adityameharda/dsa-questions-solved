class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        // int idx = 0;
        // for(int i = 0 ; i < n ; i++){
        //     int total = 0;
        //     bool flag = true;
        //     for(int j = 0 ; j < n ; j++){
        //         int k = (i+j)%n;
        //         total = total + gas[k] - cost[k];
        //         if(total < 0){
        //             flag = false;
        //             break;
        //         }
        //     }
        //     if(flag)return  i;  
        // }
        // return  -1; 

        int total = 0 ;
        int idx = 0;
        int tank = 0;
        for(int i = 0 ; i < n ; i++){
            total += gas[i] - cost[i] ;
            tank += gas[i] - cost[i];
            if(tank < 0){
                idx = i+1;
                tank = 0;
            }
        }
        if(total >= 0)return idx ;
        return -1;
    }
};