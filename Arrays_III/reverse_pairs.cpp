//optimal approach

//modified merge sort

class Solution
{
    void merge(vector<int> &arr, int low, int mid, int high)
    {
        vector<int> temp;
        int left = low;
        int right = mid + 1;

        while (left <= mid && right <= high)
        {
            if (arr[left] <= arr[right])
            {
                temp.push_back(arr[left]);
                left++;
            }
            else
            {
                temp.push_back(arr[right]);
                right++;
            }
        }

        while (left <= mid)
        {
            temp.push_back(arr[left]);
            left++;
        }

        while (right <= high)
        {
            temp.push_back(arr[right]);
            right++;
        }

        for (int i = low; i <= high; i++)
        {
            arr[i] = temp[i - low];
        }
    }

    int reverse_pairs(vector<int> &arr, int low, int mid, int high)
    {
        int cnt = 0;
        int right = mid + 1;

        for (int i = low; i <= mid; i++)
        {
            while (right <= high && (long long)arr[i] > 2LL * arr[right])
            {
                right++;
            }

            cnt += (right - (mid + 1));
        }

        return cnt;
    }

    int mergeSort(vector<int> &arr, int low, int high)
    {
        int cnt = 0;
        if (low >= high)
            return cnt;
        int mid = (low + high) / 2;
        cnt += mergeSort(arr, low, mid);      // left half
        cnt += mergeSort(arr, mid + 1, high); // right half
        cnt += reverse_pairs(arr, low, mid, high);
        merge(arr, low, mid, high); // merging sorted halves
        return cnt;
    }

public:
    int reversePairs(vector<int> &nums)
    {
        int n = nums.size();
        return mergeSort(nums, 0, n - 1);
    }
};
