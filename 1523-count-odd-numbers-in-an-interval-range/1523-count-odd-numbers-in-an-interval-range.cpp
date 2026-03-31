class Solution {
public:
    int countOdds(int low, int high) {
        int count = 0;
        // for(int i = low ; i < high ; i++)
        // {
        //     if()
        // }
        while(low<=high)
        {
            if(low %2 != 0)count++;

            low++;
        }
        return count;
    }
};