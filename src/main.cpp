#include <iostream>
#include <vector>
#include <set>
#include <time.h>
#include <unordered_set>
#include <unordered_map>
#include <valarray>
#include <memory>

using namespace std;
vector<string> findRepeatedDnaSequences(string s) {
    int len = s.length();
    char nums[len];
    for (int i=0;i<len;i++) {
        switch (s[i]) {
            case 'A' :
                nums[i] = 0;
                break;
            case 'G' :
                nums[i] = 1;
                break;
            case 'C' :
                nums[i] = 2;
                break;
            case 'T':
                nums[i] = 3;
                break;
        }
    }

    int left = 0, right =0;
    int number = 0;
    unordered_map<int, bool> m;
    set<string> res;
    while (right < len) {
        char num = nums[right];
        right++;
        number = number * 4 + num;
        if (right - left == 10) {
            if (m[number]) {
                res.insert(s.substr(left,10));
            }
            m[number] = true;
            num = nums[left];
            left++;
            number = number - num * (pow(4,9));
        }

    }
    return vector<string>(res.begin(), res.end());

}
int strStr(string haystack, string needle) {
    if (needle.empty()) {
        return 0;
    }
    if (haystack.empty()) {
        return -1;
    }
    int prime = 1658598167;
    int R = 128;
    int L = needle.length();
    long hash = 0;
    for (int i : needle) {
        hash = (hash * R + i) % prime ;
    }
    long RL = 1;
    for (int i=1;i<L;i++) {
        RL = RL%prime * R;
    }
    int left = 0, right =0;
    long window = 0;

    while (right < haystack.length()) {
        int num = haystack[right];
        right++;
        window = (window * R + num) % prime;
        if (right - left == L) {
            if (window == hash) {
                if (haystack.substr(left, L) == needle)
                    return left;
            }
            num = haystack[left];
            left++;
            window =( (window - long(num* RL) % prime) + prime) % prime;
        }
    }
    return -1;
}
int a= 10;
int& func(){
    return a;
}

long eat(int k, vector<int>& piles) {
    long sum = 0;
    for (int pile : piles) {
        sum += pile / k;
        if (pile % k != 0) {
            sum++;
        }
    }
    return sum;
}

int need_m(int arr, vector<int>& nums) {
    int sum = 1;
    int idx = 0;
    int size = nums.size();
    int cur = arr;
    while (idx <size) {
        if (cur >= nums[idx]) {
            cur -= nums[idx];
            idx++;
        } else {
            cur = arr;
            sum++;
        }
    }
    return sum;
}

struct Temp {
    int num;
    int idx;
};

vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
    int size = nums1.size();
    vector<Temp> v(size);
    for (int i=0;i<size;i++) {
        v[i].idx = i;
        v[i].num = nums2[i];
    }
    sort(nums1.begin(),nums1.end());
    sort(v.begin(), v.end(), [](const Temp& t1, const Temp& t2){
        return t1.num < t2.num;
    });

    vector<int> res(size, -1);
    int left=size-1, right = size-1;
    int min = 0;
    while (right >= 0) {
        if (nums1[left] > v[right].num) {
            res[v[right].idx] = nums1[left];
            left--;
            right--;
        } else {
            res[v[right].idx] = nums1[min];
            min++;
            right--;
        }
    }

    return res;

}

int splitArray(vector<int>& nums, int m) {
    int min = nums[0];
    int right = 1;
    for (int num : nums) {
        min = std::max(min, num);
        right+=num;
    }
    int left = min;
    while (left <= right) {
        int mid = (left + right)/ 2;
        if (need_m(mid, nums) > m) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left;
}

class RandomizedSet {
public:
    vector<int> nums;
    unordered_map<int ,int> m;
    RandomizedSet() {
        srand(time(nullptr));
    }

    bool insert(int val) {
        if (m.count(val) > 0) {
            return false;
        } else {
            m[val] = nums.size();

                nums.emplace_back(val);

            return true;
        }
    }

    bool remove(int val) {
        if (m.count(val) > 0) {
            int size = nums.size();
            nums[m[val]] = nums[size-1];
            m[nums[size-1]] = m[val];
            m.erase(val);
            nums.pop_back();
            return true;
        } else {
            return false;
        }
    }

    int getRandom() {

         int idx = rand() % nums.size();
        return nums[idx];
    }
};

void func2() {

}
#include <memory>
#include <thread>
#include <unordered_map>
using namespace std;
struct A{
    int num;
};

static const std::string base64_chars =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"
        "0123456789+/";


static inline bool is_base64(unsigned char c) {
    return (isalnum(c) || (c == '+') || (c == '/'));
}

std::string base64_decode(std::string const& encoded_string) {
    int in_len = encoded_string.size();
    int i = 0;
    int j = 0;
    int in_ = 0;
    unsigned char char_array_4[4], char_array_3[3];
    std::string ret;

    while (in_len-- && ( encoded_string[in_] != '=') && is_base64(encoded_string[in_])) {
        char_array_4[i++] = encoded_string[in_]; in_++;
        if (i ==4) {
            for (i = 0; i <4; i++)
                char_array_4[i] = base64_chars.find(char_array_4[i]);

            char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
            char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
            char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

            for (i = 0; (i < 3); i++)
                ret += char_array_3[i];
            i = 0;
        }
    }

    if (i) {
        for (j = i; j <4; j++)
            char_array_4[j] = 0;

        for (j = 0; j <4; j++)
            char_array_4[j] = base64_chars.find(char_array_4[j]);

        char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
        char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
        char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

        for (j = 0; (j < i - 1); j++) ret += char_array_3[j];
    }

    return ret;
}

void my_shuffle() {
    std::vector<int> v {1,2,3,4,5,6,7,8,9};
    std::random_shuffle(v.begin(), v.end());
    std::cout << this_thread::get_id() << endl;
}

int main() {
    std::thread threads[10000];

    for (int i=0;i<10000;i++) {
        threads[i] = std::thread(my_shuffle);
    }
    for (int i=0;i<10000;i++) {
        threads[i].join();
    }
}

