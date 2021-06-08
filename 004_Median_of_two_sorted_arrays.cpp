class Solution {
public:
    double calculateMedian( int a, int b ){
        return (double)(a+b)/(double)2;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if( !nums1.size() || !nums2.size()){
            if( nums1.size() ){
                if( ( nums1.size() & 1) ){
                    return (double)(nums1[ nums1.size()/2 ]);
                }
                else{
                    return calculateMedian( nums1[nums1.size()/2], nums1[nums1.size()/2-1] );
                }
            }
            else{
                if( ( nums2.size() & 1) ){
                    return (double)(nums2[ nums2.size()/2 ]);
                }
                else{
                    return calculateMedian( nums2[nums2.size()/2], nums2[nums2.size()/2-1] );
                }
            }
        }

        if( nums1.size() > nums2.size() ){
            nums1.swap(nums2);
        }
        int split1, split2;
        int left = 0, right = nums1.size(),result,max1,min1,max2,min2;
        int total = nums1.size()+nums2.size();
        while(1){
            split1 = (left + right)/2;
            split2 = (total)/2-split1;
            min1 = split1==0?INT_MIN:nums1[split1-1];
            max1 = split1==nums1.size()?INT_MAX:nums1[split1];
            min2 = split2==0?INT_MIN:nums2[split2-1];
            max2 = split2==nums2.size()?INT_MAX:nums2[split2];
            if( (min2 <= max1)&&(min1 <= max2) ){
                break;
            }
            else{
                if( min2 > max1 ){
                    left = split1+1;
                }
                else{
                    right = split1-1;
                }
            }
        }
        if( total&1 ){
            left = min1 > min2?min1:min2;
            right = max1 < max2? max1:max2;
            return left >right?left:right;
        }
        else{
            left = min1 > min2?min1:min2;
            right = max1 < max2? max1:max2;
            return calculateMedian( left,right );
        }
    }
};

/*

we split and make sure there are m elements in array1 and n elements in array2
length of array1 is M
length of array2 is N

(m+n) * 2 = M+N;
n = ( M+N )/2 - m;
therefore, we can use binary search to search m

if the m elements and n elemnts are all smaller then the other half, we got the point.

and the median is the larger of m and n and the smaller of the other half.

When the total length is single, you need to get the larger of m and n or the smaller of the other half depends on how you split.

Time Complexity O(logn)

Space Complexity O(1)

However, if you use another solution, which is :
1. Create an array with size M + N
2. Add all elements inside using O(N)
3. calculate median from the new array
though 
Time complexity is O(N+M)
Space Complexity is O(N+M)

it runs faster since I believe the test case is not large enough

*/