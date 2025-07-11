/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long long left = 0;
        long long right = n;

        while(left <= right){
            long long  mid = (left + right) / 2;
            // cout << mid << endl;
            int res = guess(mid);
            // cout << "res " << res << endl;
            if(res == 0) return mid;
            else if( res == -1) right = mid - 1;
            else left = mid + 1;
        }
        return 0;
    }
};