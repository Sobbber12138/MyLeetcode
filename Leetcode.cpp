#include<bits/stdc++.h>
using namespace std;

//构建一个二叉树
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) :val(x), left(nullptr), right(nullptr){};
    TreeNode(int x, TreeNode *left) :val(x), left(left), right(nullptr){};
    TreeNode(int x, TreeNode *left, TreeNode *right) :val(x), left(left), right(right){};
};

//构建一个链表
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode *next) : val(x), next(next){} 
};

//删除链表中的节点请你编写一个函数，用于删除单链表中的某个特定节点node
class Solution0{
public:
void deleteNode(ListNode *node) {
    node -> val = node -> next-> val;
    node -> next = node -> next-> next;
}
};

//使用hash表统计数组中相同的数
class Solution1{
    public:
    int numIdenticalPairs(vector<int>&nums) {
        int hash[110],sum=0;
        memset(hash,0,sizeof(hash));//栈上空间的初始化
        for(int i=0;i<nums.size();++i) {
            ++hash[ nums[i] ];
        }
        for(int i = 1; i<100; ++i){
            int x = hash[i];
            sum += x*(x-1)/2;
        }
        return sum;
    }
};

//实现整数的反转（如果反转后整数超过32位的有符号整数范围[-2^31,2^31-1],返回0。
class solution2{
#define ll long long
    public:
    int reverse(int x) {
        queue<int> q;
        ll flag = 1;
        ll l = -((ll)1<<31);
        ll r = ((ll)1<<31)-1;

        if(!x){
            return 0;
        }
        if(x==1){
            return 0;
        }
        if(x<0){
            flag = -flag;
            x = -x;
        }
        while(x){
            q.push(x % 10);
            x=x/10;
        }
        ll sum = 0;
        while( !q.empty()){
            sum=sum*10+q.front();
            q.pop();
        }
        if(sum <l||sum >r){
            return 0;
        }
        return flag*sum;
    }


};

//利用一个类来计算[t-3000,t]最近的所有请求数。
class RecentCounter{
    queue<int> q;
    public:
    RecentCounter() {

    }
    int ping(int t) {
        while(!q.empty()) {
            if(t - q.front()>3000) {
                q.pop();
            }else {
                break;
            }
        }
        q.push(t);
        return q.size();
    }
};

//输入一棵二叉树的根节点，求该树的深度。
class Solution3 {
    public:
    int maxDepth(TreeNode *root) {
        if(!root){
            return 0 ;
        }else {
            return max((maxDepth(root-> left)+1), (maxDepth(root-> right)+1));
        }
    }
};

//给一个二叉树的根节点root， 返回它的节点值的前序遍历。
class Solution4 {
public:
    void traversal(TreeNode* cur, vector<int>& vec) {
        if (cur == NULL) return;
        vec.push_back(cur->val);    // 中
        traversal(cur->left, vec);  // 左
        traversal(cur->right, vec); // 右
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        traversal(root, result);
        return result;
    }
};

/* 实现一个二叉搜索树迭代器类BSTiterator
boolean hasNext()如果向指针右侧遍历存在数字，返回true，否则返回false；
int next()将指针向右移动，然后返回指针处的数字。 */
class BSTiterator {
    vector<int> ret;
    int num=-1;
    void dfs(TreeNode *root) {
        if(!root) {
            return;
        }
        dfs(root-> left);
        ret.push_back(root-> val);
        dfs(root->right);
    }
    public:
    BSTiterator(TreeNode *root) {
        dfs (root);
    }

    int next() {
        return ret[++num];
    }

    bool hasNext() {
        if(num < (int)ret.size()-1) {
            return true;
        }
        return false;
    }
};

//判断是否存在二叉搜索树中两个节点之和等于k
class Solution5 {
    public:
    vector<int> ret;
    void dfs(TreeNode *root) {
        if(!root) {
            return;
        }
    dfs(root-> left);
    ret.push_back(root->val);
    dfs(root->right);
    }
    bool findTarget(TreeNode *root,int k){
        dfs(root);
        int target=0;
        int l=0, r=ret.size()-1;
        while(l<r) {
            target= ret[l]+ret[r];
            if(target<k) {
                l++;
            }
            if(target>k) {
                r--;
            }
            else return true;
        }
        return false;
    }
};

//快速排序法
class Solution99 {
    void swap(int *x, int *y) {
    int t = *x;
    *x = *y;
    *y = t;
}
    void quick_sort_recursive(int arr[], int start, int end) {
        if(start >= end)
        return;
        int mid = arr[end];
        int left = start, right = end-1;
        while (left < right) {
            while (arr[left] < mid && left <right)
            left++;
            while(arr[right] >= mid && left < right)
            right--;
            swap(&arr[left], &arr[right]);
        }
        if (arr[left] >=arr[end])
        swap(&arr[left], &arr[end]);

        quick_sort_recursive(arr, start, left-1);
        quick_sort_recursive(arr, left + 1, end);
    }
    void quick_sort(int arr[], int len) {
        quick_sort_recursive(arr, 0, len-1);
    }
};

//**********************以下开始为按照代码随想录顺序进行编写********************//
/* Chapter 3 数组 */
//利用快慢双指针移除数组中的元素
class Solution6 {
    public:
    int removeElement(vector<int>& nums, int val) {
        int SlowIndex = 0;
        for (int FastIndex= 0; FastIndex < nums.size(); FastIndex++) {
            if(nums[FastIndex]!=val) {
                nums[SlowIndex]=nums[FastIndex];
                SlowIndex++;
            }
        }
        return SlowIndex;
    }
};

//利用指向双指针移除数组中的元素，但是湖改变元素的相对位置
class Solution7 {
    public:
    int removeElement(vector<int>& nums, int val) {
        int LeftIndex = 0;
        int RightIndex = 0;
        while(LeftIndex<= RightIndex) {
            if(nums[LeftIndex] != val) {
                LeftIndex++;
            }
            if(nums[RightIndex] = val) {
                RightIndex--;
            }
            nums[LeftIndex++] = nums[RightIndex--];
        }
        return LeftIndex;
    }
};

//利用螺旋法读取矩阵元素（核心是注意循环时区间开闭的选取）
class Solution8 {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0)); // 使用vector定义一个二维数组
        int startx = 0, starty = 0; // 定义每循环一个圈的起始位置
        int loop = n / 2; // 每个圈循环几次，例如n为奇数3，那么loop = 1 只是循环一圈，矩阵中间的值需要单独处理
        int mid = n / 2; // 矩阵中间的位置，例如：n为3， 中间的位置就是(1，1)，n为5，中间位置为(2, 2)
        int count = 1; // 用来给矩阵中每一个空格赋值
        int offset = 1; // 需要控制每一条边遍历的长度，每次循环右边界收缩一位
        int i,j;
        while (loop --) {
            i = startx;
            j = starty;

            // 下面开始的四个for就是模拟转了一圈
            // 模拟填充上行从左到右(左闭右开)
            for (j = starty; j < n - offset; j++) {
                res[startx][j] = count++;
            }
            // 模拟填充右列从上到下(左闭右开)
            for (i = startx; i < n - offset; i++) {
                res[i][j] = count++;
            }
            // 模拟填充下行从右到左(左闭右开)
            for (; j > starty; j--) {
                res[i][j] = count++;
            }
            // 模拟填充左列从下到上(左闭右开)
            for (; i > startx; i--) {
                res[i][j] = count++;
            }

            // 第二圈开始的时候，起始位置要各自加1， 例如：第一圈起始位置是(0, 0)，第二圈起始位置是(1, 1)
            startx++;
            starty++;

            // offset 控制每一圈里每一条边遍历的长度
            offset += 1;
        }

        // 如果n为奇数的话，需要单独给矩阵最中间的位置赋值
        if (n % 2) {
            res[mid][mid] = count;
        }
        return res;
    }
};
/* Chapter 4 链表 */
//删除链表中为val的元素（通过设置一个虚拟头结点的方式）
class Solution9 {
    public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* DummyHead = new ListNode(0);
        DummyHead->next = head;
        ListNode* cur = DummyHead ;
        while(cur->next!= NULL) {
            if(cur->next->val == val) {
                ListNode* tem = cur->next;
                cur->next = cur->next->next;
                delete tem;
            }
            else{
                cur = cur->next;
            }
        }
        head = DummyHead->next;
        delete DummyHead;
        return head;
    }
};
/* 总结上题：该方法是通过增加一个虚拟头的方式实现链表的查找删除的，如果不能访问
链表的头结点，那么则可以参考最上方的变种方式进行实现 */

/*设计链表,以实现如下功能
获取链表第index个节点的数值
在链表的最前面插入一个节点
在链表的最后面插入一个节点
在链表第index个节点前面插入一个节点
删除链表的第index个节点
*/
class MyLinkedList {
    public:
    //定义链表节点结构体
    struct LinkedNode {
        int val;
        LinkedNode* next;
        LinkedNode(int x):val(x), next(nullptr){}
        LinkedNode(int x, LinkedNode* next):val(x), next(next){}
    };

    //初始化链表
    MyLinkedList() {
        LinkedNode* _dummyHead = new LinkedNode(0);
        int _size = 0;
    }

    //获取链表第index个节点的数值
    int get(int index) {
        if(index > (_size-1)||index < 0) {
            return -1;
        }
        LinkedNode* cur = _dummyHead->next;
        while(index--) {
            cur = cur->next;
        }
        return cur->val;
    }

    //在链表的最前面插入一个节点
    void addHead(int val) {
        LinkedNode* newHead = new LinkedNode(val);
        newHead->next = _dummyHead->next;
         _dummyHead->next = newHead;
         _size++;
    }
    //在链表的最后面添加一个点
    void addTail(int val) {
        LinkedNode* newTail = new LinkedNode(val);
        LinkedNode* cur = _dummyHead;
        while(_size--) {
            cur = cur->next;
        }
            cur->next = newTail;
            _size++;
    }
    // 在第index个节点之前插入一个新节点，例如index为0，那么新插入的节点为链表的新头节点。
    // 如果index 等于链表的长度，则说明是新插入的节点为链表的尾结点
    // 如果index大于链表的长度，则返回空
    // 如果index小于0，则在头部插入节点
    void addIndex(int index, int val){
        if (index>_size) return;
        if(index<0) index = 0;
        LinkedNode* newIndex = new LinkedNode(val);
        LinkedNode* cur = _dummyHead;
        while(index--) {
            cur = cur->next;
        }

        newIndex->next = cur->next;
        cur->next = newIndex;
        _size++;
    }
    //删除第index个节点
    void deleteIndex(int index) {
        if(index>= _size|| index < 0) return;
        LinkedNode* cur = _dummyHead;
        while(index--) {
            cur = cur ->next;
        }
        LinkedNode* tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
        _size--;
    }
    private:
    int _size;
    LinkedNode* _dummyHead;
};

//翻转链表
//双指针法
class Solution10 {
    public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp;
        ListNode* cur = head;
        ListNode* pre = NULL;
        while(cur) {
            temp = cur->next;
            cur->next = pre ;
            //更新pre和cur指针
            pre = cur;
            cur = temp;
        }
        return pre;
    }
};
//使用递归算法实现上述双指针法翻转链表的思想
class Solution11 {
    public:
    ListNode* reverse(ListNode* cur, ListNode* pre) {
        if(cur==NULL) return pre;
        ListNode* temp = cur->next;
        cur->next = pre;
        reverse(temp, cur);
    }
    ListNode* reverseList(ListNode* head) {
        return reverse(head,NULL);
    }
};

//两两交换链表中的节点（使用虚拟表头法，可以有效简化过程）
class Solution12 {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode(0); // 设置一个虚拟头结点
        dummyHead->next = head; // 将虚拟头结点指向head，这样方面后面做删除操作
        ListNode* cur = dummyHead;
        while(cur->next != nullptr && cur->next->next != nullptr) {
            ListNode* tmp = cur->next; // 记录临时节点
            ListNode* tmp1 = cur->next->next->next; // 记录临时节点

            cur->next = cur->next->next;    // 步骤一
            cur->next->next = tmp;          // 步骤二
            cur->next->next->next = tmp1;   // 步骤三

            cur = cur->next->next; // cur移动两位，准备下一轮交换
        }
        return dummyHead->next;
    }
};
//链表相交 找出并返回两个单链表相交的起始节点，没有则返回null
class Solution13{
    public:
    ListNode* gerIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* curA = headA;
        ListNode* curB = headB;
        int lenA = 0, lenB = 0;
        while(curA!=NULL) {
            lenA++;
            curA = curA->next;
        }
        while(curB!=NULL) {
            lenB++;
            curB = curB->next;
        }
        curA = headA;
        curB = headB;
        if(lenB>lenA) {
            swap(lenA, lenB);
            swap(curA, curB);
        }
        int a = lenA - lenB;
        while(a--) {
            curA = curA->next;
        }
        while(curA!= NULL) {
            if(curA == curB){
                return curA;
            }
            curA = curA->next;
            curB = curB->next;
        }
        return NULL;
    }
};
//环形链表 给定一个链表，返回链表开始入环的第一个节点，没有则返回null(真的抽象我去)
class Solution14{
    public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast !=NULL && fast->next !=NULL) {
            slow = slow->next;
            fast = fast->next->next;
            //快慢指针相遇，此时head 和相遇点同时查找直至相遇
            if(fast==slow) {
                ListNode* index1 = fast;
                ListNode* index2 = head;
                while(index1 != index2) {
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index1;//返回环的入口
            }
        }
        return NULL;       
    }
};

/* Chapter 5 哈希表 */
//给定2个字符串s和t，编写一个函数判断t是否为s的字母异位词
class Solution15{
    public:
    bool isAnagram(string s, string t) {
        int hash[26];
        memset(hash, 0, sizeof(hash));
        for(int i= 0; i<s.size(); i++) {
            hash[s[i]-'a']++;
        }
        for(int j = 0;j< t.size(); j++) {
            hash[t[j]-'a']--;
        }
        for(int k = 0; k<26; k++) {
            if(hash[k]!= 0) {
                return false;
            }
        }
        return true;
    }
};

//给定两个数组，编写一个函数来计算他们的交集
//如果哈希值较少，且分散，跨度大，使用数组则会造成空间内的极大浪费
class Solution16{
    public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> result_set;
        unordered_set<int> nums_set(nums1.begin(), nums1.end());
        for(int num :nums2) {
            //发现nums2的元素在nums_set里出现过（没出现过则nums_set.find(nums2[i])=nums_set.end())
            if (nums_set.find(num)!= nums_set.end()) {
                result_set.insert(num);
            }
        }
        return vector<int>(result_set.begin(), result_set.end());
    }
};
//判断一个数n是否为快乐数
//[快乐数]每次将该数替换为它每个位置上数字的平方和，然后重复该过程，直到这个数能变为1，则是快乐数
class Solution17{
    public:
    int getSum(int n) {
        int sum = 0;
        while(n) {
            sum += (n % 10) * (n % 10);
            n /=10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> set;
        while(1) {
            int sum = getSum(n);
            if(sum==1) {
                return true;
            }
            if(set.find(sum)!= set.end()) {
                return false;
            }
            else {
                set.insert(sum);
            }
            n = sum ;
        }
    }
};

//两数之和
//给定一个整数组nums和一个目标值targrt，找出和为target的那两个整数，并返回数组下标
class Solution18{
    public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        for(int i = 0; i < nums.size(); i++) {
            unordered_map<int,int>::iterator iter = map.find(target-nums[i]);
            if(iter !=map.end()) {
                return vector<int>{i, iter->second};
            }
            map.insert(pair<int, int>(nums[i], i));
        }
        return {};
    }
};
//四数相加
//给定四个包含整数的数组列表ABCD，计算有多少个元组(i,k,k,l)，使得A[i] + B[j] + C[k] + D[l] = 0
class Solution19{
    public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        std::unordered_map<int, int> map;
        for(int a:A) {
            for(int b:B) {
                ++map[a+b];
            }
        }
        int count = 0;
        for(int c:C){
            for(int d:D) {
                if(map.find(0-(c+d))!= map.end()) {
                    count += map[c+d];
                }
            }
        }
        return count;
    }
};

//赎金信 判断给定第一个字符串能否由第二个字符串中的字符构成，且每个字符只能使用一次
class Solution20{
    public:
    bool canConstruct(string ransomnote, string magazine) {
        int map[26];
        memset(map, 0, sizeof(map));
        if(ransomnote.size() > magazine.size()) {
            return false;
        }
        for(int i = 0; i< magazine.length(); i++) {
            ++map[int(magazine[i]-'a')];
        }
        for(int j = 0; j< ransomnote.length(); j++) {
            --map[int(ransomnote[j]-'a')];
            if(map[int(ransomnote[j]-'a')] < 0) {
                return false;
            }
        }
        return true;
    }
};

//三数之和 判断给定数组中是否存在三元素abc使得a+b+c=0,并返回各三元组
class Solution21{
    public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());//排序
        for(int i = 0; i< nums.size(); i++) {
            if(nums[i] > 0) {
                break;
            }
            if(i > 0 &&nums[i] == nums[i-1]) {
                continue;
            }
            unordered_set<int> set;
            for(int j = i ;j < nums.size(); j++) {
                if(j > i+2
                &&nums[j] == nums[j-1]
                &&nums[j-1] == nums[j-2]) {
                    continue;
                }
                int c = 0 - (nums[i]+ nums[j]);
                if(set.find(c) != set.end()) {
                    result.push_back({nums[i], nums[j], c});
                    set.erase(c);
                } else {
                    set.insert(nums[j]);
                }
            }
        }
        return result;
    }
};

/* Chapter 5 哈希表 */
//反转字符串
class Solution22{
    public:
    void reverseString(vector<char>& s) {
        for(int i = 0, a = s.size()-1 ; i < s.size()/2; i++, a--) {
            if(i != a) {
                char temp = s[i];
                s[i] = s[a];
                s[a] = temp;
            }
        }
    }
};

//每计数至2k，反转前2k个字符，若剩下的大于k，则反转前k个，剩余不变。若剩下的小于k，则反转全部
class Solution23 {
public:
    void reverse(string& s, int start, int end) {
        for (int i = start, j = end; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
    }
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += (2 * k)) {
            // 1. 每隔 2k 个字符的前 k 个字符进行反转
            // 2. 剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符
            if (i + k <= s.size()) {
                reverse(s, i, i + k - 1);
                continue;
            }
            // 3. 剩余字符少于 k 个，则将剩余字符全部反转。
            reverse(s, i, s.size() - 1);
        }
        return s;
    }
};

/* Chapter 6 字符串 */
//实现把char s中每个空格替换为%20
//数组填充类问题，可以预先给数组扩容到填充后的大小，然后从后向前进行操作
class Solution24 {
    public:
    string replaceSpace(string s) {
        int count = 0;
        int soldSize = s.size();
        for(int i = 0; i<soldSize; i++) {
            if (s[i] = ' ');
            count++;
        }
        s.resize(s.size() + count*2);
        int sNewSize = s.size();
        for(int i = sNewSize - 1, j = soldSize - 1; j < i; i--, j--) {
            if(s[j] != ' ') {
                s[i] = s[j];
            }
            else {
                s[i] = 0;
                s[i-1] = 2;
                s[i-2] = '%';
                i -= 2;
            }
        }
        return s;
    }
};

//翻转字符串里的单词
class Solution25 {
    public:
    void reverse(string& s, int start, int end) {
        for(int i = start, j = end-1; i<j; i++, j--) {
            swap(s[i], s[j]);
        }
    }
    string reverseVerb(string s) {
        for(int i = 0, j = s.size()-1; i < j; i++, j--) {
                swap(s[i], s[j]);
        }
        int ini = 0;
        int count = 0;
        for(int k = 0 ;k < s.size(); k++) {
            if(s[k] != ' ') {
            count++;
             } else {
                reverse(s, ini, ini+count);
                ini = count + 1;
                count = 0;
             }
        }
        return s;
    }
};

//左旋转字符串，把字符串前面的k个字符转移到字符串的尾部
class Solution26 {
    public:
    string reverseLeftWords(string& s, int n) {
        reverse(s.begin(), s.begin() +n);
        reverse(s.begin(), s.end());
        reverse(s.begin(), s.end());
        return s;
    }
};

//KMP算法
//实现strStr()函数，在haystack字符串中找出needle字符串出现的第一个位置，不存在返回-1
class Solution27 {
    public:
    void getNext(int* next, const string& s) {
        int j = 0;
        next[0] = 0;
        for(int i = 1; i < s.size(); i++){
            while(j > 0&& s[i]!= s[j]) {
                j = next[j - 1];
            }
            if(s[i] == s[j]) {
                j++;
            }
            next[i] = j;
        }
    }
    int strStr(string haystack, string needle) {
        if(needle.size() == 0){
            return 0;
        }
        int next[needle.size()];
        getNext(next, needle);
        int j = 0;
        for (int i = 0; i< haystack.size(); i++) {
            while(j > 0&& haystack[i] != needle[j]) {
                j = next[j - 1];
            }
            if (haystack[i] == needle[j]) {
                j++;
            }
            if(j == needle.size()) {
                return(i - needle.size() + 1);
            }
        }
        return -1;
    }
};

//利用移动匹配和KMP寻找重复的子字符串
class Solution28{
    public:
    void getNext (int*next, const string& s) {
        next[0] = 0;
        int j = 0;
        for(int i = 1; i< s.size(); i++) {
            while(j > 0 && s[i] != s[j]) {
                j = next [j-1] ;
            }
            if(s[i] == s[j]) {
                j++;
            }
            next[i] = j;
        }
    }
    bool repeatedSubstringPattern (string s) {
        if (s.size() == 0) {
            return false;
        }
        int next[s.size()];
        getNext(next, s);
        int len = s.size();
        if (next[len - 1] != 0&& len% (len - (next[len - 1])) == 0) {
            return true;
        }
        return false;
    }
};

/* Chapter 7 栈和队列 */
//使用栈实现队列的基本操作 pop,push,peek,empty
class MyQueue {
    public:
    stack<int> stIn;
    stack<int> stOut;
    MyQueue() {

    }
    void push(int x) {
        stIn.push(x);
    }

    int pop() {
        if(stOut.empty()) {
        while(!stIn.empty()) {
            stOut.push(stIn.top());
            stIn.pop();
            }
        }
        int result = stOut.top();
        stOut.pop();
        return result;
    }

    int peek() {
        int res = this-> pop();
        stOut.push(res);
        return res;
    }

    bool empty() {
        return stIn.empty() && stOut.empty();
    }

};

int main() {
    cout<<"hello world!"<<endl;
    return 1;
}